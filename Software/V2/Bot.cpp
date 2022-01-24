#include "Bot.h"

Bot::Bot(String mode, bool debug, int step_size_look, int stop_distance,
         uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4,
         uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin, uint8_t dip1,
         uint8_t dip2) : Bluetooth(mode, debug, step_size_look, stop_distance, motor1, motor2, motor3, motor4, ENABLEpin_1, ENABLEpin_2, trigPin, echoPin), ReadDip(dip1, dip2)
{
  cal_distance();
}

void Bot::read_mode()
{
  readmode = mode();
}

void Bot::set_mode_debug()
{
  read_mode();
  if (readmode == '1' | readmode == '4')
  {
    _debug = false;
    set_debug();
    if (readmode == '1')
    {
      _mode = "O";  //Obstacle
    }
    else
    {
      _mode = "B"; //Bluetooh
    }
    return;
  }
  if (readmode == '2' | readmode == '3')
  {
    _debug = true;
    set_debug();
    if (readmode == '2')
    {
      _mode = "BD"; //Bluetooh
    }
    else
    {
      _mode = "OD"; //Obstacle
    }
    return;
  }

}


void Bot::lets_go()
{  
  if (_mode == "B" | _mode == "BD") //Mode 2 Bebug
  {
    act_on_cmd(); //Bluetooh Control 
    return;
  }
  if (_mode == "O" | _mode == "OD") //Mode 3 Debug
  {
    start_moving(); //Auto 
    return;
  }
}
