#pragma once
#ifndef VAO_H
#define VAO_H

#include "../Def.h"

class VAO
{
private:
    /* data */
public:
    GLuint id;
    VAO(/* args */);

    void bind();
    void link();
    void del();
};



#endif // VAO_H