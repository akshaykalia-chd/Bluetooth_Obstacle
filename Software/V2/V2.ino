#include "Obstacle.h"

Obstacle bot(true, 300, 500,50);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  bot.print_data();
  bot.start_moving();
}
