#include <Servo.h>
#include <Serial.h>

#define SERVO_PIN_1 2; // tbd
#define SERVO_PIN_2 3; // also tbd

Servo s1; 
Servo s2; 

void setup() {
  // put your setup code here, to run once:
  s1.attach(SERVO_PIN_1);
  s2.attach(SERVO_PIN_2);
  s1.writeMicroseconds(1500);
  s2.writeMicroseconds(1500);
  Serial.begin(9600);
}

int currPos = 1500; 

int angleConstrain(int currentAngle){
  if(currentAngle > 2000){
    return 2000;
  }else if(currentAngle < 1000){
    return 1000;
  }
  return currentAngle;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String input = Serial.readString();
    switch(input){
      case "LEFT":
        currPos -= 10;
        s1.writeMicroseconds(angleConstrain(currPos));
        break;
      case "RIGHT":
        currPos += 10;
        s1.writeMicroSeconds(angleConstrain(currPos));
        break;
      case "CENTER":
        break;
      
      default: 
        break;
    }

  }
}
