#pragma once

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

        void setVec4(const char* name, const glm::vec4& value) const;
        void setMat4(const char* name, const glm::mat4& value) const;
    private:
        unsigned int ID;

        static std::string fileNameToString(const std::string& fileName);
        static unsigned int compileShader(const char* fileName, GLenum type);
};