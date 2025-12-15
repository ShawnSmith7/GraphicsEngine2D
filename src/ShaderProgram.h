#pragma once

#include <string>
#include <iosfwd>

#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>

#include <glad/glad.h>

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

        friend std::ostream& operator<<(std::ostream& os, const ShaderProgram& shaderProgram);
};

std::ostream& operator<<(std::ostream& os, const ShaderProgram& shaderProgram);