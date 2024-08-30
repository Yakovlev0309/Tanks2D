#ifndef WINDOW_EVENTS_H
#define WINDOW_EVENTS_H

class Events
{
public:
    static bool* keys;
    static unsigned int* frames;
    static unsigned int current;

    static int init();
    static void poll();

    // keyboard button pressed
    static bool pressed(int keycode);
    static bool jpressed(int keycode);

    // mouse button clicked
    static bool clicked(int button);
    static bool jclicked(int button);
};

#endif // WINDOW_EVENTS_H
