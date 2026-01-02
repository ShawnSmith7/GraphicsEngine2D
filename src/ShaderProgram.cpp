#include "pch.h"

#ifndef SRC_DIR
#define SRC_DIR "./"
#endif

#include "ShaderProgram.h"

ShaderProgram::ShaderProgram(const char* vertexShaderFileName, const char* fragmentShaderFileName) :
    ID(glCreateProgram()) {
    unsigned int vertexShader = compileShader(vertexShaderFileName, GL_VERTEX_SHADER);
    unsigned int fragmentShader = compileShader(fragmentShaderFileName, GL_FRAGMENT_SHADER);
    
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    
    int success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << '\n';
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(ID);
}

void ShaderProgram::use() const {
    glUseProgram(ID);
}

void ShaderProgram::setVec4(const char* name, const glm::vec4& value) const {
    glUniform4fv(glGetUniformLocation(ID, name), 1, glm::value_ptr(value));
}

void ShaderProgram::setMat4(const char* name, const glm::mat4& value) const {
    glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));
}

std::string ShaderProgram::fileNameToString(const std::string& fileName) {
    std::string filePath = SRC_DIR + fileName;
    std::ifstream file(filePath);
    if (!file.is_open())
        std::cerr <<"Failed to open " << filePath << '\n';
    
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int ShaderProgram::compileShader(const char* fileName, GLenum type) {
    std::string shaderString = fileNameToString(fileName);
    const char* shaderCString = shaderString.c_str();

    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderCString, 0);
    glCompileShader(shader);

    int success;
    char infoLog[512];
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if(!success) {
        const char* typeString;
        switch (type) {
            case GL_VERTEX_SHADER:
                typeString = "VERTEX::";
                break;
            case GL_FRAGMENT_SHADER:
                typeString = "FRAGMENT::";
                break;
            default:
                typeString = "";
        }

        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::" << typeString << "COMPILATION_FAILED\n" << infoLog << '\n';
    }

    return shader;
}

std::ostream& operator<<(std::ostream& os, const ShaderProgram& shaderProgram) {
    return os
        << "{ ID = " << shaderProgram.ID << " }";
}