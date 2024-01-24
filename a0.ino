// Assignment 0: Hello World. Visit https://justinyu.carrd.co/ for info.
// CPSC 599 Justin Yu 30093886

// initializing led and button pins
int REDPIN = 11;
int GREENPIN = 10;
int BLUEPIN = 9;
int BUTTONPIN = 2;

int buttonState = 0; //tracks button state
int prevButtonState = 0; // tracks last state 
int buttonCounter = 0; // tracks button presses

void setup() {
  // RGB pins as output
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);

  // button as input. Using INPUT_PULLUP to use internal resistor for button. default is HIGH
  pinMode(BUTTONPIN, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(BUTTONPIN) == LOW) { // if the button is pressed
    buttonCounter++;
    delay(400); // delay to allow button to press fully
  }

  switch (buttonCounter%9) {
    case 0:
      changeColour(0,0,0); // off
      break;
    case 1:
      changeColour(255,255,0); // bright yellow
      break;
    case 2:
      changeColour(100,100,0); // dim yellow
      break;
    case 3:
      changeColour(0,255,255); // bright teal
      break;
    case 4:
      changeColour(0,100,100); // dim teal
      break;
    case 5:
      changeColour(50,255,50); // bright green
      break;
    case 6:
      changeColour(20,100,20); // dim green
      break;
    case 7:
      changeColour(255,0,50); // bright pink
      break;
    case 8:
      changeColour(100,0,20); // dim pink
      break;
  }

}

void changeColour(int r, int g, int b) {
    analogWrite(REDPIN,   r);
    analogWrite(GREENPIN, g);
    analogWrite(BLUEPIN,  b);
}
