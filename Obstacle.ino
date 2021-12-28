void obstacle()
{
  Serial.println("Obstacle Mode");
  int r  = random(10);
  long cm ;
  cm = cal_distance();
  if (cm > 100)
  {
    move_forward();
  }
  if (cm < 50)
  {
    stop_moving();
    move_backward();
    stop_moving();
  }
  if (cm<50 & cm>30)
  {
    stop_moving();
    if (r % 2 == 0)
    {
      turn_right();
    }
    else
    {
      turn_left();
    }
    move_backward();
  }
  if (cm < 30)
  {
    stop_moving();
    move_backward();
    stop_moving();
  }
  if (cm < 20)
  {
    stop_moving();
    if (r % 2 == 0)
    {
      turn_right();
      turn_right();
    }
    else
    {
      turn_left();
      turn_left();
    }

  }
}
