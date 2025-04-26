//
// Created by luke on 26/03/2025.
//

#ifndef MAIN_MENU_H
#define MAIN_MENU_H
#include "main.h"

void start_menu(user_pos *user);

typedef struct {
    int game_grid_matrix[12][12];
    int gems_in_grid;
} game_grid;
#endif //MAIN_MENU_H
