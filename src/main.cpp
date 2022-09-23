// I, Martin De Jesus Gonzalez Santos, 000790179 certify that this is my original work.
#include <Arduino.h>

void setup()
{
  // configure the USB serial monitor
  Serial.begin(115200);
}

float mapfloat(long x, long in_min, long in_max, long out_min, long out_max)
{
  return (float)(x - in_min) * (out_max - out_min) / (float)(in_max - in_min) + out_min;
}

void loop()
{
  int iVal;

  // read digitized value from the D1 Mini's A/D convertor
  iVal = analogRead(A0);
  float voltage = mapfloat(iVal, 0, 1024, 0, 50);  

  String feeling  = "";
  if (voltage < 10)
  {
    feeling = "Cold!";
  }
  else if (voltage >= 10 && voltage < 15)
  {
    feeling = "Cool";
  }
  else if (voltage >= 15 && voltage < 25)
  {
    feeling = "Perfect";
  }
  else if (voltage >= 25 && voltage < 30)
  {
    feeling = "Warm";
  }
  else if (voltage >= 30 && voltage < 35)
  {
    feeling = "Hot";
  }
  else if (voltage >= 35)
  {
    feeling = "Too Hot!";
  }

  // print value to the USB port
  Serial.println("Digitized Value Of " + String(iVal) + " is equivalent to a temperature input of " + String(temp) + " deg. C, which is " + feeling);

  // wait 0.5 seconds (500 ms)
  delay(500);
}