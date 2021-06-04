#ifndef __WALL2_AGENT__H
#define __WALL2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class wall2Controller : public Process, public AgentInterface {

    public:
    wall2Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class wall2 : public Agent {
    public:
    wall2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    wall2Controller c;
};

DECLARE_INTERFACE(wall2)

#endif