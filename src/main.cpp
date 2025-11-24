#include "Window.h"

void processInput(GLFWwindow* window);

int main() {
    Window window(1280, 800, "GraphicsEngine2D");

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    window.render([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);
    });
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}