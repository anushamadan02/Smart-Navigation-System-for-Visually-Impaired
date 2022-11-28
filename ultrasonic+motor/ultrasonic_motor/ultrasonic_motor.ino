const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}
  
  


void setup() {
  Serial.begin(9600); // Starting Serial Communication
  pinMode(pingPin, OUTPUT); // initialising pin 10 as output
  pinMode(echoPin, INPUT); // initialising pin 9 as input
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop() 
  {
  long duration, inches, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);

  
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(100);
  if (inches<100)
  {
    digitalWrite(5,HIGH);
    digitalWrite(4,LOW);
    delay(3000);
    }
 else 
 {
    digitalWrite(5,LOW);
    digitalWrite(4,LOW);
    delay(3000);
  
  }
 
}



