void obstacle(bool debug, int rand_no)
{
  Serial.println("Obstacle Mode");
  bool stuck = am_i_stuck();

  if (stuck)
  {
    stop_moving(debug);
    un_stuck(debug);
    stuck = false;
    return;
  } 

  //Stop and Turn
  if (cm < 20)
  {
    stop_moving(debug);
    turn(rand_no, debug);
    return;
  }

  //Stop and Move Back
  if (cm < 30 and cm > 20)
  {
    stop_moving(debug);
    move_backward(debug);
    return;
  }

  ///Turn
  if (cm < 50 and cm > 30)
  {
    turn(rand_no, debug);
    return;
  }

  ///Move Forward
  if (cm > 50)
  {
    move_forward(debug);
    return;
  }
}

void turn(int rand_no, bool debug)
{
  if (rand_no % 2 == 0)
  {
    turn_right(debug);
    return;
  }
  else
  {
    turn_left(debug);
    return;
  }
}
