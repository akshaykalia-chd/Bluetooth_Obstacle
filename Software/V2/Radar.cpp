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
}

long Radar::cal_distance()
{
  send_echo();
  long duration = pulseIn(_echoPin, HIGH);
  long cm = microsecondsToCentimeters(duration);
  return cm;
}
