#include "Directions.h"

Directions::Directions(uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2)
{
  _motor1 = motor1;
  _motor2 = motor2;
  _motor3 = motor3;
  _motor4 = motor4;
  _ENABLEpin_1 = ENABLEpin_1;
  _ENABLEpin_2 = ENABLEpin_2;
  pinMode(_motor1, OUTPUT);
  pinMode(_motor2, OUTPUT);
  pinMode(_motor3, OUTPUT);
  pinMode(_motor4, OUTPUT);
  pinMode(_ENABLEpin_1, OUTPUT);
  pinMode(_ENABLEpin_2, OUTPUT);
}

String Directions::stop_moving(int ms_delay, bool debug)
{
  if (!debug)
  {
    digitalWrite(_motor1, LOW); //Stop
    digitalWrite(_motor2, LOW);
    digitalWrite(_motor3, LOW);
    digitalWrite(_motor4, LOW);
  }
  delay(ms_delay);
  return "stop_moving";
}

String Directions::move_forward(int ms_delay, bool debug)
{
  if (!debug)
  {
    digitalWrite(_motor1, LOW);  //9
    digitalWrite(_motor2, HIGH); //10
    digitalWrite(_motor3, LOW);  //12
    digitalWrite(_motor4, HIGH); //11
  }
  delay(ms_delay);
  return "move_forward";
}

String Directions::move_backward(int ms_delay, bool debug)
{
  if (!debug)
  {
    digitalWrite(_motor1, HIGH); //9//Move Backword
    digitalWrite(_motor2, LOW);  //10
    digitalWrite(_motor3, HIGH); //12
    digitalWrite(_motor4, LOW);  //11
  }
  delay(ms_delay);
  return "move_backward";
}

String Directions::turn_right(int ms_delay, bool debug)
{
  if (!debug)
  {
    digitalWrite(_motor1, LOW);
    digitalWrite(_motor2, HIGH);
    digitalWrite(_motor3, HIGH);
    digitalWrite(_motor4, LOW);
  }
  delay(ms_delay);
  return "turn_right";
}

String Directions::turn_left(int ms_delay, bool debug)
{
  if (!debug)
  {
    digitalWrite(_motor1, HIGH);
    digitalWrite(_motor2, LOW);
    digitalWrite(_motor3, LOW);
    digitalWrite(_motor4, HIGH);
  }
  delay(ms_delay);
  return "turn_left";
}

String Directions::look_left(int ms_delay, bool debug)
{
  turn_left(ms_delay, debug);
  return "look_left";
}

String Directions::look_right(int ms_delay, bool debug)
{
  turn_right(ms_delay, debug);
  return "look_right";
}

String Directions::look_back(int ms_delay, bool debug)
{
  turn_right(ms_delay, debug);
  stop_moving(ms_delay, debug);
  turn_right(ms_delay, debug);
  return "look_back";
}

String Directions::disable_motors(bool debug)
{
  if (debug)
  {
    digitalWrite(_ENABLEpin_1, LOW);
    digitalWrite(_ENABLEpin_2, LOW);
    return "Disabled";
  }
  else
  {
    digitalWrite(_ENABLEpin_1, HIGH);
    digitalWrite(_ENABLEpin_2, HIGH);
    return "Enabled";
  }
}
