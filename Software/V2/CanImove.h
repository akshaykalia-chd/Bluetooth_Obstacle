#ifndef CANIMOVE_H
#define CANIMOVE_H
#include <Arduino.h>
#include "Radar.h"
#include "Directions.h"

class CanImove: public Directions, public Radar
{ 
public:
  int _stop_distance;
  CanImove(int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin);
  bool can_i_move_forward();
  bool can_i_move_left(int ms_delay, bool debug);
  bool can_i_move_right(int ms_delay, bool debug); 
};
#endif
