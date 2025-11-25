#include "Window.h"
#include "ShaderProgram.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

// #include <glm/glm.hpp>
// #include <glm/gtc/matrix_transform.hpp>
// #include <glm/gtc/type_ptr.hpp>

void processInput(GLFWwindow* window);

int main() {
    Window window(1280, 800, "GraphicsEngine2D");

    VertexArray vertexArray;
    vertexArray.bind();

    float vertices[] = {
        100.0f, 100.0f,
        100.0f, 200.0f,
        200.0f, 200.0f,
        200.0f, 100.0f
    };

    VertexBuffer vertexBuffer;
    vertexBuffer.bind();
    vertexBuffer.setData(vertices, GL_STATIC_DRAW);

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    IndexBuffer indexBuffer;
    indexBuffer.bind();
    indexBuffer.setData(indices, GL_STATIC_DRAW);

    vertexArray.enableAttribute(0);
    vertexArray.setAttributePointer(0, 2, GL_FLOAT, false, 2 * sizeof(float), 0);

    glm::vec4 coolColor(1.0f, 0.5f, 0.2f, 1.0f);

    ShaderProgram shaderProgram("vertex.shader", "fragment.shader");
    shaderProgram.use();

    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    window.render([&]() {
        processInput(window.get());

        glClear(GL_COLOR_BUFFER_BIT);

        shaderProgram.setVec4("color", coolColor);
        glm::mat4 projection = glm::ortho(0.0f, (float)window.getWidth(), (float)window.getHeight(), 0.0f, -1.0f, 1.0f);
        glm::mat4 view(1.0f);
        glm::mat4 model(1.0f);
        glm::mat4 transform = projection * view * model;
        shaderProgram.setMat4("transform", transform);

        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    });
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}