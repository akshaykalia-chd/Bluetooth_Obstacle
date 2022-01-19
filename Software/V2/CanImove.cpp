#include "CanImove.h"

CanImove::CanImove(int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin) : Directions(motor1, motor2, motor3, motor4, ENABLEpin_1, ENABLEpin_2), Radar(trigPin, echoPin)
{
  _stop_distance = stop_distance;
}

bool CanImove::can_i_move_forward()
{
  cal_distance();
  if (dist_to_obj > _stop_distance & dist_to_obj < 1150)
  {
    return true;
  }
  return false;
}

bool CanImove::can_i_move_left(int ms_delay, bool debug)
{
  look_left(ms_delay, debug);
  stop_moving(ms_delay, debug);
  cal_distance();
  look_right(ms_delay, debug);
  stop_moving(100, debug);
  if (dist_to_obj > _stop_distance & dist_to_obj < 1150)
  {
    return true;
  }
  return false;
}

bool CanImove::can_i_move_right(int ms_delay, bool debug)
{
  look_right(ms_delay, debug);
  stop_moving(ms_delay, debug);
  cal_distance();
  look_left(ms_delay, debug);
  stop_moving(ms_delay, debug);
  if (dist_to_obj > _stop_distance & dist_to_obj < 1150)
  {
    return true;
  }
  return false;
}
