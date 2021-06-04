#ifndef __BOX_AGENT__H
#define __BOX_AGENT__H 

#include "enviro.h"

using namespace enviro;

class boxController : public Process, public AgentInterface {

    public:
    boxController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {}
    void stop() {}

};

class box : public Agent {
    public:
    box(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    boxController c;
};

DECLARE_INTERFACE(box)

#endif