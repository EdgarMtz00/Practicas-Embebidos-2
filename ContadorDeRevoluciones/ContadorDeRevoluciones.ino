long f;
int pinF = 2;
float error = .1;
int frecuencias[9] = {300, 1400, 1700, 2000, 2500, 3000, 3300, 3600, 4000};
int leds[9] = {4, 5, 6, 7, 8, 9, 10, 11, 12};

void setup(){
	Serial.begin(9600);
	f = 0;
	analogWrite(3, 255);
  for(int i = 0; i < 9; i++){
    pinMode(leds[i], OUTPUT);
  }
  pinMode(pinF, INPUT);
  pinMode(3, OUTPUT);
}

void loop(){
	f = getFrequency(pinF);
	for(int i = 0; i < 9; i++){
		if(f > frecuencias[i]){
			digitalWrite(leds[i], HIGH);
			Serial.print("HIGH");
		}else{
			digitalWrite(leds[i], LOW);
			Serial.print("LOW");
		}
	}
}

long getFrequency(int pin) {
  #define SAMPLES 1000
  long freq = 0;
  for(unsigned int j = 0; j < 1000; j++) freq+= 1000000/pulseIn(pin, HIGH, 5000);
  return freq / 1000;
}
