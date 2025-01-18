/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : ConvexHull
 * @created     : Friday Jan 17, 2025 19:25:34 Pacific SA Daylight Time
 */

#include "ConvexHull.h"
#include "Stack.h"
#include "CrossProduct.h"

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
}

void sortByAngles(SDL_Point * points, int l, int r, SDL_Point * ref){
    if(l < r){
	int mid = l + (r - l)/2;
	sortByAngles(points, l, mid, ref);
	sortByAngles(points, mid+1, r, ref);
	mergeSort(points, l, mid, r, ref);
    }
}

// top-left 0,0 
// so more down = more big
int getMinYPoint(SDL_Point * points, int sz){
    int y_min = points[0].y;
    int idx = 0;
    for(int i = 1; i < sz; i++){
	if(y_min < points[i].y || (y_min == points[i].y && points[i].x < points[idx].x)){
	    idx = i;
	    y_min = points[i].y;
	}
    }
    return idx;
}

void swap(SDL_Point * points, int i, int j){
    SDL_Point temp = points[i];
    points[i] = points[j];
    points[j] = temp;
}

void ConvexHull_scan(SDL_Renderer * renderer, SDL_Point * points, int sz){
    int idx = getMinYPoint(points, sz); 
    SDL_Point min_point = points[idx];    
    swap(points, 0, idx);
    sortByAngles(points, 0, sz-1, &min_point);
    // I need think on this part
    // may be change stack to SDL_Point or use coords? what's more easy?
    Stack stackX;
    Stack stackY;
    
    Stack_Init(&stackX);
    Stack_Init(&stackY);

    Stack_Push(&stackX, points[0].x); 
    Stack_Push(&stackY, points[0].y); 

    Stack_Push(&stackX, points[1].x); 
    Stack_Push(&stackY, points[1].y);
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, points[0].x, points[0].y, points[1].x, points[1].y);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);

    SDL_point p;
    SDL_point peek;
    for(int i = 2; i < sz; i++){
	SDL_Point nxt = points[i];

	Stack_Pop(&stackX, &p.x);
	Stack_Pop(&stackY, &p.y);
	
	Stack_Peek(&stackX, &peek.x);
	Stack_Peek(&stackY, &peek.y);

	while(!Stack_IsEmpty(stackX) && CrossProduct(peek, p, nxt) <= 0){
	    // this clear is only for animation purpose
	    // in principle we drop the point
	    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	    SDL_RendererDrawLine(renderer, peek.x, peek.y, p.x, p.y);
	    SDL_RenderPresent(renderer);
	    SDL_Delay(500);
	    
	    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	    SDL_RendererDrawLine(renderer, peek.x, peek.y, p.x, p.y);
	    SDL_RenderPresent(renderer);
	    SDL_Delay(500);

	    Stack_Pop(&stackX, &p.x);
	    Stack_Pop(&stackY, &p.y);

	    if(Stack_IsEmpty()) break;
	    
	    Stack_Peek(&stackX, &peek.x);
	    Stack_Peek(&stackY, &peek.y);
	}

	Stack_Push(&stackX, p.x);
	Stack_Push(&stackY, p.y);

	Stack_push(&stackX, points[i].x);
	Stack_push(&stackY, points[i].y);

	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(renderer, p.x, p.y, points[i].x, points[i].y);
	SDL_RenderPresent(renderer);
	SDL_Delay(500);
    }

    // the last can be collinear
    Stack_Pop(&stackX, &p.x);
    Stack_Pop(&stackY, &p.y);

    Stack_Peek(&stackX, &peek.x);
    Stack_Peek(&stackY, &peek.y);
    
    if(CrossProduct(peek, p, min_point) > 0){
	Stack_Push(&stackX, p.x);
	Stack_Push(&stackY, p.y);
    }
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, p.x, p.y, points[i].x, points[i].y);
    SDL_RenderPresent(renderer);
    SDL_Delay(500);
}





