#ifndef __MAZE3_AGENT__H
#define __MAZE3_AGENT__H 

#include "enviro.h"

using namespace enviro;

class maze3Controller : public Process, public AgentInterface {

    public:
    maze3Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class maze3 : public Agent {
    public:
    maze3(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    maze3Controller c;
};

DECLARE_INTERFACE(maze3)

#endif