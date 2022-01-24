#include "Obstacle.h"

Obstacle ::Obstacle(String _mode, bool _debug, int _step_size_look, int _stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3,
                    uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin,
                    uint8_t echoPin) : Stuck(_debug,_stop_distance,_step_size_look,motor1,motor2,motor3,motor4,ENABLEpin_1,ENABLEpin_2,trigPin,echoPin)
{ 
  mode = _mode;  
  debug = _debug;  
  loop_count = 0;
  last_action = "000";  
  stuck = false;
  turns = 0;
  look_backs = 0;
  move_forwards = 0;
  canImoveForward = false;
  canImoveLeft = false;
  canImoveRight = false;  
  motor_state = "NA";
  cmd = 0;
}

void Obstacle ::start_moving()
{  
  loop_count += 1;
  canImoveForward = can_i_move_forward();  
  if (loop_count > 10 & !stuck)
  {
    stuck = am_i_stuck();
    loop_count = 0;
    last_action += "CIS";
    turns = 0;
    look_backs = 0;
    move_forwards = 0;
  }

  if (stuck)
  {
    last_action += un_stuck();
    return;
  }

  if (canImoveForward)
  {
    move_forward(step_size, debug);
    last_action += "C00";
    move_forwards += 1;    
    return;
  }
  canImoveLeft = can_i_move_left(step_size_look, debug);
  long dist_to_obj_on_left = dist_to_obj;
  canImoveRight = can_i_move_right(step_size_look, debug);
  long dist_to_obj_on_right = dist_to_obj;
  if (canImoveLeft & canImoveRight)
  {
    if (dist_to_obj_on_left >= dist_to_obj_on_right)
    {
      last_action += "C10";
      turn_left(step_size, debug);
      turns += 1;      
      return;
    }
    else
    {
      last_action += "C11";
      turn_right(step_size,debug);
      turns += 1;      
      return;
    }
  }

  if ((!canImoveLeft) & (!canImoveRight))
  {
    last_action += "C20";
    look_back(step_size_look, debug);
    look_backs += 1;
    cal_distance();
    return;
  }

  if (canImoveLeft)
  {
    last_action += "C30";
    turn_left(step_size, debug);
    turns += 1;    
    return;
  }
  else
  {
    last_action += "C31";
    turn_right(step_size, debug);
    turns += 1;    
    return;
  }
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
  Serial.print(mode);
  Serial.print(",");
  Serial.print(debug);
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
  Serial.print(step_size);
  Serial.print(",");
  Serial.print(step_size_look);
  Serial.print(",");
  Serial.print(stop_distance);
  Serial.print(",");
  Serial.print(eprom_val);
  Serial.print(",");
  Serial.print(stuck);
  Serial.print(",");
  Serial.print(cmd);
  Serial.println();
}

void Obstacle::set_debug()
{
  motor_state = disable_motors(debug);
}
