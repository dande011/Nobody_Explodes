int buzzer = 11;
//delay in milliseconds;
int del = 500;
int tim = 0;

void setup() {
  pinMode(buzzer, OUTPUT);

}

void loop() {
  if (tim <= 15){
    analogWrite(buzzer, 150);
    delay(del);
    analogWrite(buzzer, 0);
    delay(del);
  }

}
