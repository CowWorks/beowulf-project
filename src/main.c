#include "cfw.h"

int main(int argc, char** argv){
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  CGE application = init_CGE();
  application.renderWindow("Beowulf Project by CowDev - Adrian", 1280, 720);

  entity newEntity[] = {
                        application.createEntity(300, 300, 100, 100, "res/images/jake.png")
                      };

  while(running){
    
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        running = false;
      }
    }
    uint64_t start = SDL_GetPerformanceCounter();
    application.clear();
    for (int i = 0; i < (sizeof(newEntity)/sizeof(entity)); i++){
      application.renderEntity(newEntity[i]);
    }
    
    application.display();
    uint64_t end = SDL_GetPerformanceCounter();
    float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency();
    SDL_Delay(floor(16.666f - elapsed));
  }
    application.cleanUp();
    SDL_Quit();
    return 0;
}