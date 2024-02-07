#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARCS 1


int main(int argc, char** argv){

    if(argc < 2){
        fprintf(stderr, "Usage: we need more arcs\n");
        exit(EXT_ERR_TOO_FEW_ARCS);
    }

    // a failed program result usually return non-zero value 
    exit(EXT_SUCCESS);
}

