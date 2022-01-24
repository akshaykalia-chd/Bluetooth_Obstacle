#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <Arduino.h>
#include <EEPROM.h>
#include "Stuck.h"


class Obstacle : public Stuck
{
private:   


public:
    int cmd;    
    String mode;       
    int loop_count;
    int turns;
    int look_backs;      
    String last_action;
    String motor_state;
    Obstacle(String mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1,
             uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin);
    void start_moving();
    void print_data();
    void set_debug();
};

#endif