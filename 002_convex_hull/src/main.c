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
		  //
#include "initializeSDL.h"
#include "Circle.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

const char * TITLE = "convex hull project";

int main(int argc, char * argv[])
{
    initializeSDL i(title, SCREEN_WIDTH, SCREEN_HEIGHT);
    auto [window, renderer] = i.init();

    if(!(window && renderer)){
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
    
    Circle cir(10);

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

	for(auto p : points){
	    cir.DrawCircle(renderer, p.y, p.x);
	}

	SDL_RenderPresent(renderer);
	SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(myRect);
    SDL_Quit();

    return 0;
}

