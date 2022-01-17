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
    String disable_motors();
    int _stop_distance;
    int count_call_un_stuck;

public:
    bool _debug;
    int _step_size;
    int _step_size_look;
    bool stuck;
    String last_action;
    int loop_count;
    int turns;
    int look_backs;
    int move_forwards;
    Obstacle(bool debug, int step_size, int step_size_look, int stop_distance);
    void start_moving();
    void print_data();
};

#endif