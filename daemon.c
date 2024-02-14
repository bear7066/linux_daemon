#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <sys/inotify.h>

#define EXT_SUCCESS 0
#define EXT_ERR_TOO_FEW_ARCS 1
#define EXT_ERR_INIT_INOTIFY 2
#define EXT_ERR_ADD_WATCH 3

int IeventQueue = -1;
int IeventStatus = -1;

int main(int argc, char* argv[]) {
    char *basePath = NULL;
    char *token = NULL;
    const uint32_t watchMask = IN_CREATE | IN_DELETE | IN_ACCESS | IN_CLOSE_WRITE | IN_MODIFY | IN_MOVE_SELF;

    if (argc < 2) {
        fprintf(stderr, "Usage: we need more arcs\n");
        exit(EXT_ERR_TOO_FEW_ARCS);
    }

    basePath = (char *)malloc(sizeof(char) * strlen(argv[1]) + 1);
    strcpy(basePath, argv[1]);
    token = strtok(basePath, "/");
    
    while (token != NULL) {
        basePath = token;
        token = strtok(NULL, "/");
    }

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

    exit(EXT_SUCCESS);
}
