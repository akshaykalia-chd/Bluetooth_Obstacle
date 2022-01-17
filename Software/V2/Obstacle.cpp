#include "Obstacle.h"

Directions move(9, 10, 12, 11, 8, 13);
CanImove canimove(30);

Obstacle ::Obstacle(bool debug, int step_size, int step_size_look, int stop_distance)
{
    
  _stop_distance = stop_distance;
  _debug = debug;
  _step_size = step_size;
  _step_size_look = step_size_look;
  loop_count = 0;
  last_action = "000";
  stuck = false;
  turns = 0;
  look_backs = 0;
  move_forwards = 0;
  canImoveForward = {false, 0};
  canImoveLeft = {false, 0};
  canImoveRight = {false, 0};
  count_call_un_stuck = 0;
  motor_state = "NA";  
}

void Obstacle ::start_moving()
{  
  canimove._stop_distance = _stop_distance;
  loop_count += 1;
  canImoveForward = canimove.can_i_move_forward();
  if (loop_count > 10 & !stuck)
  {
    stuck = am_i_stuck();
    loop_count = 0;
    last_action = "";
    turns = 0;
    look_backs = 0;
    move_forwards = 0;
  }

  if (stuck)
  {
    un_stuck();
    return;
  }

  if (canImoveForward.resp)
  {
    move.move_forward(_step_size, _debug);
    last_action += "C00";
    move_forwards += 1;
    return;
  }
  canImoveLeft = canimove.can_i_move_left(_step_size_look, _debug);
  canImoveRight = canimove.can_i_move_right(_step_size_look, _debug);
  if (canImoveLeft.resp & canImoveRight.resp)
  {
    if (canImoveLeft.dist >= canImoveRight.dist)
    {
      last_action += "C10";
      move.turn_left(_step_size, _debug);
      turns += 1;
      return;
    }
    else
    {
      last_action += "C11";
      move.turn_right(_step_size, _debug);
      turns += 1;
      return;
    }
  }

  if ((!canImoveLeft.resp) & (!canImoveRight.resp))
  {
    last_action += "C20";
    move.look_back(_step_size_look, _debug);
    look_backs += 1;
    return;
  }

  if (canImoveLeft.resp)
  {
    last_action += "C30";
    move.turn_left(_step_size, _debug);
    turns += 1;
    return;
  }
  else
  {
    last_action += "C31";
    move.turn_right(_step_size, _debug);
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
    Serial.print("Debug,Loop Count,Last 10 Actions,No Of Turns,No Of Look Backs,");
    Serial.print("No Of Move Forwards,Motor State,Step Size, Step Size Look,Stop Distance,Stuck");
    Serial.println();
  }
  
  Serial.print(_debug);
  Serial.print(",");
  Serial.print(loop_count);
  Serial.print(",");
  Serial.print(last_action);
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
  Serial.print(canimove._stop_distance);
  Serial.print(",");  
  Serial.print(stuck);
  Serial.println();
}

void Obstacle::un_stuck()
{
  count_call_un_stuck += 1;
  if (count_call_un_stuck == 1)
  {
    last_action += "S01";
    move.turn_left(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (canImoveForward.resp)
    {
      stuck = false;
      return;
    }
    move.turn_left(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (!canImoveForward.resp)
    {
      move.turn_right(_step_size, _debug);
      move.stop_moving(_step_size, _debug);
      move.turn_right(_step_size, _debug);
      move.stop_moving(_step_size, _debug);
    }
  }
  else if (count_call_un_stuck == 2)
  {
    last_action += "S02";
    move.turn_right(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (canImoveForward.resp)
    {
      stuck = false;
      return;
    }
    move.turn_right(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (!canImoveForward.resp)
    {
      move.turn_left(_step_size, _debug);
      move.stop_moving(_step_size, _debug);
      move.turn_left(_step_size, _debug);
      move.stop_moving(_step_size, _debug);
    }
  }
  else if (count_call_un_stuck == 3)
  {
    last_action += "S03";
    move.look_back(_step_size_look, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (canImoveForward.resp)
    {
      stuck = false;
      return;
    }
    move.look_back(_step_size_look, _debug);
    move.stop_moving(_step_size, _debug);
  }
  else
  {
    last_action += "S04";
    count_call_un_stuck = 0;
    move.move_forward(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (canImoveForward.resp)
    {
      stuck = false;
      return;
    }
    move.move_forward(_step_size, _debug);
    move.stop_moving(_step_size, _debug);
    canImoveForward = canimove.can_i_move_forward();
    if (canImoveForward.resp)
    {
      stuck = false;
      return;
    }
  }
}

void Obstacle::set_debug()
{  
  motor_state = move.disable_motors(_debug);
}

