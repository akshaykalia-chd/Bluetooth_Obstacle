#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <Arduino.h>
#include <EEPROM.h>
#include "CanImove.h"

class Obstacle : public CanImove
{
private:
    bool canImoveForward;
    bool canImoveLeft;
    bool canImoveRight;
    bool am_i_stuck();
    void un_stuck();
    int count_call_un_stuck;


public:
    int cmd;
    int eprom_val;
    char _mode;
    bool _debug;
    bool stuck;
    int _step_size;
    int _step_size_look;
    int loop_count;
    int turns;
    int look_backs;
    int move_forwards;    
    String last_action;
    String motor_state;
    Obstacle(char mode, bool debug, int step_size_look, int stop_distance, uint8_t motor1, uint8_t motor2, uint8_t motor3, uint8_t motor4, uint8_t ENABLEpin_1,
             uint8_t ENABLEpin_2, uint8_t trigPin, uint8_t echoPin);
    void start_moving();
    void print_data();
    void set_debug();
};

#endif