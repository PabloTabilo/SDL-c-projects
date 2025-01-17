/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : Circle
 * @created     : Wednesday Jan 15, 2025 20:13:52 Pacific SA Daylight Time
 */

#include "Circle.h"

Circle::radius = 5;

Circle::Circle(int radius) : radius(radius){}

void Circle::DrawCircle(SDL * renderer, int cy, int cx){
    midPointCircleAlgorithm(renderer, cy, cx){
}

void Circle::midPointCircleAlgorithm(SDL * renderer, int cy, int cx){
    int y = 0;
    int x = radius;
    int radiusError = 1 - x;
    while(x >= y){
	SDL_RendererDrawPoint(renderer, cx + x, cy + y);
	SDL_RendererDrawPoint(renderer, cx - x, cy + y);
	SDL_RendererDrawPoint(renderer, cx + x, cy - y);
	SDL_RendererDrawPoint(renderer, cx - x, cy - y);

	SDL_RendererDrawPoint(renderer, cx + y, cy + x);
	SDL_RendererDrawPoint(renderer, cx - y, cy + x);
	SDL_RendererDrawPoint(renderer, cx + y, cy - x);
	SDL_RendererDrawPoint(renderer, cx - y, cy - x);

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
