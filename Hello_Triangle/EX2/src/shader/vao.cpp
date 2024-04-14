#include "VAO.h"


VAO::VAO()
{
    glGenVertexArrays();
}

void VAO::bind()
{
    glBindVertexArray(id);
}