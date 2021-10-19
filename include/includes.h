// System includes
#include <stdio.h>
#include <windows.h>

// GLFW includes
#include "glad/glad.h"
#include "GLFW/glfw3.h"


//My definitions
#define    wKey     0x57
#define    aKey     0x41
#define    sKey     0x53
#define    dKey     0x44
#define    SHIFT    0x10
#define    SPACE    0x20
#define    iNum     0x31
#define    iiNum    0x32
#define    iiiNum   0x33
#define    ivNum    0x34
#define    vNum     0x35
#define    viNum    0x36
#define    viiNum   0x37
#define    viiiNum  0x38
#define    ixNum    0x39
#define    xNum     0x30
#define    vkReturn 0x0D
#define    vkBack   0x08

#define mapX 8
#define mapY 8

// My declarations
void init( void );
void update( void );
void render( GLenum mode, int x, int y );

GLFWwindow* window;
int mapS = mapX * mapY;

typedef struct camera{
    float cameraX;
    float cameraY;
    float cameraDeltaX;
    float cameraDeltaY;
    float cameraAngle;
}camera;

camera myCamera;

int map[mapX * mapY] = {
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

void drawMap(){
    int x, y, xo, yo;
    for(y = 0; y < mapY; y++){
        for(x = 0; x < mapX; x++){
            if(map[y * mapX + x] == 1){
                glColor3f(1, 1, 1);
            }
            else{
                glColor3f(0, 0, 0);
            }
            xo = x * mapS; yo = y * mapS;
            glBegin(GL_QUADS);
            glVertex2i(xo, yo);
            glVertex2i(xo, yo + mapS);
            glVertex2i(xo + mapS, yo + mapS);
            glVertex2i(xo + mapS, yo);
            glEnd;
        }
    }
}

// Basic application
int main(){
    glfwInit();
    window = glfwCreateWindow(1024, 512, "Beowulf", NULL, NULL);

    if(!window){
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        printf("Glad probably isn't for u\n");
        return -1;
    } 
    init();
    float positions[8] = {
        myCamera.cameraX + 2, myCamera.cameraY + 2,
        myCamera.cameraX + 2, myCamera.cameraY + 2,
        myCamera.cameraX - 2, myCamera.cameraY + 2,
        myCamera.cameraX - 2, myCamera.cameraY + 2,
    };
    unsigned int buffer;
    glGenBuffers(1, &buffer);
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    glBufferData(GL_ARRAY_BUFFER, (sizeof(positions) / sizeof(float)), positions, GL_STATIC_DRAW);
    
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    while (!glfwWindowShouldClose(window)){
        update();
    }
    glfwTerminate();

    return 0;
}

void render(GLenum mode, int x, int y){
    glBegin(mode);

    glVertex2i(x + 2, y + 2);
    glVertex2i(x + 2, y -2);
    glVertex2i(x - 2, y + 2);
    glVertex2i(x - 2, y - 2);
    
    glEnd();
}