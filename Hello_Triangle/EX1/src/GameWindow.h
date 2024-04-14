#pragma once
#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Def.h"

class GameWindow
{
    private:
        
    public:
        GLFWwindow *window;
        GameWindow();
        ~GameWindow();
        void initWindow(const int &width, const int &height, const char* title, GLFWmonitor *monitor, GLFWwindow *share);
        void destroyWindow();
};

#endif // GAMEWINDOW_H