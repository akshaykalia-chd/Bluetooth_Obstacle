void bluetooth(bool debug)
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
    stop_moving(debug);
    return;
  }

  if (distance < 40 and val_recived == 49)
  {
    stop_moving(debug);
    return;
  }

  if (val_recived == 53) // Enable obstacle mode
  {
    obstacle(debug);
    return;
  }

  if ( val_recived == 49 and distance > 40)  // Forward
  {
    move_forward(debug);
    return;
  }

  if (val_recived == 50 and act) // Backward
  {
    move_backward(debug);
    stop_moving(debug);
    current_val = val_recived;
    return;
  }

  if (val_recived == 52 and act) //Right
  {
    turn_right(debug);
    stop_moving(debug);
    current_val = val_recived;
    return;
  }

  if (val_recived == 51 and act) //Left
  {
    turn_left(debug);
    stop_moving(debug);
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
    if (debug)
    {
      delay(2000);
    }
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
      if (debug)
      {
        delay(2000);
      }
    }
    else
    {
      step_size = 100;
      eprom_val = 0;
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
    if (debug)
    {
      delay(2000);
    }
    current_val = val_recived;
    return;
  }
  if (val_recived == 48 and act) //reset stepsize
  {
    step_size = 100;
    eprom_val = 0;
    Serial.print("New Step Size:");
    Serial.print(step_size);
    Serial.println();
    Serial.print("New eprom_val:");
    Serial.print(eprom_val);
    Serial.println();
    if (debug)
    {
      delay(2000);
    }
    current_val = val_recived;
    return;
  }
}
