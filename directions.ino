void stop_moving()
{
  if (not debug)
  {
    last_action = 's';
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  }
  delay(step_size);
}

void move_forward()
{
  if (not debug)
  {
    last_action = 'f';
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11
  }
  delay(step_size);
}

void move_backward()
{
  if (not debug)
  {
    last_action = 'b';
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11
  }
  delay(step_size);
}

void turn_right()
{
  if (not debug)
  {
    last_action = 'r';
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  delay(step_size);
}

void turn_left()
{
  if (not debug)
  {
    last_action = 'l';
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  delay(step_size);
}

void un_stuck()
{
  stuck = false;
  stop_moving();
  int r  = random(100);
  if (last_action == 'f' or last_action == 'b')
  {
    if (r % 2 == 0 )
    {
      turn_left();
    }
    else {
      turn_right();
    }
  }
  if (last_action == 'r' or last_action == 'l' )
  {
    if (r % 2 == 0 )
    {
      move_forward();
    }
    else
    {
      move_backward();
    }
  }
}
