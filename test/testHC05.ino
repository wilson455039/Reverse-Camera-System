#include <SoftwareSerial.h>
#include <Wire.h>
#include <Servo.h>  

Servo servo_1;  
Servo servo_2;  
// defines pins numbers
const int trigPin = 12;
const int echoPin = 13;
// defines variables
long duration;
int distance;
int LED = 5;
char LEDstatus;
SoftwareSerial BT(10,11);
void setup()
{
 pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
 pinMode(echoPin, INPUT); // Sets the echoPin as an Input
 pinMode(9,OUTPUT);
 digitalWrite(9,HIGH);
 Serial.begin(9600);
 Serial.println("Enter AT commands:");
 BT.begin(38400); // set HC-06 baud rate
 pinMode(LED, OUTPUT);  
 servo_1.attach(8);  
 servo_2.attach(9);  
}
void loop()
{
    // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  servo_1.write(0);  
  servo_2.write(0);
//  delay(1000);
//  servo_1.write(90);
//  servo_2.write(90);
//  delay(1000);
 //read BT and transmit to mobile phone
 if (BT.available()){
    LEDstatus=BT.read();t
    Serial.println(LEDstatus);  
 }
 //switch LED with BT function
 switch (LEDstatus){ 
  case 'a':
  digitalWrite(LED,HIGH);
  break;
  case 'b':
  digitalWrite(LED,LOW);
  break;
  }
}
