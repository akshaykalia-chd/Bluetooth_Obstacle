#ifndef CANIMOVE_H
#define CANIMOVE_H
#include <Arduino.h>
#include "Radar.h"
#include "Directions.h"

typedef struct
{
  bool resp;
  long dist;
} outcome;

class CanImove
{ 
public:
  int _stop_distance;
  CanImove(int stop_distance);
  outcome can_i_move_forward();
  outcome can_i_move_left(int ms_delay, bool debug);
  outcome can_i_move_right(int ms_delay, bool debug); 
};
#endif
