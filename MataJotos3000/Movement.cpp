class Movement{
    int pins[4] = {2, 3, 4, 5, 6, 7, 8, 9};
    int speed;
    int speedPin = 6;

    public void move(Directions dir){
        switch (dir){
            case Front:
                for(int i = 0; i < pins.length(); i+=2){
                    digitalWrite(pins[i], HIGH);
                    digitalWrite(pins[i+1], LOW);
                }
                break;
            case Back:
                for(int i = 0; i < pins.length(); i+=2){
                    digitalWrite(pins[i], LOW);
                    digitalWrite(pins[i+1], HIGH);
                }
                break;
            case Left:
                digitalWrite(pins[0], HIGH);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case Right:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], HIGH);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case FullLeft
                digitalWrite(pins[0], HIGH);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], HIGH);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], LOW);
                break;
            case FullRight:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], HIGH);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], HIGH);
                digitalWrite(pins[7], LOW);
                break;
            case BackRight:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], LOW);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], HIGH);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], LOW);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], HIGH);
                break;
            case BackLeft:
                digitalWrite(pins[0], LOW);
                digitalWrite(pins[1], HIGH);
                digitalWrite(pins[2], LOW);
                digitalWrite(pins[3], LOW);
                digitalWrite(pins[4], LOW);
                digitalWrite(pins[5], HIGH);
                digitalWrite(pins[6], LOW);
                digitalWrite(pins[7], LOW);
                break;
            default:
                break;
        }
    }

    void setSpeed(int speed){
        speed = speed % 255;
        analogWrite(speedPin, speed);
    }

    Movement(){
        for(int i = 0; i < pins.length; i++){
            pinMode(pins[i], OUTPUT);
            digitalWrite(pins[i], HIGH);
        }
        speed = 100;
        analogWrite(speedPin, speed);
        move(BackLeft);
        delay(1000);
        move(Left);
        delay(1000);
        move(BackRight);
        delay(1000);
        move(Right);
        delay(3000);
    }
}