#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <sys/inotify.h>

// a failed program result usually return non-zero value 
#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARCS 1
#define EXT_ERR_INIT_INOTIFY 2
#define EXT_ERR_ADD_WATCH 3
#define EXT_ERR_BASE_PATH_NULL 4
#define EXT_ERR_READ_INOTIFY 5
#define EXT_ERR_INIT_LIBNOTIFY 6 

int IeventQueue = -1;
int IeventStatus = -1;

int main(int argc, char* argv[]) {

    char *basePath = NULL;
    char *token = NULL;
    char buffer[4096];
	// return the number of characters
	int readLength = 0;

	const uint32_t watchMask = IN_CREATE | IN_DELETE | IN_ACCESS | IN_CLOSE_WRITE | IN_MODIFY | IN_MOVE_SELF;

    if (argc < 2) {
        fprintf(stderr, "Usage: we need more arcs\n");
        exit(EXT_ERR_TOO_FEW_ARCS);
    }

    basePath = (char *)malloc(sizeof(char) * strlen(argv[1]) + 1);
    strcpy(basePath, argv[1]);
    // print the original path：printf("%s", basePath);
    token = strtok(basePath, "/");
    
    while (token != NULL) {
        basePath = token;
        token = strtok(NULL, "/");
    }
	if(basePath == NULL){
		fprintf(stderr, "Error getting base path!");
		exit(EXT_ERR_BASE_PATH_NULL);
	}
    // blocking operation => let program run until it stuck by itself
    // blocking operation => program hand on code and wait for some event to continue
    IeventQueue = inotify_init();
    if (IeventQueue == -1) {
        fprintf(stderr, "Error initializing inotify instance!\n");
        exit(EXT_ERR_INIT_INOTIFY);
    }
    
    IeventStatus = inotify_add_watch(IeventQueue, argv[1], watchMask);
    if (IeventStatus == -1) {
        fprintf(stderr, "Error adding file to watch instance!\n");
        exit(EXT_ERR_ADD_WATCH);
    }
	
	while(true){
		printf("Waiting for ievent...\n");
		readLength = read(IeventQueue, buffer, sizeof(buffer));
	
		for(char *bufferPointer){

		}
	}
    // exit(EXT_SUCCESS);
}
