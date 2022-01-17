#ifndef DIRECTIONS_H
#define DIRECTIONS_H
#include <Arduino.h>

class Directions
{
private:
  uint8_t _motor1;
  uint8_t _motor2;
  uint8_t _motor3;
  uint8_t _motor4;
  uint8_t _ENABLEpin_1;
  uint8_t _ENABLEpin_2;

public:
  Directions(uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2);
  String stop_moving(int ms_delay, bool debug);
  String move_forward(int ms_delay, bool debug);
  String move_backward(int ms_delay, bool debug);
  String turn_right(int ms_delay, bool debug);
  String turn_left(int ms_delay, bool debug);
  String look_left(int ms_delay, bool debug);
  String look_right(int ms_delay, bool debug);
  String look_back(int ms_delay, bool debug);
  String disable_motors(bool debug);
};

#endif
