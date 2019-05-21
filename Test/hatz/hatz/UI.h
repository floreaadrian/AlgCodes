#pragma once
#include "Controller.h"

class UI
{
private:
    Controller controller;
    
public:
    UI(Controller controller);
    
    void printMenu();
    
    void run();
    
    ~UI() {}
    
    
};
