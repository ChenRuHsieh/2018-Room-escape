#include <Servo.h> 
int servoPin = 9; 
Servo Servo1; 

void setup() { 
   Servo1.attach(servoPin); 
}
void loop(){ 
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(10000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(10000); 
   
}
