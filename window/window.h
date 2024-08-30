#ifndef WINDOW_WINDOW_H
#define WINDOW_WINDOW_H

#include <string>

class GLFWwindow;

class Window
{
public:
    static GLFWwindow* window;

    static int init(int width, int height, const std::string& title);
    static void destroy();
    static void terminate();

    static bool isShouldClose();
    static void setShouldClose(bool close);

    static void swapBuffers();
};

#endif // WINDOW_WINDOW_H
