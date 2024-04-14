#pragma once
#ifndef PROGRAM_SHADER_H
#define PROGRAM_SHADER_H

#include "../Def.h"

class ProgramShader
{
private:
    /* data */
public:
    GLuint programShader;

    ProgramShader(const char* vertexPath, const char* fragmentPath);

    void Active();
    void Delete();

};


#endif // PROGRAM_SHADER_H