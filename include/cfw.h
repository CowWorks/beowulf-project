// Make sure the file is only copied once.
#pragma once

// System includes
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

// SDL includes
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct entity entity;
struct entity{
    int               width;
	int              height;
	int                   x;
	int                   y;
	SDL_Texture*    texture;
	const char*        type;
};

// NOTE(Adrian): Function pointer prototypes for the CGE struct
typedef    void RENDERWINDOW( const char* nParam, int wParam, int hParam );                          // Makes a window and prepares it for rendering
typedef    void DESERIALIZEENTITY( void );                                                           // Reads entity data from a file and stores it in memory
typedef    void CLEANUP( void );                                                                     // Deallocates resources when shutting down the application
typedef    SDL_Texture* LOADTEXTURE( const char* fpParam );                                          // Loads a texture into memory after fetching an image from the given directory
typedef    void CLEAR( void );                                                                       // Clears the screen before rendering again
typedef    entity CREATEENTITY( int width, int height, int xpos, int ypos, const char* texture );    // Creates the instance of an entity and stores it in memory
typedef    void RENDERENTITY( entity newEntity );                                                    // Renders an entity stored in an struct of the type "entity"
typedef    void DISPLAY( void );                                                                     // Displays the back buffer

// NOTE(Adrian): CGE struct which holds all of the basic instructions in CGE
typedef struct CGE CGE;
struct CGE{
    RENDERWINDOW              *renderWindow;
    DESERIALIZEENTITY    *deserializeEntity;
    CLEANUP                        *cleanUp;
    LOADTEXTURE                *loadTexture;
    CLEAR                            *clear;
    CREATEENTITY              *createEntity;
    RENDERENTITY              *renderEntity;
    DISPLAY                        *display;
};

// Custom includes
#include "window.h"
#include "utils.h"

// NOTE(Adrian): CGE initialization function
CGE init_CGE(){
    CGE cge;

    cge.renderWindow =              renderWindow;
    cge.deserializeEntity =    deserializeEntity;
    cge.cleanUp =                        cleanUp;
    cge.loadTexture =                loadTexture;
    cge.clear =                            clear;
    cge.createEntity =              createEntity;
    cge.renderEntity =              renderEntity;
    cge.display =                        display;
    
    return cge;
}