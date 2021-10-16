#include "cfw.h"

int nScreenWidth = 64;
int nScreenHeight = 36;
float fFOV = 3.14159f / 4.0f;
float fDepth = 16.0f;

char map[128] = {
                 '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#',
                 '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'
};

typedef struct camera{
  float cameraX;
  float cameraY;
  float cameraA;
}myCamera;

typedef struct eye{
  float eyeX;
  float eyeY;
}myEye;



int main(int argc, char** argv){
	SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
  CGE application = init_CGE();
  application.renderWindow("Beowulf Project by CowDev - Adrian", 1280, 720);
  entity new[] = {application.createEntity(300, 300, 100, 100, "res/images/jake.png")};
  char screen[nScreenWidth* nScreenHeight];

  while(running){
    
    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        running = false;
      }
    }
    struct camera myCamera;
    uint64_t start = SDL_GetPerformanceCounter();

    for(int x = 0; x < nScreenWidth; x++){
      float fRayAngle = (myCamera.cameraA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) *fFOV;
      float fDistanceToWall = 0;
      int bHitWall = 1; 

      struct eye myEye;
      myEye.eyeX = sinf(fRayAngle);
      myEye.eyeY = cosf(fRayAngle);

      while(bHitWall != 0 && fDistanceToWall < fDepth){
        fDistanceToWall += 0.1f;

        int nTestX = (int)(myCamera.cameraX + myEye.eyeX * fDistanceToWall);
        int nTestY = (int)(myCamera.cameraY + myEye.eyeY * fDistanceToWall);
        
        if(nTestX < 0 || nTestX >= 16 || nTestY < 0 || nTestY >= 8){
          bHitWall = 0;
          fDistanceToWall = fDepth;
        }
        else{
          if(map[nTestY * 16 * nTestX] == '#'){
            bHitWall = 0;
          }
        }
      }

      int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
      int nFloor = nScreenHeight - nCeiling;

      for(int y = 0; y < nScreenHeight; y++){
        if(y < nCeiling){
          screen[y * nScreenWidth + x] = ' ';
        }
        else if(y > nCeiling && y <= nFloor){
          screen[y * nScreenWidth + x] = '#';
        }
        else{
          screen[y * nScreenWidth + x] = ' ';
        }
      }
    }

    application.clear();
    for (int i = 0; i < (sizeof(new)/sizeof(entity)); i++){
      application.renderEntity(new[i]);
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
