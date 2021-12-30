void obstacle()
{
  Serial.println("Obstacle Mode");

  //////Stop and Move Back
  if (cm < 30 and cm > 20)
  {
    stop_moving();
    move_backward();
    return;
  }

  int r  = random(100);

  //////Stop and Turn
  if (cm <= 20)
  {
    stop_moving();
    turn(r);
    return;
  }

  ///Turn
  if (cm < 50 and cm > 30)
  {
    turn(r);
    return;
  }

  ///Move Forward
  if (cm >= 100)
  {
    move_forward();
    return;
  }

}

void turn(int rand_no)
{
  if (rand_no % 2 == 0)
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
