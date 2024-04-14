#include "ProgramShader.h"

std::string get_source(const char *fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    if(in)
    {
        std::string s;
        in.seekg(0, in.end);
        s.resize(in.tellg());
        in.seekg(0, in.beg);
        in.read(&s[0], s.size());
        in.close();

        return s;
    }
    else
        return "Error load file.glsl";
}

ProgramShader::ProgramShader(const char* vertexPath, const char* fragmentPath)
{
    std::string vertexSource = get_source(vertexPath);
    std::string fragmentSource = get_source(fragmentPath);

    const char* vertex = vertexSource.c_str();
    const char* fragment = fragmentSource.c_str();

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertex, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragment, NULL);
    glCompileShader(fragmentShader);

    programShader = glCreateProgram();
    glAttachShader(programShader, vertexShader);
    glAttachShader(programShader, fragmentShader);
    glLinkProgram(programShader);

}

void ProgramShader::Active()
{
    glUseProgram(programShader);
}

void ProgramShader::Delete()
{
    glDeleteProgram(programShader);
}