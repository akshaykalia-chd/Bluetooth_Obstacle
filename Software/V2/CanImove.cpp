#include "CanImove.h"

Directions _move(9, 10, 12, 11, 8, 13);
Radar _radar(6, 7);

CanImove::CanImove(int stop_distance)
{
  _stop_distance = stop_distance;
}

outcome CanImove::can_i_move_forward()
{
  long distance = _radar.cal_distance();
  outcome forward = {false, distance};
  if (distance > _stop_distance & distance < 1200)
  {
    forward = {true, distance};
  }
  return forward;
}

outcome CanImove::can_i_move_left(int ms_delay, bool debug)
{
  _move.look_left(ms_delay, debug);
  _move.stop_moving(ms_delay, debug);
  long distance = _radar.cal_distance();
  outcome left = {false, distance};
  _move.look_right(ms_delay, debug);
  _move.stop_moving(100, debug);
  if (distance > _stop_distance & distance < 1200)
  {
    left = {true, distance};
  }
  return left;
}

outcome CanImove::can_i_move_right(int ms_delay, bool debug)
{
  _move.look_right(ms_delay, debug);
  _move.stop_moving(ms_delay, debug);
  long distance = _radar.cal_distance();
  outcome right = {false, distance};
  _move.look_left(ms_delay, debug);
  _move.stop_moving(ms_delay, debug);
  if (distance > _stop_distance & distance < 1200)
  {
    right = {true, distance};
  }
  return right;
}
