#ifndef __BOX2_AGENT__H
#define __BOX2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class box2Controller : public Process, public AgentInterface {

    public:
    box2Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class box2 : public Agent {
    public:
    box2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    box2Controller c;
};

DECLARE_INTERFACE(box2)

#endif