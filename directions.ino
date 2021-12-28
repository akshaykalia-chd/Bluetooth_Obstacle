void move_forward()
{
  digitalWrite(motor1, LOW);//9
  digitalWrite(motor2, HIGH);//10
  digitalWrite(motor3, LOW);//12
  digitalWrite(motor4, HIGH);//11
  delay(400);
}

void move_backward()
{
  digitalWrite(motor1, HIGH); //9//Move Backword
  digitalWrite(motor2, LOW);  //10
  digitalWrite(motor3, HIGH); //12
  digitalWrite(motor4, LOW);  //11
  delay(400);
}

void stop_moving()
{
  digitalWrite(motor1, LOW); //Stop
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
  delay(500);
}

void turn_left()
{
  digitalWrite(motor1, LOW);
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);
  digitalWrite(motor4, LOW);
  delay(500);
}

void turn_right()
{
  digitalWrite(motor1, HIGH);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, HIGH);
  delay(500);
}
