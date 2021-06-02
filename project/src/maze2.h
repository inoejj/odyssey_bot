#ifndef __MAZE2_AGENT__H
#define __MAZE2_AGENT__H 

#include "enviro.h"

using namespace enviro;

class maze2Controller : public Process, public AgentInterface {

    public:
    maze2Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class maze2 : public Agent {
    public:
    maze2(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    maze2Controller c;
};

DECLARE_INTERFACE(maze2)

#endif