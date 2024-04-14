#include "ShaderProgram.h"

std::string getSource(const char* fileName)
{
    std::ifstream in(fileName, std::ios::binary);
    if(in)
    {
        std::string src;
        in.seekg(0, in.end);
        src.resize(in.tellg());
        in.seekg(0, in.beg);
        in.read(&src[0], src.size());
        in.close();

        return src;
    }
    else
        return "Error load file Source !";
}

ShaderProgram::ShaderProgram(const char* vertexPath, const char* fragmentPath)
{
    std::string getVertex = getSource(vertexPath);
    std::string getFragment = getSource(fragmentPath);

    std::string errorV = getVertex;
    std::string errorF = getFragment;

    if(getVertex == errorV || getFragment == errorF)
    {
        std::cout << "Use backup path. If it don't run...\n";
        std::cout << "Put Folder game in C:/Users/chinh/G_Opengl/HelloTriangle/EX2/build/ !!" << std::endl; 
        getVertex = getSource(PATH_VERTEX_SOURCE_BACKUP);
        getFragment = getSource(PATH_FRAGMENT_SOURCE_BACKUP);
    }

    const char* vertexSource = getVertex.c_str();
    const char* fragmentSource = getFragment.c_str();

    std::cout << vertexSource << "\n" << fragmentSource << std::endl;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    id = glCreateProgram();
    glAttachShader(id, vertexShader);
    glAttachShader(id, fragmentShader);
    glLinkProgram(id);
}

void ShaderProgram::use()
{
    glUseProgram(id);
}

void ShaderProgram::del()
{
    glDeleteProgram(id);
}