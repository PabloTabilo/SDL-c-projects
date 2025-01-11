#ifndef RENDER2D_H
#define RENDER2D_H

#include <SDL2/SDL.h>
#include <vector>

struct Vertex2D{
    float x, y;
}

struct Render2D{
    Render2D(SDL_Window * _window, SDL_Renderer * _renderer );
    void render();
    std::vector<Point2D> vertices;
    SDL_Window * window;
    SDL_Renderer * render;
}

#endif
