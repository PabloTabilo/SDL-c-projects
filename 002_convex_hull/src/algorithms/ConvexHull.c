/**
 * @author      : $USER ($USER@$HOSTNAME)
 * @file        : ConvexHull
 * @created     : Friday Jan 17, 2025 19:25:34 Pacific SA Daylight Time
 */

#include "ConvexHull.h"

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

void ConvexHull_scan(SDL_Point * points, int sz, LineRender * lines, int *lineCnt){
    *lineCnt = 0;
    // more debug
    // printf("Initial Points: \n");for(int i = 0; i < sz; i++) printf("{%i, %i}", points[i].y, points[i].x); printf("\n");
    int idx = getMinYPoint(points, sz); 
    SDL_Point min_point = points[idx];    
    swap(points, 0, idx);
    sortByAngles(points, 0, sz-1, &min_point);
    // more debug
    // printf("Points after Sort \n");for(int i = 0; i < sz; i++) printf("{%i, %i}", points[i].y, points[i].x); printf("\n");
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

    lines[(*lineCnt)++] = (LineRender){points[0].x, points[0].y, points[1].x, points[1].y, 1};

    SDL_Point p = {0, 0};
    SDL_Point peek = {0, 0};
    
    for(int i = 2; i < sz; i++){
	SDL_Point nxt = points[i];

	Stack_Pop(&stackX, &p.x);
	Stack_Pop(&stackY, &p.y);
	
	peek.x = Stack_Peek(&stackX);
	peek.y = Stack_Peek(&stackY);

	while(!Stack_IsEmpty(&stackX) && CrossProduct(peek, p, nxt) <= 0){
	    // this clear is only for animation purpose
	    // in principle we drop the point
	    
	    lines[(*lineCnt)++] = (LineRender){peek.x, peek.y, p.x, p.y, 2};
	    lines[(*lineCnt)++] = (LineRender){peek.x, peek.y, p.x, p.y, 0};
	    

	    Stack_Pop(&stackX, &p.x);
	    Stack_Pop(&stackY, &p.y);

	    if(Stack_IsEmpty(&stackX)) break;
	    
	    peek.x = Stack_Peek(&stackX);
	    peek.y = Stack_Peek(&stackY);
	}

	Stack_Push(&stackX, p.x);
	Stack_Push(&stackY, p.y);

	Stack_Push(&stackX, points[i].x);
	Stack_Push(&stackY, points[i].y);

	lines[(*lineCnt)++] = (LineRender){p.x, p.y, points[i].x, points[i].y, 1};
    }

    // the last can be collinear
    Stack_Pop(&stackX, &p.x);
    Stack_Pop(&stackY, &p.y);

    peek.x = Stack_Peek(&stackX);
    peek.y = Stack_Peek(&stackY);

    if(CrossProduct(peek, p, min_point) > 0){
	Stack_Push(&stackX, p.x);
	Stack_Push(&stackY, p.y);
    }
    
    lines[(*lineCnt)++] = (LineRender){p.x, p.y, min_point.x, min_point.y, 1};
}



