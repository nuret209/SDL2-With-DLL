#include "Window.h"
Window::Window(int x, int y, std::string baslik) : x(x), y(y), title(baslik)
{
}

void Window::init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_SOFTWARE);
}

bool Window::getQuit()
{
    return quit;
}

void Window::handleCloseEvent()
{
    if (isEvent(SDL_QUIT))
        quit = true;
}

bool Window::isEvent(SDL_EventType type)
{
    while (SDL_PollEvent(&mYevent)){
        if (mYevent.type == type)
            return true;
    }
    return false;
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}