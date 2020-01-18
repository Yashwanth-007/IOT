#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
#define relay A4
#define LED 8

int analogSensorValue135;
int analogSensorValue4;
const int buzzer = 9;
const int fan = 11;

const int sensor_lm=A5; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahrenheit
float vout;  //temporary variable to hold sensor

void setup()
{
pinMode(sensor_lm,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
lcd.begin(16,2);
delay(500);
pinMode(relay, OUTPUT);
pinMode(LED, OUTPUT);
digitalWrite(LED,HIGH);

pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(9,OUTPUT);
  pinMode(11,OUTPUT);


}
void loop()
{
vout=analogRead(sensor_lm);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println("***************************************");

Serial.println(analogSensorValue135, DEC);
  Serial.println(analogSensorValue4, DEC);
  takeAnalogReading();
  airAnalogSensorCheck();
Serial.println("***************************************");


lcd.setCursor(0,0);
lcd.print("DegreeC= ");
lcd.print(tempc);
if(tempc>34.02){
    digitalWrite(relay, HIGH); 
}
else{
   digitalWrite(relay, LOW); 
      
  }
delay(1000); //Delay of 1 second for ease of viewing
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

