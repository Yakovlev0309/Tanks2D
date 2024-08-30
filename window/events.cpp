#include "events.h"
#include "window.h"

#include <GLFW/glfw3.h>

bool* Events::keys;
unsigned int* Events::frames;
unsigned int Events::current;

#define MOUSE_BUTTONS_OFFSET 1024

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        Events::keys[key] = true;
        Events::frames[key] = Events::current;
    }
    else if (action == GLFW_RELEASE)
    {
        Events::keys[key] = false;
        Events::frames[key] = Events::current;
    }
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (action == GLFW_PRESS)
    {
        Events::keys[MOUSE_BUTTONS_OFFSET + button] = true;
        Events::frames[MOUSE_BUTTONS_OFFSET + button] = Events::current;
    }
    else if (action == GLFW_RELEASE)
    {
        Events::keys[MOUSE_BUTTONS_OFFSET + button] = false;
        Events::frames[MOUSE_BUTTONS_OFFSET + button] = Events::current;
    }
}

int Events::init()
{
    GLFWwindow* window = Window::window;
    keys = new bool[1032];
    frames = new unsigned int[1032];
    current = 0;

    std::fill(keys, keys + 1032, false);
    std::fill(frames, frames + 1032, 0);

    glfwSetKeyCallback(window, key_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    return 0;
}

void Events::poll()
{
    current++;
    glfwPollEvents();
}

bool Events::pressed(int keycode)
{
    if (keycode < 0 || keycode >= MOUSE_BUTTONS_OFFSET)
    {
        return false;
    }
    return keys[keycode];
}

bool Events::jpressed(int keycode)
{
    if (keycode < 0 || keycode >= MOUSE_BUTTONS_OFFSET)
    {
        return false;
    }
    return keys[keycode] && frames[keycode] == current;
}

bool Events::clicked(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button];
}

bool Events::jclicked(int button)
{
    return keys[MOUSE_BUTTONS_OFFSET + button] && frames[MOUSE_BUTTONS_OFFSET + button] == current;
}
