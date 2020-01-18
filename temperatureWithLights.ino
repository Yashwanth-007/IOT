#include<LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
#define relay A0
#define LED 8

const int sensor=A5; // Assigning analog pin A1 to variable 'sensor'
float tempc;  //variable to store temperature in degree Celsius
float tempf;  //variable to store temperature in Fahreinheit
float vout;  //temporary variable to hold sensor

void setup()
{
pinMode(sensor,INPUT); // Configuring pin A1 as input
Serial.begin(9600);
lcd.begin(16,2);
delay(500);
pinMode(relay, OUTPUT);
pinMode(LED, OUTPUT);
digitalWrite(LED,HIGH);
}
void loop()
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempc=vout; // Storing value in Degree Celsius
tempf=(vout*1.8)+32; // Converting to Fahrenheit
Serial.print("in DegreeC=");
Serial.print("\t");
Serial.print(tempc);
Serial.println();
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

