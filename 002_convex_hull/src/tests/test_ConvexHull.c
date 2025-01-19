/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : test_ConvexHull
 * @created     : Sunday Jan 19, 2025 01:00:33 Pacific SA Daylight Time
 */

#include <stdio.h>
#define SDL_MAIN_HANDLED // Prevent SDL from redefining main()
#include <SDL2/SDL.h>

#include "ConvexHull.h"

void test_getMinYPoint(void){
    SDL_Point points[] = {{1,1},{0,0},{2,2},{3,1}};
    int size = sizeof(points) / sizeof(points[0]);
    int idx = getMinYPoint(points, size);
    if(idx == 1){
	printf("test_getMinYPoint passed!\n");
    }else{
	printf("test_getMinYPoint failed: Expected 1, got %d\n", idx);
    }
}

void test_ConvexHull_scan(void){
    SDL_Point points[] = {{0, 3}, {1, 1}, {2, 2}, {4, 4}, {0, 0}, {1, 2}, {3, 1}, {3, 3}};
    int size = sizeof(points) / sizeof(points[0]);
    LineRender lines[100];
    int lineCnt = 0;
    ConvexHull_scan(points, size, lines, &lineCnt);
    if(lineCnt > 0){
	printf("test_ConvexHull_scan passed!\n");
    }else{
	printf("test_ConvexHull_scan failed \n");
    }
}

int main(){
    printf("Running ConvexHull_scan tests ... \n");
    
    test_getMinYPoint();
    test_ConvexHull_scan();

    printf("All ConvexHull test finished.\n");

    return 0;
}
