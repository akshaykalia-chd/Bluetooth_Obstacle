void obstacle(bool debug)
{
  Serial.println("Obstacle Mode");
  outcome canImoveLeft = {false, 0};
  outcome canImoveRight = {false, 0};
  outcome canImoveForward = can_i_move_forward();
  if (canImoveForward.resp)
  {
    move_forward(debug, step_size);
    return;
  }
  else
  {
    canImoveLeft = can_i_move_left(debug);       
    canImoveRight = can_i_move_right(debug);    
  }

  if (canImoveLeft.resp and canImoveRight.resp)
  {
    if (canImoveLeft.dist >= canImoveRight.dist)
    {

      turn_left(debug, step_size );
      return;
    }
    else
    {
      turn_right(debug, step_size);
      return;
    }
  }
  else if (canImoveLeft.resp)
  {
    turn_left(debug, step_size );
    return;
  }
  else
  {
    turn_right(debug, step_size);
    return;
  }
}
