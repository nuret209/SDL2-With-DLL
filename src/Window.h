
#ifndef  WINDOW_H
#define  WINDOW_H
#include <SDL2/SDL.h>
#include<iostream>
#if BUILDING_DLL
#define WINDOW __declspec(dllexport)
#else
#define WINDOW __declspec(dllimport)
#endif

class WINDOW Window
{
private:
    /* data */
    int x, y;
    std::string title;
    bool quit = false;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event mYevent;

public:
    Window(int x, int y, std::string baslik);
    void init();
    bool getQuit();
    void handleCloseEvent();
    bool isEvent(SDL_EventType type);
    ~Window();
};



#endif