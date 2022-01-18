#include "Obstacle.h"

Obstacle ::Obstacle(char mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3,
                    uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin,
                    uint8_t echoPin) : CanImove(stop_distance, motor1, motor2, motor3, motor4, ENABLEpin_1, ENABLEpin_2, trigPin, echoPin)
{

  eprom_val = EEPROM.read(1);
  _mode = mode;
  _stop_distance = stop_distance;
  _debug = debug;
  _step_size = (eprom_val * 10) + 100;
  _step_size_look = step_size_look;
  loop_count = 0;
  last_action = "000";  
  stuck = false;
  turns = 0;
  look_backs = 0;
  move_forwards = 0;
  canImoveForward = false;
  canImoveLeft = false;
  canImoveRight = false;
  count_call_un_stuck = 0;
  motor_state = "NA";
  cmd = 0;
}

void Obstacle ::start_moving()
{
  print_data();
  loop_count += 1;
  canImoveForward = can_i_move_forward();  
  if (loop_count > 10 & !stuck)
  {
    stuck = am_i_stuck();
    loop_count = 0;
    last_action = "CIS";
    turns = 0;
    look_backs = 0;
    move_forwards = 0;
  }

  if (stuck)
  {
    un_stuck();
    return;
  }

  if (canImoveForward)
  {
    move_forward(_step_size, _debug);
    last_action += "C00";
    move_forwards += 1;    
    return;
  }
  canImoveLeft = can_i_move_left(_step_size_look, _debug);
  long dist_to_obj_on_left = dist_to_obj;
  canImoveRight = can_i_move_right(_step_size_look, _debug);
  long dist_to_obj_on_right = dist_to_obj;
  if (canImoveLeft & canImoveRight)
  {
    if (dist_to_obj_on_left >= dist_to_obj_on_right)
    {
      last_action += "C10";
      turn_left(_step_size, _debug);
      turns += 1;      
      return;
    }
    else
    {
      last_action += "C11";
      turn_right(_step_size, _debug);
      turns += 1;      
      return;
    }
  }

  if ((!canImoveLeft) & (!canImoveRight))
  {
    last_action += "C20";
    look_back(_step_size_look, _debug);
    look_backs += 1;
    cal_distance();
    return;
  }

  if (canImoveLeft)
  {
    last_action += "C30";
    turn_left(_step_size, _debug);
    turns += 1;    
    return;
  }
  else
  {
    last_action += "C31";
    turn_right(_step_size, _debug);
    turns += 1;    
    return;
  }
}

bool Obstacle::am_i_stuck()
{
  if (move_forwards < 2)
  {
    return true;
  }
  return false;
}

void Obstacle::print_data()
{
  if (last_action == "000")
  {    
    Serial.print("Mode,Debug,Loop Count,Last Act(s),Distance to Object,No Of Turns,");
    Serial.print("No Of Look Backs,No Of Move Forwards,Motor State,Step Size, Step Size Look,");
    Serial.print("Stop Distance,EPROM_VAL,Stuck,CMD");
    Serial.println();
  }
  Serial.print(_mode);
  Serial.print(",");
  Serial.print(_debug);
  Serial.print(",");
  Serial.print(loop_count);
  Serial.print(",");
  Serial.print(last_action);
  Serial.print(",");
  Serial.print(dist_to_obj);
  Serial.print(",");
  Serial.print(turns);
  Serial.print(",");
  Serial.print(look_backs);
  Serial.print(",");
  Serial.print(move_forwards);
  Serial.print(",");
  Serial.print(motor_state);
  Serial.print(",");
  Serial.print(_step_size);
  Serial.print(",");
  Serial.print(_step_size_look);
  Serial.print(",");
  Serial.print(_stop_distance);
  Serial.print(",");
  Serial.print(eprom_val);
  Serial.print(",");
  Serial.print(stuck);
  Serial.print(",");
  Serial.print(cmd);
  Serial.println();
}

void Obstacle::un_stuck()
{

  count_call_un_stuck += 1;
  if (count_call_un_stuck == 1)
  {
    last_action += "S01";
    turn_left(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (canImoveForward)
    {
      stuck = false;
      return;
    }
    turn_left(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (!canImoveForward)
    {
      turn_right(_step_size, _debug);
      stop_moving(_step_size, _debug);
      turn_right(_step_size, _debug);
      stop_moving(_step_size, _debug);
    }
  }
  else if (count_call_un_stuck == 2)
  {
    last_action += "S02";
    turn_right(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (canImoveForward)
    {
      stuck = false;
      return;
    }
    turn_right(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (!canImoveForward)
    {
      turn_left(_step_size, _debug);
      stop_moving(_step_size, _debug);
      turn_left(_step_size, _debug);
      stop_moving(_step_size, _debug);
    }
  }
  else if (count_call_un_stuck == 3)
  {
    last_action += "S03";
    look_back(_step_size_look, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (canImoveForward)
    {
      stuck = false;
      return;
    }
    look_back(_step_size_look, _debug);
    stop_moving(_step_size, _debug);
  }
  else
  {
    last_action += "S04";
    count_call_un_stuck = 0;
    if (loop_count > 100)
    {
      loop_count = 0;
      last_action = "";
    }
    move_forward(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (canImoveForward)
    {
      stuck = false;
      return;
    }
    move_forward(_step_size, _debug);
    stop_moving(_step_size, _debug);
    canImoveForward = can_i_move_forward();
    if (canImoveForward)
    {
      stuck = false;
      return;
    }
  }
}

void Obstacle::set_debug()
{
  motor_state = disable_motors(_debug);
}
