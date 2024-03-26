int green = 7, yellow = 8, red = 9,white = 3;
int butt[] = {10, 11};
int poten = A1,photo=A0;
int redState = 0;
unsigned long previousTime = 0;
int yellowInt = 1000;

void setup() {
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);
  for (int i = 0; i < 2; i++) {
    pinMode(butt[i], INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  int potenval = analogRead(poten);
  int photoval = analogRead(photo);
  int light = map(photoval,0,1024,0,100);
  unsigned long currentTime = millis();
  unsigned long interval = potenval * 10;
  Serial.println(light);
  analogWrite(white, 35-light);
  if(light >= 10){
    if (digitalRead(butt[0])){ //override green
      grOn();
      previousTime=currentTime;
    }
    else if (digitalRead(butt[1])){ //override red
      if(digitalRead(green)){
        previousTime=yellOn(currentTime);
      }
      redOn();
      previousTime = currentTime;
    }
    else{
      if(currentTime - previousTime >= interval){ //normal
        if(digitalRead(green)){
          previousTime = yellOn(currentTime);
          goto red;
        }
        else if(digitalRead(yellow)){
          red:
          redOn();
          previousTime = currentTime;
        }
        else{
          grOn();
          previousTime = currentTime;
        }
      }
    }
  }
  else{
    if(currentTime-previousTime>= 1000){
      digitalWrite(green, LOW);
      digitalWrite(yellow, LOW);
      redState = !redState;
      digitalWrite(red, redState);
      previousTime=currentTime;
    }
  }
}

void grOn(){
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
}
int yellOn(int current){
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
  return current+1000;
}
void redOn(){
  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);
}
