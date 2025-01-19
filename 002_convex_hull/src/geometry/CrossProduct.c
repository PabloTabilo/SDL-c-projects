/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : CrossProduct
 * @created     : Friday Jan 17, 2025 19:33:45 Pacific SA Daylight Time
 */

#include "CrossProduct.h"

// p1 is on hull
// p2 is a candidate
int CrossProduct(SDL_Point ref, SDL_Point p1, SDL_Point p2){
    int x1 = p1.x;
    int y1 = p1.y;

    int x2 = p2.x;
    int y2 = p2.y;

    // adjust reference 0,0 -> mid, mid
    x1 -= ref.x;
    y1 -= ref.y;

    x2 -= ref.x;
    y2 -= ref.y;

    int area = x1*y2 - x2*y1;

    if(area < 0) return -1; // clockwise
    else if(area > 0) return 1; // counter-clockwise
    return 0; // collinear
}
