// The author of the code is Shruti Pistolwala and if you are using the code please acknowledge. 
// The code cannot be used for commercialization. If it is being used the author needs to be updated in advance. 
// We would further like to acknowledge Arduino Forum and stackoverflow.
// This code is use for building a soft Exoskeleton for paralysis patients.


// Library for Servo Motor
#include <Servo.h>
//I2C library
#include<Wire.h>

// Declaration of all the pins
const int button_pin = 2 ; // Button Pin
const int motorPin = 3; // Vibrational Motor Pin
Servo m; // Servo  Motor Pin
int button_value = 0; //Initialization of button value

//Pin modes and serial initialization
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(A0,INPUT); // Tacterion Sensor at analog Pin
  pinMode(motorPin, OUTPUT );  
  m.attach(7);
  Serial.begin(9600);
}

//Logic for the working
//When the  button is pressed vbartional motors start and then the exercise starts.
//When the flex sensor moves the servo motor moves and helps patients with the exercise.
void loop()
{
  //Calculation for the measurement of the flex sensor
  float x=analogRead(A0);
  float y= ((x-159)/352);
  int angle=(y*200);
  button_value = digitalRead(button_pin);

//Logic for the working
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
