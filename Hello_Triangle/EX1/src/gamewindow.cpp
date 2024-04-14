#include "GameWindow.h"


GameWindow::GameWindow(/* args */)
{
    std::cout << "Init GameWindow" << std::endl;
}

GameWindow::~GameWindow()
{
    std::cout << "Destroy GameWindow" << std::endl;
}

void GameWindow::initWindow(const int &width, const int &height, const char* title, GLFWmonitor *monitor, GLFWwindow *share)
{
    if(!glfwInit())
        std::cout << "Error init glfw !" << std::endl;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, monitor, share);
    if(window == NULL){
        std::cout << "Error create window !" << std::endl;
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

}

void GameWindow::destroyWindow()
{
    glfwTerminate();
}