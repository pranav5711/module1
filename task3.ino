// C++ code
const int motionPin = 3; // Motion sensor signal pin
const int motionPin2 = 2; // Motion sensor signal pin
volatile int motionState = LOW; // Current motion state
volatile int lastMotionState = LOW; // Previous motion state

volatile int motionState2 = LOW; // Current motion state
volatile int lastMotionState2 = LOW; // Previous motion state

const int LED = 12;
void setup() {
pinMode(motionPin, INPUT);
pinMode(LED, OUTPUT);
  pinMode(motionPin2, INPUT);
attachInterrupt(digitalPinToInterrupt(motionPin), motionInterrupt, CHANGE);
  attachInterrupt(digitalPinToInterrupt(motionPin2), motionInterrupt2, CHANGE);
Serial.begin(9600);
}
void loop() {
if (motionState != lastMotionState) {
if (motionState == HIGH) {

  digitalWrite(LED,HIGH);
Serial.println("LED turn on");
} else {
Serial.println("LED turn off");
}
lastMotionState = motionState;
}
}
void motionInterrupt() {
motionState = digitalRead(motionPin);
digitalWrite(LED, motionState);
  Serial.println("Motion detected sesnsor 1!");
}

void motionInterrupt2() {
motionState2 = digitalRead(motionPin2);
digitalWrite(LED, motionState2);
    Serial.println("Motion detected sesnsor 2!");
}
