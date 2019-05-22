 #include <SoftwareSerial.h>
void setup() {
  // put your setup code here, to run once:
pinMode(OUTPUT,13);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(13) !=LOW)
  Serial.print("1\n");
  else Serial.print("0\n");
}
