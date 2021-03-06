#include <stdio.h> 
#include <string.h>

const int MOTOR_A = 23;
const int MOTOR_B = 19;
const int MOTOR_C = 18;
const int MOTOR_D = 26;

const int CHANNEL_A = 0;
const int CHANNEL_B = 1;
const int CHANNEL_C = 2;
const int CHANNEL_D = 3;

const int MOTOR_FREQ = 5000;
const int MOTOR_RESOLUTION = 10;

void setup(){
  ledcAttachPin(MOTOR_A, CHANNEL_A);
  ledcAttachPin(MOTOR_B, CHANNEL_B);
  ledcAttachPin(MOTOR_C, CHANNEL_C);
  ledcAttachPin(MOTOR_D, CHANNEL_D);

  ledcSetup(CHANNEL_A, MOTOR_FREQ, MOTOR_RESOLUTION);
  ledcSetup(CHANNEL_B, MOTOR_FREQ, MOTOR_RESOLUTION);
  ledcSetup(CHANNEL_C, MOTOR_FREQ, MOTOR_RESOLUTION);
  ledcSetup(CHANNEL_D, MOTOR_FREQ, MOTOR_RESOLUTION);
  ledcWrite(CHANNEL_A, 0); 
  ledcWrite(CHANNEL_B, 0);
  ledcWrite(CHANNEL_C, 0);
  ledcWrite(CHANNEL_D, 0);
  Serial.begin(115200);
}

void loop(){
  if(Serial.available()>0){
    //char userInput = Serial.readString().toInt();
    //Serial.print(userInput + 1);

    char userInput = Serial.read();
    Serial.print(userInput);

    char t = 'takeoff';
    char l = 'land';
    int i = 0;
 
    if(userInput == l){
     while (i != 0){
        i--;
        int throttle = i*100;
        ledcWrite(CHANNEL_A, throttle);
        ledcWrite(CHANNEL_B, throttle);
        ledcWrite(CHANNEL_C, throttle);
        ledcWrite(CHANNEL_D, throttle);
     }
     int throttle = 0*100;
     ledcWrite(CHANNEL_A, throttle);
     ledcWrite(CHANNEL_B, throttle);
     ledcWrite(CHANNEL_C, throttle);
     ledcWrite(CHANNEL_D, throttle);
    }

    if(userInput == t)
    {
     int throttle = i*100;
     ledcWrite(CHANNEL_A, throttle);
     ledcWrite(CHANNEL_B, throttle);
     ledcWrite(CHANNEL_C, throttle);
     ledcWrite(CHANNEL_D, throttle);
    }
  }
}
