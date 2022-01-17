#ifndef OBSTACLE_H
#define OBSTACLE_H
#include <Arduino.h>
#include "Directions.h"
#include "CanImove.h"

class Obstacle
{
private:
    outcome canImoveForward;
    outcome canImoveLeft;
    outcome canImoveRight;
    bool am_i_stuck();
    void un_stuck();    
    String motor_state;  
    int count_call_un_stuck;
    
    

public:
    bool _debug;
    bool stuck;
    int _step_size;
    int _step_size_look;
    int _stop_distance;
    int loop_count;
    int turns;
    int look_backs;
    int move_forwards;
    String last_action;
    Obstacle(bool debug, int step_size, int step_size_look, int stop_distance);
    void start_moving();
    void print_data();
    void set_debug();      
};

#endif