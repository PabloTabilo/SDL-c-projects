/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : initializeSDL
 * @created     : Wednesday Jan 15, 2025 20:23:57 Pacific SA Daylight Time
 */

#ifndef INITIALIZESDL_H

#define INITIALIZESDL_H

#include <SDL2/SDL.h>

typedef struct{
    SDL_Window * window;
    SDL_Renderer * render;
    const * char title;

    initializeSDL();
    pair<SDL_Window *, SDL_Renderer *> init(const char * title, int width, int height);
} initializeSDL;


#endif /* end of include guard INITIALIZESDL_H */

