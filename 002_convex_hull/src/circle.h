/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : circle
 * @created     : Wednesday Jan 15, 2025 20:14:04 Pacific SA Daylight Time
 */

#ifndef CIRCLE_H

#define CIRCLE_H

#include <SDL2/SDL.h>

typedef struct {
    int radius;
}Circle;

void CircleInit(Circle * circle, int radius);
void midPointCircleAlgorithm(SDL_Renderer * renderer, int cy, int cx, int radius);
void DrawCircle(const Circle * circle, SDL_Renderer * renderer, int cy, int cx); 

#endif /* end of include guard CIRCLE_H */

