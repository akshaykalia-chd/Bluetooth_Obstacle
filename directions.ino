void stop_moving()
{
  if (not debug)
  {
    digitalWrite(motor1, LOW); //Stop
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, LOW);
  }
  delay(500);
}

void move_forward()
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);//9
    digitalWrite(motor2, HIGH);//10
    digitalWrite(motor3, LOW);//12
    digitalWrite(motor4, HIGH);//11
  }
  delay(500);
}

void move_backward()
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH); //9//Move Backword
    digitalWrite(motor2, LOW);  //10
    digitalWrite(motor3, HIGH); //12
    digitalWrite(motor4, LOW);  //11
  }
  delay(300);
}

void turn_right()
{
  if (not debug)
  {
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, HIGH);
    digitalWrite(motor3, HIGH);
    digitalWrite(motor4, LOW);
  }
  delay(300);
}

void turn_left()
{
  if (not debug)
  {
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, LOW);
    digitalWrite(motor3, LOW);
    digitalWrite(motor4, HIGH);
  }
  delay(300);
}

void un_stuck(int r)
{
  if (not debug)
  {
    stop_moving();
    if (loop_count == 1)
    {
      turn_right();
      return;
    }
    
    if (loop_count == 2)
    {
      turn_left();
      return;
    }
    
    if (loop_count == 3)
    {
      move_backward();
      return;
    }
    
    if (loop_count == 4)
    {
      move_forward();
      return;
    }
  }  
}
