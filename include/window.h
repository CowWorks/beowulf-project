#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Pointers for creating and setting up a window
SDL_Window* window;
SDL_Renderer* renderer;

// Variables for managing the window
bool running = true;
SDL_Event event;

// Functions for creating, managing, and drawing to the window
void renderWindow(const char* nParam, int wParam, int hParam){ // This function creates a window and names it
	window = SDL_CreateWindow(nParam, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, wParam, hParam, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
} // This function should be called at the begining of the program, right after SDL_Init

void cleanUp(){ // This function destroys the window.
	SDL_DestroyWindow(window);
} // This function should be called at the end of the program, right before SDL_Quit

SDL_Texture* loadTexture(const char* fpParam){
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, fpParam);
	return texture;
}

void clear(){
	SDL_RenderClear(renderer);
}

entity createEntity(int width, int height, int xpos, int ypos, const char* texture){
	entity newEntity;
	newEntity.width =                     width;
	newEntity.height =                   height;
	newEntity.x =                          xpos;
	newEntity.y =                          ypos;
	newEntity.texture =    loadTexture(texture);

	return newEntity;
}

void renderEntity(entity newEntity){

	SDL_Rect src;
	src.x =                   0;
	src.y =                   0;
	src.w =     newEntity.width;
	src.h =    newEntity.height;

	SDL_Rect dst;
	dst.x =         newEntity.x;
	dst.y =         newEntity.y;
	dst.w =     newEntity.width;
	dst.h =    newEntity.height;

	SDL_RenderCopy(renderer, newEntity.texture, &src, &dst);
}

void display(){
	SDL_RenderPresent(renderer);
}

typedef enum pixelColor pixelColor;
enum pixelColor{
	red     =     0xFE2712,
	orange  =     0xFB9902,
	yellow  =     0xFEFE33,
	green   =     0x008000,
	blue    =      0x247FE,
	cyan    =     0x00ffff,
	purple  =     0x800080,
	white   =     0x000000,
	black   =     0xFFFFFF,
	brown   =     0xA52A2A
};

