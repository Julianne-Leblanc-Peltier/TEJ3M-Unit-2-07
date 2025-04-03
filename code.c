/* 
 * Created by Julianne Leblanc-Peltier
 * Created on April 2025
 * This program turns servo 90 if sensor detects distance less than 20 cm
*/

# include <Servo.h>


const int TRIG_PIN = 3;  
const int ECHO_PIN = 2;
const int DISTANCE_TO_START = 20;
const float CONVERSION_METRIC = 0.0343;
 
float duration; 
float DISTANCE;

Servo servoNumber1;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(6);
  servoNumber1.write(0);
}

void loop() {
 // clears trig pin
  servoNumber1.write(0);
  digitalWrite(TRIG_PIN, LOW);

  // set trig on high for 10 microseconds
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // detects distance
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * CONVERSION_METRIC) / 2;
  Serial.print("Distance: ");
  Serial.println(distance);
  Serial.print("cm");
  delay(100);
  
  if (distance < DISTANCE_TO_START) {
    servoNumber1.write(0);
    delay(1000);
    servoNumber1.write(90);
    delay(1000);
  }
}
