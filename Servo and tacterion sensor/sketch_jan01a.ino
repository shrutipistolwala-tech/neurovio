#include <Servo.h>

Servo m;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT);
  m.attach(7);
  Serial.begin(9600);
}

void loop()
{
  float x=analogRead(A0);
  float y= ((x-159)/352);
  
  int angle=(y*180);
  Serial.println(angle);
  m.write(angle);
  delay(1000); 
  
}
