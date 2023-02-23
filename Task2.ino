// C++ code
const int motionPin = 3; // Motion sensor signal pin
volatile int motionState = LOW; // Current motion state
volatile int lastMotionState = LOW; // Previous motion state
const int LED = 12;
void setup() {
pinMode(motionPin, INPUT);
pinMode(LED, OUTPUT);
attachInterrupt(digitalPinToInterrupt(motionPin), motionInterrupt, CHANGE);
Serial.begin(9600);
}
void loop() {
if (motionState != lastMotionState) {
if (motionState == HIGH) {
Serial.println("Motion detected!");
  digitalWrite(LED,HIGH);
Serial.println("LED turn on");
} else {
Serial.println("Motion ended.");
Serial.println("LED turn off");
}
lastMotionState = motionState;
}
}
void motionInterrupt() {
motionState = digitalRead(motionPin);
digitalWrite(LED, motionState);
}
