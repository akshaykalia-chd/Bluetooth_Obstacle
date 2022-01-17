void obstacle(bool debug)
{  
  loop_count += 1;  
  outcome canImoveForward = can_i_move_forward();
  if (loop_count == 11)
    {      
      am_i_stuck();
      loop_count = 0;
      last_action = "";
    }
  
  if (canImoveForward.resp)
  {
    move_forward(step_size, debug);
    last_action += "C00";
    return;
  }
  outcome canImoveLeft = can_i_move_left(debug);
  outcome canImoveRight = can_i_move_right(debug);
  if (canImoveLeft.resp and canImoveRight.resp)
  {
    if (canImoveLeft.dist >= canImoveRight.dist)    
    {
      last_action += "C10";
      turn_left(step_size, debug );
      return;
    }
    else
    {
      last_action += "C11";
      turn_right(step_size, debug);
      return;
    }
  }

  if ((not canImoveLeft.resp) and (not canImoveRight.resp))
  {
    last_action += "C20";
    look_back(debug);
    return;
  }

  if (canImoveLeft.resp)
  {
    last_action += "C30";
    turn_left(step_size, debug );
    return;
  }
  else
  {
    last_action += "C31";
    turn_right(step_size, debug);
    return;
  }
}
