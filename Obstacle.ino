void obstacle(bool debug)
{
  Serial.println("Obstacle Mode");
  if (can_i_move_forward())
  {
    move_forward(debug, step_size);
    return;
  }
  else
  {
    distance = cal_distance();
    prev_distance = distance;
    move_backward(debug, step_size);
    distance = cal_distance();
    long displacment = cal_displacment();
    if (displacment < 0)
    {
      move_backward(debug, step_size);
    }
    if (can_i_move_forward())
    {
      return;
    }
    else
    {
      turn_left(debug, step_size);
      turn_left(debug, step_size);
      if (can_i_move_forward())
      {
        return;
      }
      else
      {
        turn_right(debug, step_size);
        turn_right(debug, step_size);
        turn_right(debug, step_size);
        turn_right(debug, step_size);
        if (can_i_move_forward())
        {
          return;
        }
        else
        {
          turn_left(debug, step_size);
          turn_left(debug, step_size);
          turn_left(debug, step_size);
          turn_left(debug, step_size);
          return;
        }

      }
    }
  }
}
