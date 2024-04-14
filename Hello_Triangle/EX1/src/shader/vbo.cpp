#include "VBO.h"

VBO::VBO(GLenum target, GLsizeiptr size, const void *data, GLenum usage)
{
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage);
}

void VBO::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
}

void VBO::UnBind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete()
{
    glDeleteBuffers(1, &vbo);
}