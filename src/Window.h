#pragma once

#include <functional>

struct GLFWwindow;
using GLFWframebuffersizefun = void(*)(GLFWwindow*, int, int);

#include <iosfwd>

class Window {
    public:
        Window(int width = 1280, int height = 800, const char* title = "Window");
        ~Window();

        GLFWwindow* get() const;
        int getWidth() const;
        int getHeight() const;
        const char* getTitle() const;

        void render(const std::function<void()>& renderCallback) const;
    private:
        GLFWwindow* window;
        int width, height;
        const char* title;

        static GLFWframebuffersizefun framebufferSizeCallback;
};

std::ostream& operator<<(std::ostream& os, const Window& window);