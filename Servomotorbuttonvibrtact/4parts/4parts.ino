#include <Servo.h>
#include<Wire.h>//I2C library


const int button_pin = 2 ; 
const int motorPin = 3;
Servo m;
int button_value = 0; 

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(motorPin, OUTPUT );  
  m.attach(7);
  Serial.begin(9600);
}

void loop()
{
  float x=analogRead(A0);
  float y= ((x-159)/352);
  
  int angle=(y*200);

   button_value = digitalRead(button_pin);

   if (button_value==HIGH){ 
    digitalWrite(motorPin, HIGH); 
    analogRead(A0);
     delay(1000); 
   }
    else if(analogRead(A0==HIGH)){
      digitalWrite(motorPin, LOW);
   m.write(angle);
  delay(1000);
  Serial.println(angle);
  delay(1000); 
   }
  else { 
    digitalWrite(motorPin, LOW);
    m.write(0);
    Serial.println(angle);
    delay(1000); 
  }
   
}
