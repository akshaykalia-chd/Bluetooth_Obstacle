#include "Radar.h"

Radar::Radar(uint8_t trigPin, uint8_t echoPin)
{
  _trigPin = trigPin;
  _echoPin = echoPin;    
}

long Radar::microsecondsToCentimeters(long ms)
{
  return ms / 29 / 2;
}

void Radar::send_echo()
{
  digitalWrite(_trigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(_trigPin, LOW);
  delayMicroseconds(5);
  duration = pulseIn(_echoPin, HIGH);  
}

void Radar::cal_distance()
{
  send_echo();  
  dist_to_obj = microsecondsToCentimeters(duration);  
}
