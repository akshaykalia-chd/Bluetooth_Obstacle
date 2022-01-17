outcome can_i_move_forward()
{
  long distance = cal_distance();
  outcome  forward = {false, distance};
  if (distance > 50 and distance < 1200)
  {
    forward = {true, distance};
  }
  Serial.print("Can i move forward?");
  if (forward.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return forward;
}


outcome can_i_move_left(bool debug)
{
  look_left(debug);
  stop_moving(100, debug);
  long distance = cal_distance();
  outcome  left = {false, distance};
  look_right(debug);
  stop_moving(100, debug);
  if (distance > 50 and distance < 1200)
  {
    left = {true, distance};
  }
  Serial.print("Can i move forward on the left?");
  if (left.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return left;
}

outcome can_i_move_right(bool debug)
{
  look_right(debug);
  stop_moving(100, debug);
  long distance = cal_distance();
  outcome right = {false, distance};
  look_left(debug);
  stop_moving(100, debug);
  if (distance > 50 and distance < 1200)
  {
    right = {true, distance};
  }
  Serial.print("Can i move forward on the right?");
  if (right.resp)
  {
    Serial.print(" Yes");
  }

  else
  {
    Serial.print(" No");
  }

  Serial.println();
  return right;
}
