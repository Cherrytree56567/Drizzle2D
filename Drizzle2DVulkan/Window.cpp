#include "Window.h"

void Window::CreateWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
}

bool Window::Mainloop() {
    if (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        return false;
    } else {
        return true;
    }
}

void Window::CloseWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}
