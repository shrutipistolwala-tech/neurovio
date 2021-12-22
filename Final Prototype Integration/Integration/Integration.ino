 // Shout out and Thanks a ton to Zoomkat for the first code for the momentary switch. I have learned a ton!
//Thanks Lar3ry for showing me things to learn to better my skills, I have learned a ton!
//zoomkat servo button toggle test 4-28-2012  combined from code suggested my reallifeonhold source unknown

#include <Servo.h>
#include<Wire.h>//I2C library

const int button_pin = 2 ;    
const int motorPin = 3; //The issue I see is this takes voltage from the nano and NOT completing my circuit which would be to run ground from digital 
              //side GRN to pin 7, in short this just uses the nano to send 5V to pin D7 what code is needed?


int led = 13;                                 // use LED aka pin 13 for visual confirmation as to which state the Arduino was in.

Servo s1;
int pos = 0;            // variable to store the servo start position deg
int button_value = 180;         //variable to store switch position e.g. 180 turn 

void setup()
{
  s1.attach(9);           // attaches the servo's control wire on pin 5 White wire
  pinMode(led, OUTPUT);  
  pinMode(motorPin, OUTPUT );  
 
}
                                            // code for z wave switch recognition 
void loop()
{
  button_value = digitalRead(button_pin);
  if (button_value==HIGH){        //do this
        digitalWrite(motorPin, HIGH);
    delay(1000);
    s1.write(45); 
    //Value to open servo to on/off of switch
    digitalWrite(led, HIGH);   
     delay(3000);// turn the LED on LED corresponding to switch
         digitalWrite(motorPin, LOW);
    delay(1000);
    }
  else {            //or else do this
    s1.write(200);         //Value to open servo to on/off of switch
   digitalWrite(led, LOW); 
   delay(1500);// turn the LED of corresponding to switch
    }
}
