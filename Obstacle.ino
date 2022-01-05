void obstacle(bool debug)
{
  Serial.println("Obstacle Mode");
  if (can_i_move_forward())
  {
    move_forward(debug);
    return;
  }
  else
  {
    distance = cal_distance();
    prev_distance = distance;
    move_backward(debug);
    distance = cal_distance();
    long displacment = cal_displacment();
    if (displacment > 0)
    {
      move_backward(debug);
    }
    if (can_i_move_forward())
    {
      return;
    }
    else
    {
      turn_left(debug);
      turn_left(debug);
      if (can_i_move_forward())
      {
        return;
      }
      else
      {
        turn_right(debug);
        turn_right(debug);
        turn_right(debug);
        turn_right(debug);
        if (can_i_move_forward())
        {
          return;
        }
        else
        {
          turn_left(debug);
          turn_left(debug);          
          turn_left(debug);
          turn_left(debug);
          return;
        }

      }
    }
  }
}
