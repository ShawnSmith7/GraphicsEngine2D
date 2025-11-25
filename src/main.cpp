#include "Window.h"
#include "Rect.h"
#include "Circle.h"

void processInput(GLFWwindow* window);

int main() {
    Window window(1280, 800, "GraphicsEngine2D");

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    glm::vec4 coolColor(1.0f, 0.5f, 0.2f, 1.0f);

    Rect rect(glm::vec2(200.0f), glm::vec2(200.0f), coolColor);
    Circle circle(glm::vec2(640.0f, 300.0f), 100.0f, coolColor);

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    window.render([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);

        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 model(1.0f);
        glm::mat4 transform = projection * view * model;
        shaderProgram.setMat4("transform", transform);
        rect.draw(shaderProgram);
        circle.draw(shaderProgram);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    });
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}