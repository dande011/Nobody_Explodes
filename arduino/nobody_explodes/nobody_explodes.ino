// all this file does is beep a buzzer

int buzzer = 11;
//delay in milliseconds;
int del = 500;
int tim = 1000;

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  analogWrite(buzzer, 150);
  delay(del);
  if(del > 0){
    del-=25;
    analogWrite(buzzer, 0);
  }
  else
    del=0;
  delay(del);

}
