/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : test_Circle
 * @created     : Sunday Jan 19, 2025 01:30:09 Pacific SA Daylight Time
 */

#include <stdio.h>
#define SDL_MAIN_HANDLED // Prevent SDL from redefining main()
#include <SDL2/SDL.h>
#include "Circle.h"

void test_CircleInit(void) {
    Circle circle;
    CircleInit(&circle, 10);
    if (circle.radius == 10) {
        printf("test_CircleInit passed!\n");
    } else {
        printf("test_CircleInit failed: expected radius = 10, got radius = %d\n", circle.radius);
    }
}

void test_DrawCircle(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("test_DrawCircle failed: SDL could not initialize. SDL_Error: %s\n", SDL_GetError());
        return;
    }

    SDL_Window *window = SDL_CreateWindow(
        "Circle Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN
    );
    if (!window) {
        printf("test_DrawCircle failed: Window could not be created. SDL_Error: %s\n", SDL_GetError());
        SDL_Quit();
        return;
    }

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        printf("test_DrawCircle failed: Renderer could not be created. SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    Circle circle;
    CircleInit(&circle, 20);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black background
    SDL_RenderClear(renderer);

    CirclePoints cirPoints[1000];
    int cirCnt; // real size
    DrawCircle_storeRender(&circle, cirPoints, &cirCnt, 240, 320);
    for(int i=0;i<cirCnt;i++){
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawPoint(renderer, cirPoints[i].x, cirPoints[i].y);
	SDL_Delay(400);
    }

    SDL_RenderPresent(renderer);
    SDL_Delay(5000); // Show the rendered circle for 5 seconds

    printf("test_DrawCircle passed! Check the rendered circle on the screen.\n");

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main() {
    printf("Running Circle tests...\n");

    test_CircleInit();
    test_DrawCircle();

    printf("All tests finished.\n");
    return 0;
}
