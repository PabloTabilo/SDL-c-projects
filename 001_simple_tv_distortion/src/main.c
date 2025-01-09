/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : main
 * @created     : Thursday Jan 09, 2025 00:36:15 Pacific SA Daylight Time
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define SRC_WIDTH 1280
#define SRC_HEIGHT 720

const char * TITLE = "why you do that?";


void change_pixels_to_randomData(SDL_Surface * surface)
{
    int n = surface->w * surface->h; // tot pixels
    printf("n = %d\n", n);
    Uint32 * pixels = (Uint32 *)surface->pixels;
    for(int i=0;i<n; i++){
	pixels[i] = (Uint32) rand();
    }
}

typedef struct{
    SDL_Renderer * renderer;
    SDL_Window * window;
    SDL_Surface * surface;
} App;

App app;

void initSDL(void)
{
    int rendererFlags, windowFlags;

    rendererFlags = SDL_RENDERER_ACCELERATED;

    windowFlags = 0;
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	printf("Couldn't initialize SDL: %s\n", SDL_GetError());
	exit(1);
    }

    app.window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SRC_WIDTH, SRC_HEIGHT, windowFlags);

    if(!app.window){
	printf("Failed to open %d x %d window: %s\n", SRC_WIDTH, SRC_HEIGHT, SDL_GetError());
	exit(1);
    }

    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);
    
    if(!app.window){
	printf("Failed to create renderer: %s\n", SDL_GetError());
	exit(1);
    }
    
    app.surface = SDL_GetWindowSurface(app.window);

}

void doInput(void)
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
	switch(event.type)
	{
	    case SDL_QUIT:
		exit(0);
		break;
	    default:
		break;
	}	    
    }
}

int main(int argc, char * argv[])
{
    memset(&app, 0, sizeof(App));
    
    initSDL();

    while(1){
	doInput();
	change_pixels_to_randomData(app.surface);
	SDL_UpdateWindowSurface(app.window);
	SDL_Delay(100);
    }

    return 0;
}

