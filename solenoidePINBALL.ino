int led = 13;
//int button 2; 
int solenoide = 4;

void setup() {
  //pinMode(button, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(solenoide, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  int buttonState = digitalRead(button); // Read the state of the button
  if (buttonState == HIGH) {
  digitalWrite(solenoide, HIGH);
  digitalWrite(led, HIGH);
  } else {
  digitalWrite(solenoide, LOW);
  digitalWrite(led, LOW);
  }
 
}