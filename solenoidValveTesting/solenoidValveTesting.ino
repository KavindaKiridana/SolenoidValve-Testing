// Simple Arduino Uno Solenoid Test with Relay and Button
const int RELAY_PIN = 8;      // Relay control on D8
const int BUTTON_PIN = 2;     // Button on D2 (with pull-up)
const int LED_PIN = 13;       // LED on D13 (built-in LED)//i wantot 

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Enable internal pull-up
  pinMode(LED_PIN, OUTPUT);
  
  // Start with relay OFF and LED OFF
  digitalWrite(RELAY_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  
  Serial.begin(9600);
  Serial.println("Solenoid Test Program Ready");
}

void loop() {
  // Read button state (LOW when pressed, HIGH when not pressed)
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) { // Button pressed
    digitalWrite(RELAY_PIN, HIGH); // Turn ON relay (solenoid activates)
    digitalWrite(LED_PIN, HIGH);   // Turn ON LED
    Serial.println("Button pressed - Solenoid ON");
  } else { // Button not pressed
    digitalWrite(RELAY_PIN, LOW);  // Turn OFF relay (solenoid deactivates)
    digitalWrite(LED_PIN, LOW);    // Turn OFF LED
    Serial.println("Button off - Solenoid OFF");
  }
  
  delay(50); // Small debounce delay
}