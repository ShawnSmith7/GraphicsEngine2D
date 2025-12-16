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

    Rect rect(glm::vec2(320.0f, 266.7f), glm::vec2(200.0f), coolColor);
    Circle circle(glm::vec2(640.0f, 266.7f), 100.0f, coolColor);
    Line line(glm::vec2(880.0f, 166.7f), glm::vec2(1080.0f, 366.7f), 20.0f, coolColor);
    ThickLine thickLine(glm::vec2(220.0f, 433.3f), glm::vec2(420.0f, 633.3f), 20.0f, coolColor);
    thickLine.setPos1({0.0f, 0.0f});
    RoundThickLine roundThickLine(glm::vec2(540.0f, 433.3f), glm::vec2(740.0f, 633.3f), 20.0f, coolColor, 16, 16);
    SemiCircle semiCircle(glm::vec2(980.0f, 533.3f), 100.0f, coolColor, std::numbers::pi, 32);
    Polyline polyline({{100.0f, 100.0f}, {200.0f, 50.0f}, {300.0f, 100.0f}}, 20, coolColor);
    ThickPolyline thickPolyline({{500.0f, 50.0f}, {600.0f, 100.0f}, {700.0f, 50.0f}}, 20, coolColor);

    std::cout << polyline;

    std::vector<Drawable*> drawables = {
        &rect,
        &circle, 
        &line,
        &thickLine,
        &roundThickLine,
        &semiCircle,
        &polyline,
        &thickPolyline };

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
    
    glfwTerminate();
    return 0;
}

void processInput(GLFWwindow *window) {
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}