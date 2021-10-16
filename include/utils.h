#pragma once
#include <stdlib.h>
#include "window.h"
#include <math.h>

#define fileExtention = ".yaml"

/*struct entity*/ void deserializeEntity(){
    FILE* fp;
    fp = fopen("res/dev/test.yaml", "r");
    int count_lines = 0;
    char chr, information[255];
    chr = getc(fp);
    while(chr != EOF){
        if(chr == '\n'){
            count_lines = count_lines + 1;
        }
        chr = getc(fp);
    }
    count_lines = count_lines + 1;
    fseek(fp, 0, SEEK_SET); // resets the file pointer
    for(int i = 0; i < count_lines; i++){
        fgets(information, 255, (FILE*)fp);
        printf("%s", information);
    }
    //struct entity deserializedEntityData;
    // deserializedEntityData.width = ;
    // deserializedEntityData.height = ;
    // deserializedEntityData.x = ;
    // deserializedEntityData.y = ;
    // deserializedEntityData.texture = ;
    // deserializedEntityData.type = ;

    fclose(fp);
    printf("\n%i", count_lines);

    //return deserializedEntityData;
}