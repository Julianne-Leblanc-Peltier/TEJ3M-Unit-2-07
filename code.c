/* 
 * Created by Julianne Leblanc-Peltier
 * Created on April 2025
 * 
*/

# include <Servo.h>


const int TRIG_PIN = 3;  
const int ECHO_PIN = 2; 

Servo servoNumber1;
  
float duration, distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(9600);
  servoNumber1.attach(6);
  servoNumber1.write(0);
}

void loop() {
  servoNumber1.write(0);
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
  
  if (distance < 50) {
    servoNumber1.write(0);
    delay(1000);
    servoNumber1.write(90);
    delay(1000);
	}
}
