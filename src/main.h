#include "../include/includes.h"

camera buttons(){
    camera myCamera;

    for (int i = 0; i < 255; i++){
        int state = GetAsyncKeyState(i);

        if (state == 1 || state == -32767){
           switch(i){
               case wKey:
               {
                   myCamera.cameraY -= 5;
               }break;
               case aKey:
               {
                   printf("A\n");
               }break;
               case sKey:
               {
                   myCamera.cameraY += 5;
               }break;
               case dKey:
               {
                   printf("D\n");
               }break;
               case SHIFT:
               {
                   printf("Shift\n");
               }break;
               case SPACE:
               {
                   printf("Space\n");
               }break;
           }
        }
    }
    return myCamera;
}

void drawPlayer(){
    glColor3f(1, 1, 1);
    render(GL_QUADS, 300, 300);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //drawMap();
    drawPlayer();

    glfwSwapBuffers(window);
}