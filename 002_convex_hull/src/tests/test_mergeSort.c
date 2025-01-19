/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : test_mergeSort
 * @created     : Sunday Jan 19, 2025 01:14:36 Pacific SA Daylight Time
 */

#include <stdio.h>
#include <stdbool.h>
#define SDL_MAIN_HANDLED // Prevent SDL from redefining main()
#include <SDL2/SDL.h>

#include "mergeSort.h"

void merge(SDL_Point * points, int l, int r, SDL_Point * ref){
    if(l < r){
	int mid = l + (r - l) / 2;
	merge(points, l, mid, ref);
	merge(points, mid+1, r, ref);
	mergeSort(points, l, mid, r, ref);
    }
}

void test_mergeSort(void){
    SDL_Point points[] = {{0,0},{999, 100}, {6, 7}, {23, 25}};
    SDL_Point ref = {0,0};
    int size = sizeof(points) / sizeof(points[0]);
    
    merge(points, 0, size-1, &ref);
    
    bool isCorrect = true;
    SDL_Point answer[] = {{0,0},{6, 7},{23, 25},{999, 100}};
    for(int i = 0; i < size; i++){
	if(points[i].x != answer[i].x){
	    isCorrect = false;
	    break;
	}	
	if(points[i].y != answer[i].y){
	    isCorrect = false;
	    break;
	}
    }
    if(isCorrect){
	printf("test_mergeSort passed!\n");
    }else{
	printf("test_mergeSort failed\n");
    }
}

int main(){
    printf("Running mergeSort tests ... \n");
    
    test_mergeSort();

    printf("All mergeSort test finished.\n");

    return 0;
}


