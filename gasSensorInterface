int analogSensorValue135;
int analogSensorValue4;
const int buzzer = 9;
const int fan = 11;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);
 
}
void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(analogSensorValue135, DEC);
  Serial.println(analogSensorValue4, DEC);
  takeAnalogReading();
  airAnalogSensorCheck();
}

void takeAnalogReading()
{
  analogSensorValue135 = analogRead(0);
  analogSensorValue4 = analogRead(1);
}
void airAnalogSensorCheck()
{
  if(analogSensorValue135 >=100 || analogSensorValue4 >=200)
  {
      soundAlarm();
      analogWrite(fan, 200);
  }
  else
      {
          delay(1000);                               
          analogWrite(fan,0);
    }
 
}

void soundAlarm()
{
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9,LOW);
}

