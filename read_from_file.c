#include <stdio.h>
#include <stdlib.h>

void read_and_print(char *fileName){
    FILE *f = fopen(fileName, "r");
    char c = NULL;

    while(1){
        c = fgetc(f);

        if(c==EOF){
            break;
        }

        printf("%c", c);
    }

    printf("\n");
}
