#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Def.h"

class GameWindow
{
private:
    
public:
    GLFWwindow* id;
    GameWindow();
    ~GameWindow();

    void init(const int &w, const int &h, const char* title, GLFWmonitor *monitor, GLFWwindow *share);
    void del();

};


#endif // GAMEWINDOW_H