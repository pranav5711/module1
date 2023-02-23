const int MotionSensor = 3; 
int LED = 12;
int MotionState = LOW;
void setup() {
pinMode(LED, OUTPUT);
pinMode(MotionSensor, INPUT);

Serial.begin(9600);
}
void loop() {
MotionState = digitalRead(MotionSensor);

if (MotionState == HIGH) {
Serial.println("Motion detected");
digitalWrite(LED, HIGH);
Serial.println("LED turned on");
}

else {
Serial.println("Motion not detected");
digitalWrite(LED, LOW);
Serial.println("LED turned off");
}
delay(1000);
}
