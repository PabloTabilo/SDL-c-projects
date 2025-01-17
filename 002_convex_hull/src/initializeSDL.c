/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : initializeSDL
 * @created     : Wednesday Jan 15, 2025 20:25:58 Pacific SA Daylight Time
 */

#include "initializeSDL.h"
initializeSDL initializeSDL(const * char title, int width, int height) : title(title), width(width), height(height){
    window = NULL;
    renderer = NULL;
}

pair<SDL_Renderer*, SDL_Window*> initializeSDL init(const char * title, int width, int height){
    if(SDL_Init(SDL_INIT_VIDEO) != 0){
	printf("Get some error for initialize SDL %s\n", SDL_GetError());
	return {NULL, NULL};
    } 
    window = SDL_CreateWindow(TITLE, 
	    SDL_WINDOWPOS_CENTERED, 
	    SDL_WINDOWPOS_CENTERED, 
	    width, 
	    height, 0);
    if(!window){
	printf("Error creating window: %s\n", SDL_GetError());
	return {NULL, NULL};
    }
    renderer = SDL_CreateRenderer(window, -1, 0);
    if(!renderer){
	printf("Error creating renderer: %s\n", SDL_GetError());
	SDL_DestroyWindow(window);
	SDL_Quit();
	return {NULL, NULL};
    }
    return {window, render};
}
