#pragma once

#include <glad/glad.h>

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#ifndef SRC_DIR
#define SRC_DIR "./"
#endif

class ShaderProgram {
    public:
        ShaderProgram(const char* vertexShaderFileName, const char* fragmentShaderFileName);
        ~ShaderProgram();

        void use() const;
    private:
        unsigned int ID;

        static std::string fileNameToString(const std::string& fileName);
        static unsigned int compileShader(const char* fileName, GLenum type);
};