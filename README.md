# SDL-c-projects
My objective is get better on C doing different projects.

## Project 001 - A simple Tv distortion - Learn to use SDL 
This project demonstrates how to manipulate pixels on the screen using the surface pointer in SDL.
### New Concepts learned or reforced
* Proper usage of pointers (`*`).
* Using the [SDL2](https://wiki.libsdl.org/SDL2/SDL_CreateWindow) API.
### Results
<img src="./assets/images/print_random_points_on_screen.PNG" width="800">

### General project's structure for learning phase

```bash
C:.
│   main.exe
│   Makefile
│   SDL2.dll
│
├───include
│   └───SDL2
│
├───lib
│   │
│   ├───cmake
│   │   └───SDL2
│   │
│   └───pkgconfig
│
└───src
        main.c

```

* The `Makefile` allows easy compilation of the project files!

## Project 002 - ConvexHull

### Objectives, Learning outcomes and technical Skills Acquired
* Build your own algorithm and data structures
* Create and manage Stack data structure
* Vectors operations, in this case, cross product
* Logic behind and how implement the convex algorithm
* All the logic and implementation behind for create figures
    * middle point algorithm was used for build circles
* Design and implement animations for visualizing the construction of the Convex Hull.
* Dynamic memory managment (malloc, free).
* Passing pointers and references.
* Implement own sort algorithms based on the Struct of points and create owner rules for decide how sort the elements, in this case, using cross product with a point reference.

### Results
<img src="./assets/gifs/convexHull.gif" width="800">

### Structure Project for ConvexHull
```bash
C:.
│   Makefile
│   SDL2.dll
│
├───build
│   ├───bin
│   │
│   └───obj
│
├───include
│   │   Circle.h
│   │   config.h
│   │   ConvexHull.h
│   │   CrossProduct.h
│   │   initializeSDL.h
│   │   LineRender.h
│   │   mergeSort.h
│   │   Stack.h
│   │
│   └───SDL2
│
├───lib
│
└───src
    │   main.c
    │
    ├───algorithms
    │       ConvexHull.c
    │       mergeSort.c
    │
    ├───data-structure
    │       Stack.c
    │
    ├───geometry
    │       Circle.c
    │       CrossProduct.c
    │
    ├───init
    │       initializeSDL.c
    │
    └───tests
            test_Circle.c
            test_ConvexHull.c
            test_mergeSort.c
            test_Stack.c
```
* `include/`: Contains all the .h header files, such as `Circle.h`, `ConvexHull.h`, and others.
* `src/main.c`: The main file where all modules come together to create the Convex Hull project.
* `algorithms/`: Houses the implementations for the Convex Hull and Merge Sort algorithms.
* `data-structure/`: Contains the Stack implementation, the only data structure we need for this project.
* `geometry/`: Includes the Circle struct and the Cross Product implementation.
* `init/`: Provides the SDL2 initializer to keep everything organized and clean.
* `tests/`: Contains simple unit tests for the major components of the project.


## References and interesting links
* Other tutorials i plan check: https://www.parallelrealities.co.uk/tutorials/
* https://wiki.libsdl.org/SDL2/Tutorials
* Inspiration: https://www.youtube.com/@HirschDaniel
