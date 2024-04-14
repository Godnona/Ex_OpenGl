#pragma once
#ifndef VAO_H
#define VAO_H

#include "../Def.h"
#include "VBO.h"

class VAO
{
private:
    /* data */
public:
    GLuint vao;

    VAO();

    void Link(VBO vbo, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer);
    void Bind();
    void UnBind();
    void Delete();

};


#endif // VAO_H