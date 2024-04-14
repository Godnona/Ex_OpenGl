#include "VAO.h"

VAO::VAO()
{
    glGenVertexArrays(1, &vao);
}

void VAO::Link(VBO vbo, GLuint location, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void* pointer)
{
    vbo.Bind();
    glVertexAttribPointer(location, size, type, normalized, stride, pointer);
    glEnableVertexAttribArray(location);
    vbo.UnBind();
}

void VAO::Bind()
{
    glBindVertexArray(vao);
}

void VAO::UnBind()
{
    glBindVertexArray(0);
}

void VAO::Delete()
{
    glDeleteVertexArrays(1, &vao);
}
