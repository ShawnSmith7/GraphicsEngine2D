#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <stdexcept>
#include <functional>

class Window {
    public:
        Window(int width = 1280, int height = 800, const char* title = "Window");
        ~Window();

        GLFWwindow* get() const;
        int getWidth() const;
        int getHeight() const;

        void render(const std::function<void()>& renderCallback) const;
    private:
        GLFWwindow* window;
        int width, height;
        const char* title;

        static GLFWframebuffersizefun framebufferSizeCallback;
};