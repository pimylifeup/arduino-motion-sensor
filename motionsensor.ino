/*
  Arduino Motion Sensor

  Created: 3/11/2015
  By Gus
  Modified N/A
  By Gus

  http://pimylifeup.com/arduino-motion-sensor
*/


int ledPin = 4;                // Pin LED is connected to
int piezoBuzzerPin = 3;     // Pin Piezo Buzzer is connected to
int pirSensorPin = 2;               // PIN PIR Sensor is connected to

int motionDetected = LOW;             // Start MotionDetected as low (No motion detected)

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirSensorPin, INPUT);     // declare the PIR sensor as input
  pinMode(piezoBuzzerPin, OUTPUT); //declare buzzer as output
  Serial.begin(9600); //Set serial out if we want debugging
  delay(5000); //Allow time for the PIR Sensor to callibrate
}

void loop(){
  motionDetected = digitalRead(pirSensorPin);  // Read the PIR sensor
  if(motionDetected == HIGH) //If motion detected
  {            
    digitalWrite(ledPin, HIGH);
    analogWrite(piezoBuzzerPin, 200);
    delay(100);
    analogWrite(ledPin, LOW);
    analogWrite(piezoBuzzerPin, 25);
    delay(100);
  }
  digitalWrite(ledPin, LOW);
  digitalWrite(piezoBuzzerPin,LOW);
}
