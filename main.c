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
#include "mining.h"
#include <conio.h>




int main(void) {
    bool running = true;
    bool game_live = true;
    int game_matrix[12][12];
    int menu_choice;
    char user_move;
    user_pos user;
    user.x = 0;
    user.y = 0;
    user.replace_value = 48;
    generate_grid(game_matrix);
    int game_menu_choice = 0;
    int selected = 1;
    int ch;
    int num_options = 4;
    int valid = 0;
    bool moving = true;
    int gem_count = 0;

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
                incorrect_choice:
                game_live = true;
                printf("\n\nWhat would you like to do?\n");
                printf("1. Move character\n");
                printf("2. Dig!\n");
                printf("3. See inventory \n");
                printf("4. Stop game\n");
                printf("Enter your choice: ");
                scanf("%d", &game_menu_choice);

                if (game_menu_choice == 1) {
                    do {
                        moving = true;
                        output_grid(game_matrix);
                        player_move(game_matrix, &user, &moving, &gem_count);
                    } while (moving);
                } else if (game_menu_choice == 2) {
                    spot_mining(game_matrix, &user, &gem_count);
                } else if (game_menu_choice == 3) {
                    printf("You currently have %d gems!", gem_count);
                } else if (game_menu_choice == 4) {
                    printf("Returning to menu");
                    game_live = false;
                } else {
                    printf("Invalid choice, please try again.\n");
                    getchar();
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

    return 0;
}