class BTControl{
    BTControl(){
        Serial.begin(9600);
        Movement moves = new Movement();   
    }

    void run(){
        while(true){
            if(Serial.available() > 0){
                String command = Serial.readString();
                moves.move(command);
            }
        }
    }
}