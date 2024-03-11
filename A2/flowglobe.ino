// CSPC 599 Tangible and Physical User Interfaces Assignment 2. 
// The flowglobe is a tangible device that whirs and lights whose state and behaviour
// represents aa datastream of instagram followers from a specific account. 

int motorPin = 3;
int LED1 = 11; // GREEN
int LED2 = 10; // RED
int brightness=0;
int fanSpeed=0;
int prevFollowerCount=0;
int diff=0;
int followerCount=0;
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
} 
 
 
void loop() 
{ 
  // read value from serial port
  if(Serial.available() >0) {
    followerCount=Serial.parseInt();

    // limits on diff 
    if (followerCount-prevFollowerCount>3 ||
    followerCount-prevFollowerCount<-3) {
      diff=3;
    } else diff = abs(followerCount-prevFollowerCount);

    // adjust brightness and fanspeed based on how many followers gained/lost
    switch (diff){
      case 0:
        brightness = 0;
        fanSpeed = 0;
        break;
      case 1:
        brightness = 40;
        fanSpeed = 100;
        break;
      case 2:
        brightness = 200;
        fanSpeed = 150;
        break;
      case 3:
        brightness = 255;
        fanSpeed = 255;
        break; 
    }
    
    // if followers gained
    if (prevFollowerCount < followerCount){
      analogWrite(LED1, brightness);
      analogWrite(motorPin, fanSpeed);
      delay(3000);
      analogWrite(LED1, 0);
      analogWrite(motorPin, 0); 
    }

    // if followers lost
    if (prevFollowerCount > followerCount){
      analogWrite(LED2, brightness);
      analogWrite(motorPin, fanSpeed);
      delay(3000);
      analogWrite(LED2, 0);
      analogWrite(motorPin, 0);
    }

    prevFollowerCount=followerCount;
  }
  
} 
