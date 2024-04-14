#include "GameWindow.h"

GameWindow::GameWindow(/* args */)
{
    
}

GameWindow::~GameWindow()
{
}

void GameWindow::init(const int &w, const int &h, const char* title, GLFWmonitor *monitor, GLFWwindow *share)
{
    if(!glfwInit())
        std::cout << "Initially glfw failed !" << std::endl;
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    id = glfwCreateWindow(w, h, title, monitor, share);
    if(id == NULL){
        std::cout << "Initially window failed !" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(id);

    gladLoadGL();
    glViewport(0, 0, w, h);

}

void GameWindow::del()
{
    glfwTerminate();
}

