#ifndef STUCK_H
#define STUCK_H
#include <Arduino.h>
#include "CanImove.h"
#include<EEPROM.h>

class Stuck : public CanImove
{
private:
    int count_call_un_stuck; 

public:    
    bool stuck;
    bool canImoveForward;
    bool canImoveLeft;
    bool canImoveRight;
    bool debug;
    int step_size;
    int step_size_look;
    int move_forwards;
    int eprom_val;


    Stuck(bool _debug,int _stop_distance,int _step_size_look, uint8_t motor1, uint8_t motor2, uint8_t motor3,
          uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin,
          uint8_t echoPin);
    bool am_i_stuck();
    String un_stuck();
};

#endif