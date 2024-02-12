//Control of ultrasonic sensor (HNS04) and tilt ball switch. sending to port 9600
//based on PING arduino example

// array to store values to send to pure data
int values[2];

// pin numbers for ultrasonic sensor
const int trigPin = 7;
const int echoPin = 8;

// for the tilt sensor
int tiltPin = 2;
int reading;           // the current reading from the tilt pin
int previous = LOW;    // the previous reading from the tilt pin
// use long for large values (miliseconds)
long time = 0;         // the last time the output pin was toggled
long debounce = 50;   // the debounce time, increase if the output flickers

void setup() {
  // initialize serial communication
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);   // turn on the built in pull-up resistor
}

void loop() {
  int ultrasonic, tilt;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); //HCSO4 require 10 microsecond pulse!!!
  digitalWrite(trigPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH pulse
  // whose duration is the time (in microseconds) from the sending of the ping
  // to the reception of its echo off of an object.
  ultrasonic = pulseIn(echoPin, HIGH);

  // then read the value for tilt sensor
  tilt = digitalRead(tiltPin);
  
  // then send to serial monitor
  Serial.print(ultrasonic);
  Serial.print(" ");
  Serial.print(tilt);

  Serial.println(); // send to port
  delay(100);
 
}
