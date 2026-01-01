#include "pch.h"
#include "Window.h"
#include "RoundThickLine.h"
#include "ThickPolyline.h"
#include "ShaderProgram.h"

void processInput(GLFWwindow* window);

int main() {
    Window window(1280, 800, "GraphicsEngine2D");

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    glm::vec4 coolColor(1.0f, 0.5f, 0.2f, 1.0f);

    SemiCircle semiCircle(glm::vec2(200.0f), 100.0f, coolColor, 2.0f * std::numbers::pi / 3.0f);

    std::cout << semiCircle << '\n';

    std::vector<Drawable*> drawables{ &semiCircle };

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    window.render([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 model(1.0f);
        shaderProgram.setMat4("projection", projection);
        shaderProgram.setMat4("view", view);
        shaderProgram.setMat4("model", model);
        for (Drawable* drawable : drawables)
            drawable->draw(shaderProgram);
    });

    std::cout << semiCircle << '\n';
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}