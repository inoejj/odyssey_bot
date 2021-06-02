#ifndef __MAZE1_AGENT__H
#define __MAZE1_AGENT__H 

#include "enviro.h"

using namespace enviro;

class maze1Controller : public Process, public AgentInterface {

    public:
    maze1Controller() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class maze1 : public Agent {
    public:
    maze1(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    maze1Controller c;
};

DECLARE_INTERFACE(maze1)

#endif