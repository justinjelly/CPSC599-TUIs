#include <Servo.h>
Servo servo;
int pos = 0;

int M1 = 3;
int M2 = 6;
int RED = 5;
int GREEN = 11;

int brightness=0;
int fanSpeed=0;
int prevFollowerCount=0;
int diff=0;
int followerCount=0;
int counter=0;

// if the follower count surpasses this goal, celebration time!!
int followerGoal = 1000;

void setup() {
  Serial.begin(9600);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  servo.attach(9);
  servo.write(158); //158
}

void loop() {
  
  // read value from serial port
  if(Serial.available() >0) {
    followerCount=Serial.parseInt();

    //diff range is 0 to 10
    diff = abs(min(10, followerCount-prevFollowerCount));

    // map to brightness and fan speed
    brightness = map(diff, 0, 10, 0, 255);
    fanSpeed = map(diff, 0, 10, 80, 210);


    // check if followergoal reached. this is commented out for the demo purposes but it works as practically intended.
//    if (followerCount >= followerGoal) {
//      servo.write(60);
//      digitalWrite(GREEN, HIGH);
//      digitalWrite(RED, HIGH);
//      analogWrite(M1, 255);
//      analogWrite(M2, 255);
//      delay(5000);
//      servo.write(165)
//      digitalWrite(GREEN, lOW);
//      digitalWrite(RED, LOW);
//      analogWrite(M1,0);
//      analogWrite(M2,0);
//      return;
//    }

  // this code is for the demo purpose. it will open the servo lids after x loops
      if (counter>=18) {
      delay(2000);
      servo.write(60);
      digitalWrite(GREEN, HIGH);
      digitalWrite(RED, HIGH);
      analogWrite(M1, 255);
      analogWrite(M2, 255);
      delay(10000);
      servo.write(165);
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      analogWrite(M1,0);
      analogWrite(M2,0);
      return;
    }

    // if followers gained
    if (prevFollowerCount < followerCount) {
      // turn off everything
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      analogWrite(M1, 0);
      analogWrite(M2, 0);
      delay(1);
      
      analogWrite(GREEN, brightness);
      analogWrite(M1, fanSpeed);
    }

    // if followers lost
    if (prevFollowerCount > followerCount) {
      // turn off everything
      digitalWrite(GREEN, LOW);
      digitalWrite(RED, LOW);
      analogWrite(M1, 0);
      analogWrite(M2, 0);
      delay(1);
      
      analogWrite(RED, brightness);
      analogWrite(M2, fanSpeed);
    }

    prevFollowerCount=followerCount;
    counter++;
  }
}
