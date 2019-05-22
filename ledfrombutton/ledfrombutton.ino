int ledPin_1 = 1;
int ledPin_2 = 2;
int ledPin_3 = 3;
int ledPin_4 = 4;

int i;
int num = 0;

int Pin_0 = 5;
int Pin_1 = 6;
int Pin_2 = 7;
int Pin_3 = 8;
int Pin_4 = 9;
int Pin_5 = 10;
int Pin_6 = 11;
int Pin_7 = 12;
int Pin_8 = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin_1,INPUT);
  pinMode(ledPin_2,INPUT);
  pinMode(ledPin_3,INPUT);
  pinMode(ledPin_4,INPUT);
  pinMode(Pin_0,OUTPUT);
  pinMode(Pin_1,OUTPUT);
  pinMode(Pin_2,OUTPUT);
  pinMode(Pin_3,OUTPUT);
  pinMode(Pin_4,OUTPUT);
  pinMode(Pin_5,OUTPUT);
  pinMode(Pin_6,OUTPUT);
  pinMode(Pin_7,OUTPUT);
  pinMode(Pin_8,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int light_A;
  int light_B;
  int light_C;
  int light_D;
  
  light_A = digitalRead(ledPin_1);
  light_B = digitalRead(ledPin_2);
  light_C = digitalRead(ledPin_3);
  light_D = digitalRead(ledPin_4);
  int num_press[9] = {0, 0, 0, 0, 0};

  if(light_A == HIGH){
    num_press[0]++;
    num_press[1]++;
    num_press[3]++;
    num_press[5]++;
    num_press[7]++;
    num_press[8]++;
  }
  if(light_B == HIGH){
    num_press[0]++;
    num_press[2]++;
    num_press[3]++;
    num_press[4]++;
    num_press[6]++;
    num_press[7]++;
  }
  if(light_C == HIGH){
    num_press[0]++;
    num_press[2]++;
    num_press[4]++;
    num_press[5]++;
    num_press[7]++;
  }
  if(light_D == HIGH){
    num_press[0]++;
    num_press[1]++;
    num_press[3]++;
    num_press[4]++;
    num_press[6]++;
    num_press[8]++;
  }

  Serial.print("num = ");
  Serial.println(num);
  num++;
  for( i = 0 ; i < 10 ; i++){
    Serial.print("i = ");
    Serial.println(i);
    Serial.println(num_press[i]);
  }

  if(num_press[0] % 2 == 0){ 
    digitalWrite(Pin_0,HIGH);
  }
  else{
    digitalWrite(Pin_0,LOW);
  }
  if(num_press[1] % 2 == 0){
    digitalWrite(Pin_1,HIGH);
  }
  else{
    digitalWrite(Pin_1,LOW);
  }
  if(num_press[2] % 2 == 0){ 
    digitalWrite(Pin_2,HIGH);
  }
  else{
    digitalWrite(Pin_2,LOW);
  }
  if(num_press[3] % 2 == 0){ 
    digitalWrite(Pin_3,HIGH);
  }
  else{
    digitalWrite(Pin_3,LOW);
  }
  if(num_press[4] % 2 == 0){ 
    digitalWrite(Pin_4,HIGH);
  }
  else{
    digitalWrite(Pin_4,LOW);
  }
  if(num_press[5] % 2 == 0){ 
    digitalWrite(Pin_5,HIGH);
  }
  else{
    digitalWrite(Pin_5,LOW);
  }
  if(num_press[6] % 2 == 0){ 
    digitalWrite(Pin_6,HIGH);
  }
  else{
    digitalWrite(Pin_6,LOW);
  }
  if(num_press[7] % 2 == 0){ 
    digitalWrite(Pin_7,HIGH);
  }
  else{
    digitalWrite(Pin_7,LOW);
  }
  if(num_press[8] % 2 == 0){ 
    digitalWrite(Pin_8,HIGH);
  }
  else{
    digitalWrite(Pin_8,LOW);
  }

//  delay(1000);

}
