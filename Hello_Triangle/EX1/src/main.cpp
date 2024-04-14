// Try to draw 2 triangles next to each other 
// using glDrawArrays by adding more vertices to your data

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Def.h"
#include "GameWindow.h"
#include "shader/ProgramShader.h"
#include "shader/VBO.h"
#include "shader/VAO.h"

float verticies[] = 
{
    // First triangle
    -0.5f, 0.25f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.25f, 0.25f, 0.0f,
    // Second triangle
    0.25f, 0.25f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    0.25f, -0.5f, 0.0f
};

int main()
{
    
    GameWindow *window = new GameWindow;
    window->initWindow(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_TITLE, NULL, NULL);

    ProgramShader program(PATH_VERTEX_SOURCE, PATH_FRAGMENT_SOURCES);
    VAO vao;
    vao.Bind();
    VBO vbo(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    vao.Link(vbo, 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    
    vao.UnBind();
    vbo.UnBind();


    while(!glfwWindowShouldClose(window->window))
    {
        glClearColor(0.0f, 0.0f, 0.1f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        program.Active();    
        vao.Bind();
        glDrawArrays(GL_TRIANGLES, 0, 6);

        glfwSwapBuffers(window->window);
        glfwPollEvents();
    }

    vao.Delete();
    vbo.Delete();
    program.Delete();
    window->destroyWindow();

    delete window; window = NULL;
    return 0;
}