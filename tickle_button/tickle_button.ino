const int buttonPin = 2;    // the number of the pushbutton pin
const int ledPin = 13;      // the number of the LED pin
const int buzzer = 8; //buzzer to arduino pin 9
int redPin = 3;     // Red RGB pin -> D3
int greenPin = 5;   // Green RGB pin -> D5
int bluePin = 6;    // Blue RGB pin -> D6
long randomNumber;
long spinCount;
boolean randomGenerated = false;
int ledState = HIGH;         // the current state of the output pin
int buttonState;             // the current reading from the input pin
int lastButtonState = LOW;   // the previous reading from the input pin
long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  digitalWrite(A0, HIGH);

  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  if (!randomGenerated){
  randomNumber = random(1, 9);
  randomGenerated = true;
  }
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);
 
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
      


      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
        spinCount = spin(spinCount);
      }
    }
  }

  // set the LED:
  digitalWrite(ledPin, ledState);


  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}


void buzz() {
  Serial.println("BUZZ!!!");
  digitalWrite(buzzer, HIGH); // Send 1KHz sound signal...
  delay(1000);
  digitalWrite(buzzer, LOW);     // Stop sound...
  randomGenerated = false;
}

void lights() {
  Serial.println("LIGHTS!!");
  for (int x = 0; x <= 10; x++){
  setColor(255, 0, 0);  // red
  delay(80);
  setColor(0, 255, 0);  // green
  delay(80);
  setColor(0, 0, 255);  // orange!
  delay(80);
  setColor(255, 255, 0);  // green!
  delay(80);  
  setColor(80, 0, 80);  // purple
  delay(80);
  setColor(0, 255, 255);  // aqua
  delay(80);
  };
  setColor(255, 255, 255); //off
}

void setColor(int red, int green, int blue){
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

int spin(long spinCount) {
  Serial.println("SPIN!");
  Serial.println(" Random Number: ");;
  Serial.println(randomNumber);
  Serial.println(" Spin Count: ");
  Serial.println(spinCount);
  spinCount++;
  if (spinCount == randomNumber) {
    Serial.println("TICKLE TIME!");
    buzz();
    lights();
    
    spinCount = 0;
  };
  return spinCount;
}
