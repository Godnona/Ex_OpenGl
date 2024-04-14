#include "VBO.H"

VBO::VBO(GLsizeiptr size, const void* data)
{
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
}

void VBO::unBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::del()
{
    glDeleteBuffers(1, &id);
}
