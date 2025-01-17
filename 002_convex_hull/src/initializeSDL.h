/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : initializeSDL
 * @created     : Wednesday Jan 15, 2025 20:23:57 Pacific SA Daylight Time
 */

#ifndef INITIALIZESDL_H

#define INITIALIZESDL_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

bool initSDL(const char * title, int width, int height, SDL_Window ** window, SDL_Renderer ** renderer);

#endif /* end of include guard INITIALIZESDL_H */

