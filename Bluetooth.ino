void bluetooth()
{

  Serial.println("Bluetooth Mode");
  bool input_recived = false;
  bool act = false;

  if (Serial.available() > 0)
  {
    val_recived = Serial.read();
    Serial.println(val_recived);
    input_recived = true;
  }

  act = (val_recived != current_val) or input_recived ;

  if (val_recived == 56) // Enable obstacle mode
  {
    obstacle();
    return;
  }

  if ( val_recived == 49 and cm >= 100)  // Forward
  {
    move_forward();
    return;
  }

  if (val_recived == 50 and act) // Backward
  {
    move_backward();
    stop_moving();
    current_val = val_recived;
    return;
  }

  if (val_recived == 52 and act)//Left
  {
    turn_left();
    stop_moving();
    current_val = val_recived;
    return;
  }

  if (val_recived == 51 and act) //Right
  {
    turn_right();
    stop_moving();
    current_val = val_recived;
    return;
  }

  else
  {
    current_val = val_recived;
    stop_moving();
    return;
  }
}
