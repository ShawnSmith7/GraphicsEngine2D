#include "Window.h"
#include "ShaderProgram.h"

void processInput(GLFWwindow* window);

int main() {
    Window window(1280, 800, "GraphicsEngine2D");

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    float vertices[] = {
        -0.5f, 0.5f,
        -0.5f, -0.5f,
        0.5f, -0.5f,
        0.5f, 0.5f
    };

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    window.render([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    });
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}