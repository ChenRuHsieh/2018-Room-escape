#include "Wire.h"
#include "I2Cdev.h"
#include "ADXL345.h"
#include <SoftwareSerial.h>

ADXL345 acc;

int16_t ax, ay, az;

#define OUTPUT_READABLE_ACCELGYRO
#define LED_PIN 13
bool blinkState = false;

SoftwareSerial BTSerial(10, 11);

void forward() {
  Serial.print("for");
  Serial.print("\t");
  BTSerial.write('u');
}
void backward() {
  Serial.print("back");
  Serial.print("\t");
  BTSerial.write('d');
}
void turnleft() {
  Serial.print("right");
  Serial.print("\t");
  BTSerial.write('r');
}
void turnright() {
  Serial.print("left");
  Serial.print("\t");
  BTSerial.write('l');
}
void stay() {
  Serial.print("no_y");
  Serial.print("\t");
  BTSerial.write('0');
}

void setup() {
    Wire.begin();
    BTSerial.begin(38400);

    Serial.begin(9600);
    Serial.println("Initializing I2C devices...");
    acc.initialize();

    Serial.println("Testing device connections...");
    Serial.println(acc.testConnection() ? "ADXL345 connection successful" : "ADXL345 connection failed");
    pinMode(LED_PIN, OUTPUT);    
}

void loop() {
    // read raw accel measurements from device
    acc.getAcceleration(&ax, &ay, &az);

    // display tab-separated accel x/y/z values
    Serial.print("accel:\t");
    Serial.print(ax); Serial.print("\t");
    Serial.print(ay); Serial.print("\t");
    Serial.println(az);

//*********************以下程式用自己的力量完成！*********************//
//判斷ax, ay, az的大小來控制前後左右！
//可用的function有 forward(), backward(),turnleft(), turnright(), stay()
    if () {
      
    }
    else if () {
      
    }
    else {
      
    }

//******************************END****************************//

    Serial.println("\n");

    #ifdef OUTPUT_BINARY_ACCELGYRO
        Serial.write((uint8_t)(ax >> 8)); Serial.write((uint8_t)(ax & 0xFF));
        Serial.write((uint8_t)(ay >> 8)); Serial.write((uint8_t)(ay & 0xFF));
        Serial.write((uint8_t)(az >> 8)); Serial.write((uint8_t)(az & 0xFF));
    #endif

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);
}
