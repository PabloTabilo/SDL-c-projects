/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : Circle
 * @created     : Wednesday Jan 15, 2025 20:13:52 Pacific SA Daylight Time
 */

#include "Circle.h"

void CircleInit(Circle * circle, int radius){
    circle->radius = radius;
}

void DrawCircle(const Circle * circle, SDL_Renderer * renderer, int cy, int cx){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    midPointCircleAlgorithm(renderer, cy, cx, circle->radius);
}

void midPointCircleAlgorithm(SDL_Renderer * renderer, int cy, int cx, int radius){
    int y = 0;
    int x = radius;
    int radiusError = 1 - x;
    while(x >= y){
	SDL_RenderDrawPoint(renderer, cx + x, cy + y);
	SDL_RenderDrawPoint(renderer, cx - x, cy + y);
	SDL_RenderDrawPoint(renderer, cx + x, cy - y);
	SDL_RenderDrawPoint(renderer, cx - x, cy - y);

	SDL_RenderDrawPoint(renderer, cx + y, cy + x);
	SDL_RenderDrawPoint(renderer, cx - y, cy + x);
	SDL_RenderDrawPoint(renderer, cx + y, cy - x);
	SDL_RenderDrawPoint(renderer, cx - y, cy - x);

	y++;
	// midpoint inside circle
	if(radiusError < 0){
	    radiusError += 2 * y + 1; // delta y^2 = (y+1)^2 - y^2 = 2 * y + 1  
	}
	// midpoint outside circle
	else{
	    x--;
	    radiusError += 2*y - 2*x + 2; // delta y^2 + delta x^2 = (x-1)^2 - x^2 
	}

    }
}

void midPointCircleAlgorithm_storeRender(CirclePoints * cirPoints, int * cirCnt, int cy, int cx, int radius){
    int y = 0;
    int x = radius;
    int radiusError = 1 - x;
    *cirCnt = 0;
    while(x >= y){
	cirPoints[(*cirCnt)++] = (CirclePoints){cx + x, cy + y};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx - x, cy + y};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx + x, cy - y};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx - x, cy - y};
	
	cirPoints[(*cirCnt)++] = (CirclePoints){cx + y, cy + x};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx - y, cy + x};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx + y, cy - x};
	cirPoints[(*cirCnt)++] = (CirclePoints){cx - y, cy - x};
	
	y++;
	// midpoint inside circle
	if(radiusError < 0){
	    radiusError += 2 * y + 1; // delta y^2 = (y+1)^2 - y^2 = 2 * y + 1  
	}
	// midpoint outside circle
	else{
	    x--;
	    radiusError += 2*y - 2*x + 2; // delta y^2 + delta x^2 = (x-1)^2 - x^2 
	}

    }
}

void DrawCircle_storeRender(const Circle * circle, CirclePoints * cirPoints, int * cirCnt, int cy, int cx){
    midPointCircleAlgorithm_storeRender(cirPoints, cirCnt, cy, cx, circle->radius);
}


