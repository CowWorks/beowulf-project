// System includes
#include <stdio.h>

// GLFW includes
#include "GLFW/glfw3.h"

// My declarations
int init( void );
void update( void );

GLFWwindow* window;

typedef struct camera{
    float cameraX;
    float cameraY;
    float cameraDeltaX;
    float cameraDeltaY;
    float cameraAngle;
}camera;

camera myCamera;

// Basic application
int main(){
    init();

    while (!glfwWindowShouldClose(window)){
        update();
    }
    glfwTerminate();

    return 0;
}