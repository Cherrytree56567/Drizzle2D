#include "Window.h"

Window::Window() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void Window::CreateWin() {
    if (!resizable) {
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    }
    window = glfwCreateWindow(800, 600, "Vulkan window", nullptr, nullptr);
    Render.InitRenderer(WindowTitle, window);
    glfwSetWindowUserPointer(window, &Render);
    glfwSetFramebufferSizeCallback(window, Render.framebufferResizeCallback);
}

bool Window::Mainloop() {
    if (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        Render.drawFrame();
        vkDeviceWaitIdle(Render.device);
        return false;
    } else {
        vkDeviceWaitIdle(Render.device);
        return true;
    }
}

void Window::CloseWindow() {
    Render.DestructRenderer();

    glfwDestroyWindow(window);

    glfwTerminate();
}
