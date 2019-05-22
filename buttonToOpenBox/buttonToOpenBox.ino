#include<Servo.h>

int button_A = 1;
int button_B = 2;
int button_C = 3;
int button_D = 4;
int button_E = 5;
int button_F = 6;
int button_G = 7;
int button_H = 8;
int button_I = 9;
int num = 0;
int pB_A;
int pB_B;
int pB_C;
int pB_D;
int pB_E;
int pB_F;
int pB_G;
int pB_H;
int pB_I;

//int LED = 10;

int servoPin = 10; 
Servo Servo1; 

void setup() {
  // put your setup code here, to run once:
  pinMode(button_A,INPUT);
  pinMode(button_B,INPUT);
  pinMode(button_C,INPUT);
  pinMode(button_D,INPUT);
  pinMode(button_E,INPUT);
  pinMode(button_F,INPUT);
  pinMode(button_G,INPUT);
  pinMode(button_H,INPUT);
  pinMode(button_I,INPUT);
  Servo1.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  pB_A = digitalRead(button_A);
  pB_B = digitalRead(button_B);
  pB_C = digitalRead(button_C);
  pB_D = digitalRead(button_D);
  pB_E = digitalRead(button_E);
  pB_F = digitalRead(button_F);
  pB_G = digitalRead(button_G);
  pB_H = digitalRead(button_H);
  pB_I = digitalRead(button_I);

  Serial.print(num);
  Serial.print("\n");
  num++;
  Serial.print("A");
  Serial.print(pB_A);
  Serial.print("\n");
  
  Serial.print("B");
  Serial.print(pB_B);
  Serial.print("\n");
  
  Serial.print("C");
  Serial.print(pB_C);
  Serial.print("\n");
  
  Serial.print("D");
  Serial.print(pB_D);
  Serial.print("\n");
  
  Serial.print("E");
  Serial.print(pB_E);
  Serial.print("\n");
  
  Serial.print("F");
  Serial.print(pB_F);
  Serial.print("\n");
  
  Serial.print("G");
  Serial.print(pB_G);
  Serial.print("\n");
  
  Serial.print("H");
  Serial.print(pB_H);
  Serial.print("\n");
  
  Serial.print("I");
  Serial.print(pB_I);
  Serial.print("\n");
  
  Serial.print("\n");
  //delay(1000);
 
  if(pB_A == 1 || pB_B == 1 || pB_C == 1 || pB_I == 1){
    Servo1.write(90);
  }
  else if(pB_D == 1 && pB_F == 1 && pB_H == 1 && pB_G == 1 && pB_E == 1){
    Servo1.write(0); 
  }
  else{
    Servo1.write(90);
  }
  delay(1000);
}
