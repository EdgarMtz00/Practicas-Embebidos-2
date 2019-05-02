long f;
int pinF = 2;
float error = .1;
int frecuencias[9] = {500, 800, 1300, 2600, 2800, 3000, 3300, 3600, 4000};
int leds[9] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup(){
	Serial.begin(9600);
  pinMode(pinF, INPUT);
  pinMode(3, OUTPUT);
	f = 0;
  for(int i = 0; i < 9; i++){
    pinMode(leds[i], OUTPUT);
  }
  analogWrite(3, 125);  
}

void loop(){
	f = getFrequency(pinF);
  Serial.println(f);
	for(int i = 0; i < 9; i++){
		if(f > frecuencias[i]){
			digitalWrite(leds[i], HIGH);
			Serial.println("HIGH");
		}else{
			digitalWrite(leds[i], LOW);
			Serial.println("LOW");
		}
	}
}

long getFrequency(int pin) {
  long freq = 0;
  for(unsigned int j = 0; j < 1000; j++) freq+= 500000/pulseIn(pin, HIGH, 1000);
  return freq / 1000;
}
