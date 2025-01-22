#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_of_life.h"

typedef enum {
    DEAD,
    ALIVE
} State;

typedef struct {
    State state;
    int neighbours;
} Cell;

struct grid {
    Cell** cell;
    int width;
};

Grid map_create(int width) {

    Grid map = malloc(sizeof(struct grid));

    map->cell = malloc(width * sizeof(*(map->cell)));
    

    for (int i = 0; i < width; i++) {
        map->cell[i] = malloc(width * sizeof(Cell));
    }

    map->width = width;

    unsigned int seed = time(NULL);
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->width; j++) {

            if (rand_r(&seed) / (double)RAND_MAX < 0.65 ) {
                map->cell[i][j].state = DEAD;
            }
            else
                map->cell[i][j].state = ALIVE;
        }
    }

    return map;
}

void map_print(Grid map) {

    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->width; j++) {
            if (map->cell[i][j].state == DEAD) {
                putchar('-');
            }
            else putchar('#');
        }
        putchar('\n');
    }
}


void map_next_gen_calculate(Grid map) {
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->width; j++) {
                
            map->cell[i][j].neighbours = 0;
            
            for (int x = i - 1; x <= (i + 1); x++) {
                for (int y = j - 1; y <= (j + 1); y++) {

                    if ((x == i && y == j) || x == -1 || y == -1 || x == map->width || y == map->width)
                        continue;
                    
                    if (map->cell[x][y].state == ALIVE)
                        map->cell[i][j].neighbours ++;
                    
                }
            }
        }
    }
}

void map_update(Grid map) {

    map_next_gen_calculate(map);
    
    for (int i = 0; i < map->width; i++) {
        for (int j = 0; j < map->width; j++) {

            if (map->cell[i][j].state != ALIVE) {
                if (map->cell[i][j].neighbours == 3)
                    map->cell[i][j].state = ALIVE;
                
                continue;
            }
            
            if (map->cell[i][j].neighbours < 2 || map->cell[i][j].neighbours > 3)
                map->cell[i][j].state = DEAD;
            
        }
    }
}

void map_destroy(Grid map) {

    for (int i = 0; i < map->width; i++)
        free(map->cell[i]);
    
    free(map->cell);
    free(map);
}