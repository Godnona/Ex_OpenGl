#pragma once
#ifndef VBO_H
#define VBO_H

#include "../Def.h"

class VBO
{
private:
    /* data */
public:
    GLuint id;
    VBO(GLsizeiptr size, const void* data);
    
    void bind();
    void unBind();
    void del();

};



#endif // VBO_H