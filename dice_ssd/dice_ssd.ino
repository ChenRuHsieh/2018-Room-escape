 #include <SoftwareSerial.h>
#include <Wire.h>
#include<Servo.h>

#define MAX_STRING 128
// The maximum received command length from an Android system over the bluetooth

/*
 * Connections Between HC-06 and Arduino ---
 * HC-06    Arduino
 * TX       RX/Pin10
 * RX       TX/Pin11
 */

SoftwareSerial BTSerial(10,11);     // HC06 <-> Arduino RX/TX

byte cmd[MAX_STRING];               // var: Received command from Android
int cmd_len = 0;                    // var: Received command length record
int mode = 0;                       // var: Mode for motor action
int button = 5;
Servo myservo;

void setup(){
    Serial.begin(9600);             // Init: Arduino <-> Computer Baud Rate
    BTSerial.begin(38400);           // Init: HC-06 <-> Arduino Baud Rate

    pinMode(button,INPUT);
    myservo.attach(9);
}

void loop(){
    char str[MAX_STRING];           // var: String to be recieved
    int cmd_tmp_size;               // var: Command size waiting to be read.
    int i;                          // var: Reading loop counter
    int tick = 0;                   // var: 
    int pressButton = digitalRead(button);


    
    while ( tick < MAX_STRING ){
        cmd_tmp_size = BTSerial.available();        // Get the size of commands waiting to be read
        if ( cmd_tmp_size > 0 ){                    // If there are commands waiting
            for ( i=0; i < cmd_tmp_size; i++ ){     // For each command character waiting
                cmd[(cmd_len++)%MAX_STRING] = char(BTSerial.read());
                                                    // Read command character and save it into cmd
            }
        }
        else {
            tick++;
        }
    }

    if (cmd_len){                   // If cmd have content
        sprintf(str,"%s",cmd);      // Convert cmd to string, and print formatted string to str
        //Serial.println(str[0]);     // Print str by Serial
        cmd[0] = '\0';              // Clean cmd
        Serial.print(str[0]);
        Serial.print("\n");
        if(str[0]=='u')  {           // Switch modes
          mode = 1;
          delay(30);}
        else{
          mode = 0;
          delay(30);}
    }
    cmd_len = 0;                    // Reset cmd's length record
    Serial.print(mode);
    Serial.print("M\n");
    Serial.print(pressButton);
    Serial.print("\n");
    
    if(mode ==1 &&pressButton == 1){                  // Switch mode actions
      myservo.write(90);
      delay(1000);
    }
    else{
      myservo.write(0);
      delay(1000);
    }
}
