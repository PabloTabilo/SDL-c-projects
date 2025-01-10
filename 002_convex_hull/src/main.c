/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : main
 * @created     : Thursday Jan 09, 2025 00:36:15 Pacific SA Daylight Time
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

const char * TITLE = "convex hull project";
SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

bool init(void){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
	printf("Get some error for initialize SDL %s\n", SDL_GetError());
	return false;
    } 
    window = SDL_CreateWindow(TITLE, 
	    SDL_WINDOWPOS_CENTERED, 
	    SDL_WINDOWPOS_CENTERED, 
	    SCREEN_WIDTH, 
	    SCREEN_HEIGHT, 0);
    if(!window){
	printf("Error creating window: %s\n", SDL_GetError());
	return false;
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
	printf("Error creating renderer: %s\n", SDL_GetError());
	SDL_DestroyWindow(window);
	SDL_Quit();
	return false;
    }
    return true;
}

int main(int argc, char * argv[])
{
    if(!init()){
	return 1;
    }
    SDL_Rect * myRect = malloc(sizeof(SDL_Rect()));
    
    if(!myRect){
	printf("Error allocation memory for SDL_Rect.\n");
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	return 1;
    }

    myRect->x = SCREEN_WIDTH / 2;
    myRect->y = SCREEN_HEIGHT / 2;
    myRect->w = 100;
    myRect->h = 100;
    
    SDL_Point points[] = {
	{100, 100},
	{200, 150},
	{300, 200},
	{400, 250},
	{500, 300}
    };

    int numPoints = sizeof(points) / sizeof(points[0]);

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

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawRect(renderer, myRect);
	
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderDrawPoints(renderer, points, numPoints);

	SDL_RenderPresent(renderer);
	SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    free(myRect);
    SDL_Quit();

    return 0;
}

