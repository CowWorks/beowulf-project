// System includes
#include <stdio.h>

// GLFW includes
#include "GLFW/glfw3.h"

// My declarations
int init( void );
void update( void );

GLFWwindow* window;

// Basic application
int main(){
    init();

    while (!glfwWindowShouldClose(window)){
        update();
    }
    glfwTerminate();

    return 0;
}