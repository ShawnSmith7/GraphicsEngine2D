#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
    public:
        Transform(const glm::vec2& pos = glm::vec2(0.0f),
            const glm::vec2& size = glm::vec2(1.0f),
            float rotation = 0.0f);

        void setPos(const glm::vec2& pos);
        void setSize(const glm::vec2& size);
        void setRotation(float rotation);

        glm::mat4 getMatrix();
    private:
        glm::vec2 pos, size;
        float rotation;
        glm::mat4 matrix;
        bool dirty;

        void updateMatrix();
};