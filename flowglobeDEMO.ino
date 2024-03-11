// demo mode to show the states of the flowglobe.

int motorPin = 3;
int LED1 = 11; // GREEN
int LED2 = 10; //RED

void setup() {
  // put your setup code here, to run once:
  pinMode(motorPin, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

    // gain 1 follower
    delay(3000);
    analogWrite(LED1, 40);
    analogWrite(motorPin, 100);
    delay(3000);
    analogWrite(LED1, 0);
    analogWrite(motorPin, 0); 

    // lose 2 followers
    delay(3000);
    analogWrite(LED2, 200);
    analogWrite(motorPin, 150);
    delay(3000);
    analogWrite(LED2, 0);
    analogWrite(motorPin, 0); 

    // gain 3+ followers
    delay(3000);
    analogWrite(LED1, 255);
    analogWrite(motorPin, 255);
    delay(3000);
    analogWrite(LED1, 0);
    analogWrite(motorPin, 0); 

}
