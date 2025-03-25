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
#include "main.h"



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
    user.replace_value = 48;
    generate_grid(game_matrix);
    int game_menu_choice;
    bool moving = true;

    printf("Welcome to the mining game! \n");
    do {
        printf("Menu:\n");
        printf("1. Create a new game\n");
        printf("2. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &menu_choice);

        if (menu_choice == 1) {

            output_grid(game_matrix);

            do {
                printf("\n\nWhat would you like to do?\n");
                printf("1. Move character\n");
                printf("2. Dig!\n");
                printf("3. Stop game\n");
                printf("Enter your choice: ");
                scanf("%d", &game_menu_choice);

                if (game_menu_choice == 1) {
                    do {
                        printf("\nEnter your move or press q to stop: ");
                        scanf(" %c", &user_move);

                        player_move(game_matrix, user_move, &user, &moving);
                        output_grid(game_matrix);
                    } while (moving);
                } else if (game_menu_choice == 2) {
                    printf("Function not built yet!");
                } else if (game_menu_choice == 3) {
                    printf("Returning to menu");
                    game_live = false;
                }


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