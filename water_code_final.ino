int SensorPin = A0;

void setup() {
  // set up the LCD's number of columns and rows:
Serial.begin(9600);
  
}

void loop() {

  int SensorValue = analogRead(SensorPin);   
  float SensorVolts = analogRead(SensorPin)*0.0048828125;   

SensorValue = analogRead(SensorPin);
 Serial.println(SensorValue);
//  lcd.setCursor(4,2);
//  lcd.print(sensorValue);
//  delay(1000);
  
}
