#include "window.h"

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLFWwindow* Window::window;

int Window::init(int width, int height, const std::string& title)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (window == nullptr)
    {
        std::cerr << "Failed to create main window." << std::endl;
        return -1;
    }
    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, width, height);

    return 0;
}

void Window::destroy()
{
    glfwDestroyWindow(window);
}

void Window::terminate()
{
    glfwTerminate();
}

bool Window::isShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::setShouldClose(bool close)
{
    glfwSetWindowShouldClose(window, close);
}

void Window::swapBuffers()
{
    glfwSwapBuffers(window);
}
