#include "../include/includes.h"

void drawCamera(){
    glColor3f(1, 1, 0);
    glPointSize(8);
    /*glBegin(GL_POINTS);
    glVertex2i(px, py);
    glEnd();*/
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawCamera();
    glfwSwapBuffers(window);
}

int init(){
    glfwInit();
    window = glfwCreateWindow(1024, 512, "Beowulf", NULL, NULL);

    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glClearColor(0.3, 0.3, 0.3, 0);
    return 0;
}

void update(){
    glfwPollEvents();
    display();
}