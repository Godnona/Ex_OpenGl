// create the same 2 triangles using two different VAOs and VBOs
// for their data

#include "Def.h"
#include "GameWindow.h"
#include "shader/ShaderProgram.h"
#include "shader/VBO.h"

float vertices[] = {
    0.5f, 0.5f, 0.0f,
    0.5f, 0.0f, 0.0f,
   -0.5f, 0.0f, 0.0 
};

int main()
{

    GameWindow *window = new GameWindow;
    window->init(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, NULL, NULL);

    ShaderProgram *program = new ShaderProgram(PATH_VERTEX_SOURCE, PATH_FRAGMENT_SOURCE);
    
    VBO *vbo = new VBO(sizeof(vertices), vertices);

    while(!glfwWindowShouldClose(window->id))
    {
        glClearColor(0.8f, 0.9f, 0.9f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        program->use();

        glfwSwapBuffers(window->id);

        glfwPollEvents();
    }

    vbo->del();
    program->del();
    window->del();
    return 0;
}