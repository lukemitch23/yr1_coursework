/*
Project title:
 Description:
 Inputs: none
 Outputs: none
 Date:
 Author: Luke Mitchell
*/

#include <stdio.h>
#include "grid_generation.h"
#include "output_grid.h"
#include "player_move.h"
#include <stdbool.h>

typedef struct {
    int x;
    int y;
    char value;
} user_pos;

typedef struct {
    int x;
    int y;
    char value;
} prev_pos;

int main(void) {
    bool running = true;
    bool game_live = true;
    int game_matrix[12][12];
    int count = 0;
    int menu_choice;
    char user_move;
    user_pos user;
    user.x = 0;
    user.y = 0;
    user.value = '0';
    prev_pos prev;
    generate_grid(game_matrix);


    do {
        printf("Welcome to the mining game! \n");
        printf("Menu:\n");
        printf("1. Create a new game\n");
        printf("2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &menu_choice);

        if (menu_choice == 1) {

            output_grid(game_matrix);

            do {
                printf("\nEnter your move: ");
                scanf(" %c", &user_move);

                prev.x = user.x;
                prev.y = user.y;
                if (user_move == 'w') {
                    if (user.x == 0) {
                        printf("Invalid move \n");
                    } else {
                        printf("Old spot now x is: %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 88;
                        user.x--;
                        printf("P position should be %d, %d\n", user.x, user.y);
                        game_matrix[user.x][user.y] = 80;
                    }
                } else if (user_move == 's') {
                    if (user.x == 11) {
                        printf("Invalid move \n");
                    } else {
                        printf("Old spot now x is: %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 88;
                        user.x++;
                        printf("P position should be %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 80;
                    }
                } else if (user_move == 'a') {
                    if (user.y == 0) {
                        printf("Invalid move \n");
                    } else {
                        printf("Old spot now x is: %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 88;
                        user.y--;
                        printf("P position should be %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 80;
                    }
                } else if (user_move == 'd') {
                    if (user.y == 11) {
                        printf("Invalid move \n");
                    } else {
                        printf("Old spot now x is: %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 88;
                        user.y++;
                        printf("P position should be %d, %d", user.x, user.y);
                        game_matrix[user.x][user.y] = 80;
                    }
                } else if (user_move == 'q') {
                    running = false;
                    game_live = false;
                }
                output_grid(game_matrix);
            } while (game_live);
        } else if (menu_choice == 2) {
            printf("Quitting...\n");
            running = false;
        } else {
            printf("Error, choose again!");
            continue;
        }
    } while (running);

    // // Print the top border
    // printf("+----");
    // for (int j = 0; j < 12; j++) {
    //     printf("----");
    // }
    // printf("+\n");
    //
    // // Print the matrix with borders
    // for (int i = 0; i < 12; i++) {
    //     printf("| ");  // Left border
    //     for (int j = 0; j < 12; j++) {
    //         printf("%2c|", game_matrix[i][j]);  // Print each number with spacing and right border
    //     }
    //     printf("\n");
    //
    //     // Print row separator
    //     printf("+----");
    //     for (int j = 0; j < 12; j++) {
    //         printf("----");
    //     }
    //     printf("+\n");
    // }

    return 0;
}