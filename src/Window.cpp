#include "Window.h"

Window::Window(int width, int height, const char* title) :
    width(width), height(height), title(title) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, title, 0, 0);
    if (window == 0) {
        glfwTerminate();
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glfwSetWindowUserPointer(window, this);

    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
}

Window::~Window() {
    glfwDestroyWindow(window);
}

GLFWwindow* Window::get() const {
    return window;
}

void Window::render(const std::function<void()>& renderCallback) const {
    while(!glfwWindowShouldClose(window)) {
        renderCallback();
        glfwSwapBuffers(window);
        glfwPollEvents();    
    }
}

GLFWframebuffersizefun Window::framebufferSizeCallback = [](GLFWwindow* window, int width, int height) {
    Window* windowPtr = static_cast<Window*>(glfwGetWindowUserPointer(window));
    windowPtr->width = width;
    windowPtr->height = height;
    glViewport(0, 0, width, height);
};