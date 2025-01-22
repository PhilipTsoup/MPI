#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "game_of_life.h"


int main(int argc, char **argv) {

    system("clear");

    if (argc != 3) {
        fprintf(stderr, "Invalid num of arguments\n");
        return 1;
    }

    int numOfGenerations = atoi(argv[1]);
    int size = atoi(argv[2]);

    Grid map = map_create(size);

    for (int i = 0; i < numOfGenerations; i++) {

        map_print(map);
        map_update(map);
        usleep(20000);
        system("clear");
    }


    map_print(map);
    map_destroy(map);

    return 0;
}