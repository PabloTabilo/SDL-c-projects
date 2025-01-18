/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : ConvexHull
 * @created     : Friday Jan 17, 2025 19:07:14 Pacific SA Daylight Time
 */

#ifndef CONVEXHULL_H

#define CONVEXHULL_H

#include <SDL2/SDL.h>
#include "Stack.h"
#include "CrossProduct.h"

void mergeSort(SDL_Point * points, int l, int mid, int r, SDL_Point * ref);
void sortByAngles(SDL_Point * points, int l, int r, SDL_Point * ref);
int getMinYPoint(SDL_Point * points, int sz);
void swap(SDL_Point * points, int i, int j);
void ConvexHull_scan(SDL_Renderer * renderer, SDL_Point * points, int sz);



#endif /* end of include guard CONVEXHULL_H */

