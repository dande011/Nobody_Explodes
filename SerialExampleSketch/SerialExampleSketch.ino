char incomingByte = 0;
char incomingString[26] = {0};
String str;
String buff;
int tim;
int start;
int strikeTotal;
int strikeCurr;
bool rndEnd;
bool boom;

int i;
int j;

//BUZUZER
int buzzer = 11;

int relay = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(relay,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  i = 0;
  while(Serial.available() > 0){
    if(i < 25){
       incomingByte = Serial.read();
       incomingString[i] = incomingByte;
       i++;
       }
     else{
      Serial.read();
     }
  }
  str = String(incomingString);
  //Serial.print(str);
  
  buff = str.substring(2,5);
  tim = buff.toInt();

  buff = str.substring(8,9);
  start = buff.toInt();

  buff = str.substring(12,13);
  rndEnd = buff.toInt();

  buff = str.substring(16,17);
  strikeCurr = buff.toInt();

  buff = str.substring(20,21);
  strikeTotal = buff.toInt();

  buff = str.substring(24,25);
  boom = buff.toInt();
  

  //Serial.print("\n\nTime:");
  //Serial.print(tim);
  //Serial.print("\nStart:");
  //Serial.print(start);
  //Serial.print("\nRound End:");
  //Serial.print(rndEnd);
 // Serial.print("\nCurrent Strike:");
 // Serial.print(strikeCurr);
 // Serial.print("\nTotal Strikes:");
  //Serial.print(strikeTotal);
  Serial.print("\nIs Explode?:");
  Serial.print(boom);
 // Serial.print(buff);

  delay(250);

    if(strikeCurr > 0){
     if (j <= 2){
     tone(buzzer, 150 + strikeCurr*strikeCurr*10);
     j += (2 + strikeCurr - 1)/2;
     }
     else{
     noTone(buzzer);
     j += (2 + strikeCurr - 1)/2;
     }
     if (j > 4)
      j = 0;
     }
     else{
      noTone(buzzer);
     }
  
  
  if(boom){
    digitalWrite(relay,0);
  }
  else{
    digitalWrite(relay,1); 
  }
}
