#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARCS 1


int main(int argc, char* argv[]){

    char *basePath = NULL;
    char *token = NULL;
    if(argc < 2){
        fprintf(stderr, "Usage: we need more arcs\n");
        exit(EXT_ERR_TOO_FEW_ARCS);
    }

    basePath = (char *)malloc(sizeof(char) * sizeof(argv[1]) + 1);
    // path = basePath 
    strcpy(basePath, argv[1]);
    // 印出原始路徑：printf("%s", basePath);
    token = strtok(basePath, "/");
    
    while(token != NULL){
        //printf("%s\n", token);
        basePath = token;
        token = strtok(NULL, "/");

    }
    // printf("%s\n", basePath);
   /*
    while(true){

    }*/

    // a failed program result usually return non-zero value 
    exit(EXT_SUCCESS);
}

