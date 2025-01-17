/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : ConvexHull
 * @created     : Friday Jan 17, 2025 19:25:34 Pacific SA Daylight Time
 */

#include "ConvexHull.h"
#include "Stack.h"

void sortByAngles(SDL_Point * points, int l, int r, SDL_Point * ref){
    if(l < r){
	int mid = l + (r - l)/2;
	sortByAngles(points, l, mid, ref);
    }
}

void ConvexHull_scan(SDL_Point * points, int sz){
    SDL_Point * min_point = getMinYPoint(points, sz);    
    sortByAngles(points, 0, sz-1, min_point);
}
