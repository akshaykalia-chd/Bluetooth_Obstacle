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

  if (val_recived == 55)
  {
    current_val = val_recived;
    stop_moving();
    return;
  }

  if (cm < 100 and val_recived == 49)
  {
    stop_moving();
    return;
  }

  if (val_recived == 53) // Enable obstacle mode
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

  if (val_recived == 52 and act) //Right
  {
    turn_right();
    stop_moving();
    current_val = val_recived;
    return;
  }

  if (val_recived == 51 and act) //Left
  {
    turn_left();
    stop_moving();
    current_val = val_recived;
    return;
  }

  if (val_recived == 54 and act) //increment step size
  {
    step_size = step_size + 10;
    eprom_val = eprom_val + 1;
    Serial.print("New Step Size:");
    Serial.print(step_size);
    Serial.println();
    Serial.print("New eprom_val:");
    Serial.print(eprom_val);
    Serial.println();    
    current_val = val_recived;
    return;
  }

  if (val_recived == 56 and act)  //decrement step size
  {
    if (step_size > 100)
    {
      step_size = step_size - 10;
      eprom_val = eprom_val - 1;
      Serial.print("New Step Size:");
      Serial.print(step_size);
      Serial.println();
      Serial.print("New eprom_val:");
      Serial.print(eprom_val);
      Serial.println();      
    }
    else
    {
      step_size = 100;
    }
    current_val = val_recived;
    return;
  }

  if (val_recived == 57 and act) //persist step size
  {
    if (EEPROM.read(1) != eprom_val)
    {
      EEPROM.write(1, eprom_val);
      Serial.print("New value writen to EEPROM:");
      Serial.print(eprom_val);
      Serial.println();
    }
    else
    {
      Serial.println("Not updating, New Value is same as Existing Value");
    }
    current_val = val_recived;   
    return;
  }
}
