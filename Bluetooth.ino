void bluetooth()
{  
  Serial.println("Bluetooth Mode");
  if (Serial.available() > 0)
  {
    val_recived = Serial.read();
    Serial.println(val_recived);
  }
  if (val_recived == 56) //Right
  {
    obstacle();
  }

  if ( val_recived == 49) // Forward
  {
    cm = cal_distance();
    if (cm > 100)
    {
      move_forward();
    }
    else
    {
      stop_moving();
    }
  }
  
  if (val_recived == 50) // Backward
  {
    stop_moving();
    if (val_recived != current_val)
    {
      current_val = val_recived;
      move_backward();
    }
  }
  else if (val_recived == 52) //Left
  {
    stop_moving();
    if (val_recived != current_val)
    {
      current_val = val_recived;
      turn_left();
    }
  }
  else if (val_recived == 51) //Right
  {
    stop_moving();
    if (val_recived != current_val)
    {
      current_val = val_recived;
      turn_right();
    }
  }  
  else
  {
    current_val = val_recived;
    stop_moving();
  }
}
