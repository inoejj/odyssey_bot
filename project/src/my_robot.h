#ifndef __MY_ROBOT_AGENT__H
#define __MY_ROBOT_AGENT__H 

#include <string>
#include <math.h>
#include "enviro.h"

using namespace enviro;

class MovingForward : public State, public AgentInterface {
    public:
        void entry(const Event& e) {}
        void during() { 
            track_velocity(15, 0);
            if ( sensor_value(0) < 40 ) {
                emit(Event(tick_name));
            }     
        }
        void exit(const Event& e) {}
        void set_tick_name(std::string s) { tick_name = s; }
        std::string tick_name;
    };

class Rotating : public State, public AgentInterface {
    public:

    void entry(const Event& e) { 
        rate = rand() % 2 == 0 ? -2: 2;
        decorate("<circle x='-5' y='5' r='5' style='fill: blue'></circle>");
        label(sensor_reflection_type(0), 20, 5);
     }
    void during() {
        track_velocity(0,rate);
        if ( sensor_value(0) > 140 ) {
                emit(Event(tick_name));
            }      
        
         }
    void exit(const Event& e) {
        decorate(""); 
        clear_label();
    }
    double rate;
    void set_tick_name(std::string s) { tick_name = s; }
    std::string tick_name; 
};

class MyRobotController : public StateMachine, public AgentInterface {

    public:
    MyRobotController() : StateMachine() {

        set_initial(moving_forward);
            tick_name = "tick_" + std::to_string(rand()%1000); // use an agent specific generated 
                                                               // event name in case there are 
                                                               // multiple instances of this class
            add_transition(tick_name, moving_forward, rotating);
            add_transition(tick_name, rotating, moving_forward);
            moving_forward.set_tick_name(tick_name);
            rotating.set_tick_name(tick_name);

    }
    // will try to decelerate before it collides
    void init() {
            watch("button_click", [&](Event& e) {
                std::cout << e.value() << "\n";
                e.stop_propagation();
            });
            StateMachine::init();
        }

    void update() {

        if ( rand() % 100 <= 5 ) {
                emit(Event(tick_name));
            }   
            StateMachine::update();
    }

    MovingForward moving_forward;
    Rotating rotating;
    std::string tick_name;



};

class MyRobot : public Agent {
    public:
    MyRobot(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    MyRobotController c;
};

DECLARE_INTERFACE(MyRobot)

#endif