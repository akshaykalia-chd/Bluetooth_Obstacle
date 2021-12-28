void obstacle()
{
  Serial.println("Obstacle Mode");
  int r  = random(10);
  long cm ;
  cm = cal_distance();
  ///Move Forward
  if (cm > 100)
  {
    move_forward();
  }

  ///Move Forward
  if (cm < 50)
  {
    move_backward();
  }

  ///Trun and Move Back
  if (cm<50 & cm>30)  {

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
  
  //////Move Back
  if (cm < 30)
  {
    move_backward();
    cm = cal_distance();
    if (cm < 30)
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

    }
  }

  //////Stop
  if (cm < 20)
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

  }
}
