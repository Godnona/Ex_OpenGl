#pragma once
#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include "../Def.h"

std::string getSource(const char* fileName);

class ShaderProgram
{
private:
    /* data */
public:
    GLuint id;
    ShaderProgram(const char* vertexPath, const char* fragmentPath);
    
    void use();
    void del();

};


#endif // SHADERPROGRAM_H