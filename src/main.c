#include "main.h"

void init(){
    glClearColor(0.3, 0.3, 0.3, 0);
    myCamera.cameraX = 300;
    myCamera.cameraY = 300;
    printf("%i", sizeof(char*));
}

void update(){
    glfwPollEvents();
    buttons();
    display();
}