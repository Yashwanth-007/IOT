#include<LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);

#define relay_led A4

#define relay_fan 8

#define LED 7
 

const int buzzer = 9; 

int analogSensorValue135;

int analogSensorValue4;

 

const int sensor_lm = A5; // Assigning analog pin A1 to variable 'sensor'

float tempc;  //variable to store temperature in degree Celsius

//float tempf;  //variable to store temperature in Fahreinheit

float vout;  //temporary variable to hold sensor

 

void setup()

{

pinMode(sensor_lm,INPUT); // Configuring pin A1 as input

Serial.begin(9600);

lcd.begin(16,2);

delay(500);

pinMode(relay_led, OUTPUT);

pinMode(LED, OUTPUT);

digitalWrite(LED,HIGH);

 

pinMode(A0,INPUT);

  pinMode(A1,INPUT);

  pinMode(9,OUTPUT);

  pinMode(relay_fan,OUTPUT);

 

 

}

void loop()

{

vout=analogRead(sensor_lm);

vout=(vout*500)/1023;

tempc=vout; // Storing value in Degree Celsius

//tempf=(vout*1.8)+32; // Converting to Fahrenheit

Serial.print("in DegreeC=");

Serial.print("\t");

Serial.print(tempc);

Serial.println("*****************************");
Serial.println(analogSensorValue135,DEC);
Serial.println(analogSensorValue4,DEC);
Serial.println("*****************************");

lcd.setCursor(0,0);

lcd.print("DegreeC= ");

lcd.print(tempc);

if(tempc>34.02){

  digitalWrite(relay_led, HIGH);

}

else{

   digitalWrite(relay_led, LOW);

   

  }

if(tempc<40.02){

    digitalWrite(relay_fan,HIGH);

  }else{

      digitalWrite(relay_fan,LOW);

    }

  takeAnalogReading();
  airAnalogSensorCheck();


delay(500); //Delay of 1 second for ease of viewing

}

void takeAnalogReading()
{
  analogSensorValue135 = analogRead(0);
  analogSensorValue4 = analogRead(1);
}


void airAnalogSensorCheck()
{
  if(analogSensorValue135 >=250 || analogSensorValue4 >=500)
  {
    soundAlarm();
    digitalWrite(relay_fan,LOW);
    
  }
  else
    {
        delay(500);
  }
 
}



void soundAlarm()
{
  digitalWrite(9, HIGH);
  delay(2000);
  digitalWrite(9,LOW);
  digitalWrite(relay_fan,LOW);
}


