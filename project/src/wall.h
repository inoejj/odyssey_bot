#ifndef __WALL_AGENT__H
#define __WALL_AGENT__H 

#include "enviro.h"

using namespace enviro;

class wallController : public Process, public AgentInterface {

    public:
    wallController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class wall : public Agent {
    public:
    wall(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    wallController c;
};

DECLARE_INTERFACE(wall)

#endif