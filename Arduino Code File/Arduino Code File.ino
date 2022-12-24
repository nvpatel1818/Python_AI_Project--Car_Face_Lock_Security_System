#include <Servo.h>

Servo starter_motor;    // object and variable declarations
Char result;
int i;


void setup() 
{
  Serial.begin(9600);      // initialize the serial monitor with 9600 baudrate.
  starter_motor.attach(10);      // let me supposed, servo motor is connected to digital(PWM) pin number 10 to the Arduino microcontroller.
}

void loop() 
{

  if (Serial.available())   // if there is any signal present...
  {
    result=Serial.read();   // reading the signal coming with the help of communication to Python
    if (result == 1)         // if received signal to serial monitor is same as the signal sent out from Python code then its Nishant/ Access Accepted.......
    { 
      for (i=0; i<=180; i+=1)
      {
        starter_motor.write(i);  // start the starter motor to start the vehicle/ car... (here I have considered the servo motor as a starter motor for whole process understanding)
      }
    }
  }

}
