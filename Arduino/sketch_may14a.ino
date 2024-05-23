#include <Servo.h>

#define SERVO_PIN_1 25; // tbd
#define SERVO_PIN_2 26; // also tbd

Servo s1; 
Servo s2; 

enum state_enum{SEARCH, LEFT, RIGHT, CENTER};
int state = SEARCH;

void setup() {
  // put your setup code here, to run once:
  s1.attach(25);
  s2.attach(26);
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
    Serial.println("RECEIVED TARGET");
    String input = Serial.readString();

    if(input.equals("LEFT")){
      state = LEFT; 
    }else if(input.equals("RIGHT")){
      state = RIGHT;
    }else if(input.equals("CENTER")){
      state = CENTER;
    }

    switch(state){
      case LEFT:
        currPos -= 10;
        s1.writeMicroseconds(angleConstrain(currPos));
        Serial.println("AIMING LEFT");
        break;
      case RIGHT:
        currPos += 10;
        s1.writeMicroseconds(angleConstrain(currPos));
        Serial.println("AIMING RIGHT");
        break;
      case CENTER:
        Serial.println("TARGET CENTERED");
        break;

      default: 
        break;
    }

  }

  

}
