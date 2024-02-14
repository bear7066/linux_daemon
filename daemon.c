#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARCS 1


int main(int argc, char** argv){

    char *basePath = NULL;
    char *token = NULL;
    if(argc < 2){
        fprintf(stderr, "Usage: we need more arcs\n");
        exit(EXT_ERR_TOO_FEW_ARCS);
    }

    basePath = (char *)malloc(sizeof(char) * sizeof(argv[1]) + 1);
    strcpy(basePath, argv[1]);
    token = strtok(basePath, "/");

    // a failed program result usually return non-zero value 
    exit(EXT_SUCCESS);
}

