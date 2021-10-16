#include "../include/includes.h"

int init(){
    glfwInit();
    window = glfwCreateWindow(1280, 720, "Beowulf", NULL, NULL);

    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    return 0;
}

void update(){
    glClear(GL_COLOR_BUFFER_BIT);
    glfwSwapBuffers(window);
    glfwPollEvents();
}