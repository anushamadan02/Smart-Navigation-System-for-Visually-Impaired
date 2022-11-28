#include <TinyGPS.h>
#include <SoftwareSerial.h>
SoftwareSerial SIM900(7, 22);

TinyGPS gps;  //Creates a new instance of the TinyGPS object


void setup()
{
  Serial1.begin(9600);
  SIM900.begin(9600);
  pinMode(35,INPUT);
 
}

void loop()
{
  int var;
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (Serial1.available())
    {
      char c = Serial1.read();
      //Serial.print(c);
      if (gps.encode(c)) 
        newData = true;
    }
  }
  var=digitalRead(35);
  if (var==HIGH)
  {
    if (newData)      //If newData is true
    {
      float flat, flon;
      unsigned long age;
      gps.f_get_position(&flat, &flon, &age);
      SIM900.print("Alert!!!\r"); 
      delay(400);
      SIM900.println("calling +917259491307\r");// recipient's mobile number with country code
      delay(300);
      SIM900.print("Latitude = ");
      SIM900.print(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6);
      SIM900.print(" Longitude = ");
      SIM900.print(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
      delay(200);
      SIM900.println((char)26); // End AT command with a ^Z, ASCII code 26
      delay(200);
      SIM900.println();
  
  
    }
  }
  else
  { 
    SIM900.println("SOS not activated!!\r");
    }
  //Serial1.println(failed);
 // if (chars == 0)
   // Serial.println(" No characters received from GPS: check wiring ");
   }
