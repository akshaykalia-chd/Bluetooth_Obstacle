#ifndef Radar_H
#define Radar_H
#include <Arduino.h>

class Radar
{
private:
  uint8_t _trigPin;
  uint8_t _echoPin;
  void send_echo();
  long duration;
  long microsecondsToCentimeters(long microseconds);

public:
  Radar(uint8_t trigPin, uint8_t echoPin);
  long dist_to_obj;
  void cal_distance();
};
#endif
