/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : main
 * @created     : Thursday Jan 09, 2025 00:36:15 Pacific SA Daylight Time
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <stdlib.h> // for rand()
#include <time.h> // for srand()

#include "initializeSDL.h"
#include "Circle.h"
#include "ConvexHull.h";

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

const char * TITLE = "convex hull project";

int main(int argc, char * argv[])
{
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;

    if(!initSDL(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, &window, &renderer)){
	return 1;
    }

    int numPoints = 20;
    //int numPoints = sizeof(points) / sizeof(points[0]);
    SDL_Point points[numPoints];
    // initialize the random number generator
    srand((unsigned)time(0)); 

    for(int i=0;i<numPoints;i++){
	int x = rand() % 800;
	int y = rand() % 600;

	points[i].x = x;
	points[i].y = y;
    }
    
    Circle circleRender;
    CircleInit(&circleRender, 10);  

    SDL_Event event;
    bool running = true;
    while(running){
	while(SDL_PollEvent(&event)){
	    if(event.type == SDL_QUIT){
		running = false;
		break;
	    }
	}
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	for(int i=0; i < numPoints; i++){
	    DrawCircle(&circleRender, renderer, points[i].y, points[i].x);
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(100);
	ConvexHull_scan(renderer, points, numPoints);	
	printf("finish convex hull!");
	SDL_Delay(5000);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

