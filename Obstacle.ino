void obstacle()
{
  Serial.println("Obstacle Mode");
  int r  = random(10);   
  ///Move Forward
  if (cm >= 100)
  {
    move_forward();
    return;
  }

  ///Move backword
  if (cm <= 50)
  {
    move_backward();
    return;
  }

  ///Trun
  if (cm < 50 & cm > 30) 
  {
    if (r % 2 == 0)
    {
      turn_right();
      return;
    }
    else
    {
      turn_left();
      return;
    }    
  }
  
  //////Stop and Move Back
  if (cm < 30)
  {
    stop_moving();
    move_backward();
    return;    
  }

  //////Stop
  if (cm < 20)
  {
    stop_moving();
    if (r % 2 == 0)
    {
      turn_right();
      return;
    }
    else
    {
      turn_left();
      return;
    }

  }
}
