#pragma once
#ifndef VBO_H
#define VBO_H

#include "../Def.h"

class VBO
{
private:
    /* data */
public:
    GLuint vbo;

    VBO(GLenum target, GLsizeiptr size, const void *data, GLenum usage);
    
    void Bind();
    void UnBind();
    void Delete();

};


#endif // VBO_H