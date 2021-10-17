#include "../include/includes.h"

#define    wKey     0x57
#define    aKey     0x41
#define    sKey     0x53
#define    dKey     0x44
#define    SHIFT    0x10
#define    SPACE    0x20

void buttons(){

    for (int i = 0; i < 255; i++){
        int state = GetAsyncKeyState(i);

        if (state == 1 || state == -32767){
           switch(i){
               case wKey:
               {
                   printf("W\n");
               }break;
               case aKey:
               {
                   printf("A\n");
               }break;
               case sKey:
               {
                   printf("S\n");
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
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
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
    buttons();
    display();
}