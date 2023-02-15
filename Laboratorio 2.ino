// Define constants for the LED pins and the pushbutton pin
const int LED_START_PIN = 2;
const int LED_END_PIN = 9;
const int BUTTON_PIN = 10;

// Define a variable to store the current state of the pushbutton and the state of the LED blinking
int buttonState = 0;
bool blinkLEDs = false;

void setup() {
  // Initialize the LED pins as outputs and turn them all on
  for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  
  // Initialize the pushbutton pin as an input
  pinMode(BUTTON_PIN, INPUT);
  
  // Initialize the serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if the pushbutton is pressed
  buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == HIGH) {
    // If the button is pressed, turn the blinking off and turn the LEDs on and off in sequence
    blinkLEDs = false;
    for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {
      digitalWrite(i, LOW);
      delay(100);
      digitalWrite(i, HIGH);
    }
  } else if (blinkLEDs) {
    // If the button is not pressed but the LEDs should blink, turn them on and off with a 2 second delay
    for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {
      digitalWrite(i, LOW);
    }
    delay(2000);
    for (int i = LED_START_PIN; i <= LED_END_PIN; i++) {
      digitalWrite(i, HIGH);
    }
    delay(2000);
  }
  
  if (Serial.available() > 0) {
    // Read the incoming message from the serial monitor
    int message = Serial.parseInt();
    
    if (message == 2) {
      // If the message is 2, turn on the LED blinking
      blinkLEDs = true;
    }
  }
}
