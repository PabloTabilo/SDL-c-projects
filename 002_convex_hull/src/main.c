/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : main
 * @created     : Thursday Jan 09, 2025 00:36:15 Pacific SA Daylight Time
 */
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h> // for rand()
#include <stdbool.h>

#include <time.h> // for srand()

#include "config.h"

#include "initializeSDL.h"
#include "Circle.h"
#include "LineRender.h"

#include "ConvexHull.h"

#define SCREEN_WIDTH 980
#define SCREEN_HEIGHT 720
#define MAX_LINES 1000

const char * TITLE = "convex hull project";
const int GAP = 50;
int numPoints = 20;
int lineCnt;

int main(int argc, char * argv[])
{
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;

    if(!initSDL(TITLE, SCREEN_WIDTH, SCREEN_HEIGHT, &window, &renderer)){
	return 1;
    }

    //int numPoints = sizeof(points) / sizeof(points[0]);
    SDL_Point points[numPoints];
    LineRender lines[MAX_LINES];
    // initialize the random number generator
    srand((unsigned)time(0)); 
    
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
	// clear screen
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	// all the algorithms and data structures
	for(int i=0;i<numPoints;i++){
	    int x = rand() % 800 + GAP;
	    int y = rand() % 600 + GAP;
	    points[i].x = x;
	    points[i].y = y;
	}
	ConvexHull_scan(points, numPoints, lines, &lineCnt);	
	// Draw Points
	for(int i=0; i < numPoints; i++){
	    DrawCircle(&circleRender, renderer, points[i].y, points[i].x);
	}
	// draw edges	
	for(int i=0; i < lineCnt; i++){
	    if(lines[i].state == 1){
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	    }else if(lines[i].state == 2){
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	    }else{
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    }
	    SDL_RenderDrawLine(renderer, lines[i].x1, lines[i].y1, lines[i].x2, lines[i].y2);
	    SDL_RenderPresent(renderer);
	    SDL_Delay(MY_DELAY);
	}
	SDL_Delay(MY_DELAY*10);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

