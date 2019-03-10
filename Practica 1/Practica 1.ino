#define button 4
#define IN1  12
#define IN2  11
#define IN3  10
#define IN4  9

int Paso [ 12 ][ 4 ] =
{  {1, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 1},
  {1, 0, 0, 1},
  {1, 0, 0, 0},
  {1, 1, 0, 0},
  {0, 1, 0, 0},
  {0, 1, 1, 0},
  {0, 0, 1, 0},
  {0, 0, 1, 1},
  {0, 0, 0, 1},
  {1, 0, 0, 1}
};

bool isPress = HIGH;
bool cambio = false;
int Steps = 0;
int retardo = 0;    

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode (button, INPUT);
}

void step(int retardo){
  digitalWrite( IN1, Paso[Steps][ 0] );
  digitalWrite( IN2, Paso[Steps][ 1] );
  digitalWrite( IN3, Paso[Steps][ 2] );
  digitalWrite( IN4, Paso[Steps][ 3] );
  Steps = (Steps < 11)? Steps+1 : 0;
  delay (retardo);
}
   
void detener(){
  retardo=2;
  while (retardo<=100){
    step(retardo);
    retardo = retardo + 1;
  }
}

void acelerar(){
  retardo=100;
  while (retardo>=2){
    step(retardo);
    retardo = retardo - 1;
  } 
  
  while (!isPress){
    isPress = digitalRead (button);
    retardo =2;
    step(retardo);
  }
}

void loop() {
  isPress = digitalRead (button);
  if (isPress){
    isPress = false;
    cambio = !cambio;
    if(cambio){
      acelerar();
    }else{
      detener();
    }
  }
}