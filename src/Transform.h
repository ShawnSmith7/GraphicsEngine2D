#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Transform {
    public:
        Transform(const glm::vec2& translation = glm::vec2(0.0f),
            const glm::vec2& scaling = glm::vec2(1.0f),
            float rotation = 0.0f, const glm::vec2& origin = glm::vec2(0.0f));

        glm::vec2 getTranslation() const;
        glm::vec2 getScaling() const;
        float getRotation() const;
        glm::vec2 getOrigin() const;
        glm::mat4 getMatrix();

        void setTranslation(const glm::vec2& translation);
        void setScaling(const glm::vec2& scaling);
        void setRotation(float rotation);
        void setOrigin(const glm::vec2& origin);

        void translate(const glm::vec2& translation);
        void scale(const glm::vec2& scale);
        void rotate(float rotation);
    private:
        glm::vec2 translation, scaling, origin;
        float rotation;
        glm::mat4 matrix;
        bool dirty;

        void updateMatrix();
};