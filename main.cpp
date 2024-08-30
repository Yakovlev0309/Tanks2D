#include <iostream>

#include <glad/glad.h> // TODO убрать
#include <GLFW/glfw3.h> // TODO убрать

#include "window/window.h"
#include "window/events.h"

const int width = 1280;
const int height = 720;
const std::string title = "Tanks2D";

int main()
{
    int window_init = Window::init(width, height, title);
    if (window_init != 0)
    {
        return window_init;
    }

    int events_int = Events::init();
    if (events_int != 0)
    {
        return events_int;
    }

    glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
    while (!Window::isShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        Window::swapBuffers();
        Events::poll();
    }

    Window::destroy();
    Window::terminate();
    return 0;
}
