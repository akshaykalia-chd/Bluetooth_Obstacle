#include "Stuck.h"

Stuck::Stuck(bool _debug, int _stop_distance, int _step_size_look, uint8_t motor1, uint8_t motor2, uint8_t motor3,
             uint8_t motor4, uint8_t ENABLEpin_1, uint8_t ENABLEpin_2, uint8_t trigPin,
             uint8_t echoPin) : CanImove(_stop_distance, motor1, motor2, motor3, motor4, ENABLEpin_1, ENABLEpin_2, trigPin, echoPin)
{
    eprom_val = EEPROM.read(1);
    step_size = (eprom_val * 10) + 100;
    debug = _debug;
    step_size_look = _step_size_look;
}

bool Stuck::am_i_stuck()
{
    if (move_forwards < 2)
    {
        return true;
    }
    return false;
}

String Stuck::un_stuck()
{
    long previous_dist_to_obj = dist_to_obj;
    bool dist_to_obj_increased = false;
    count_call_un_stuck += 1;
    if (count_call_un_stuck == 1)
    {
        turn_left(step_size, debug);
        stop_moving(step_size, debug);
        canImoveForward = can_i_move_forward();
        dist_to_obj_increased = dist_to_obj > previous_dist_to_obj;
        previous_dist_to_obj = dist_to_obj;
        if (canImoveForward)
        {
            stuck = false;            
        }
        else if (dist_to_obj_increased)
        {
           turn_left(step_size, debug);
           stop_moving(step_size, debug);
           canImoveForward = can_i_move_forward();
           dist_to_obj_increased = dist_to_obj > previous_dist_to_obj;
           previous_dist_to_obj = dist_to_obj;
           if (dist_to_obj_increased)
           {
             stuck = false;     
           }
           else
           {
               turn_right(step_size, debug);
               stop_moving(step_size, debug);
               turn_right(step_size, debug);
               stop_moving(step_size, debug);
           }
        }
     return "S01";                     
    }
    if (count_call_un_stuck == 2)
    {

        turn_right(step_size, debug);
        stop_moving(step_size, debug);
        canImoveForward = can_i_move_forward();
        dist_to_obj_increased = dist_to_obj > previous_dist_to_obj;
        previous_dist_to_obj = dist_to_obj;
        if (canImoveForward)
        {
            stuck = false;            
        }
        else if (dist_to_obj_increased)
        {
            turn_right(step_size, debug);
            stop_moving(step_size, debug);
            canImoveForward = can_i_move_forward();
            dist_to_obj_increased = dist_to_obj > previous_dist_to_obj;
            previous_dist_to_obj = dist_to_obj;
            if (dist_to_obj_increased)
            {
               stuck = false;  
            }
            else
            {
                turn_left(step_size, debug);
                stop_moving(step_size, debug);
                turn_left(step_size, debug);
                stop_moving(step_size, debug);            
            }
        }      
     return "S02";
    }
    if (count_call_un_stuck == 3)
    {
        look_back(step_size_look, debug);
        stop_moving(step_size, debug);
        canImoveForward = can_i_move_forward();
        if (canImoveForward)
        {
            stuck = false;            
        }
        look_back(step_size_look, debug);
        stop_moving(step_size, debug);
     return "S03";
    }
    else
    {        
        count_call_un_stuck = 0;                
        return "S04";
    }    
}