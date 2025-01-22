#pragma once

typedef struct grid *Grid;

Grid map_create(int width);

void map_print(Grid map);

void map_update(Grid map);

void map_destroy(Grid map);