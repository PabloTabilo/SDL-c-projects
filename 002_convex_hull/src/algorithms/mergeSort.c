/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : mergeSort
 * @created     : Sunday Jan 19, 2025 00:50:15 Pacific SA Daylight Time
 */

#include "mergeSort.h"

void mergeSort(SDL_Point * points, int l, int mid, int r, SDL_Point * ref){
    int szi = mid - l + 1;
    int szj = r - mid;
    
    SDL_Point * left = (SDL_Point *)malloc(szi * sizeof(SDL_Point));
    SDL_Point * right = (SDL_Point *)malloc(szj * sizeof(SDL_Point));

    for(int i=0;i<szi;i++){
	left[i] = points[ l + i ];
    }

    for(int j=0;j<szj;j++){
	right[j] = points[ mid + 1 + j ];
    }

    int k = l;
    int i = 0;
    int j = 0;
    
    while(i < szi && j < szj){
	// i prefer counter-clockwise 
	int cross = CrossProduct(*ref, left[i], right[j]); 
	// i and j are collinear
	// So the value more near to reference must be go first
	if(cross == 0){
	    int distLeft = (left[i].x - ref->x) * (left[i].x - ref->x) + (left[i].y - ref->y) * (left[i].y - ref->y);
	    int distRight = (right[j].x - ref->x) * (right[j].x - ref->x) + (right[j].y - ref->y) * (right[j].y - ref->y);
	    if(distLeft <= distRight){
		points[k++] = left[i++];
	    }else{
		points[k++] = right[j++];
	    }
	}
	// i is counter-clowise to j
	// so i is corrected ubicate
	// try not to lose the info of "j"
	else if(cross == -1){
	    points[k++] = right[j++];
	}
	// i is clockwise to j
	else{
	    points[k++] = left[i++];
	}
    }
    for(;i<szi;i++){
	points[k++] = left[i];
    }
    for(;j<szj;j++){
	points[k++] = right[j];
    }
    free(left);
    free(right);
    left = NULL;
    right = NULL;
}


