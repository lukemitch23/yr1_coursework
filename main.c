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
#include <windows.h>
#include "main_menu.h"
#include "end_stats.h"




int main(void) {
    int ch, menu_choice=1, num_options=2, game_running=true, game_ran = false;
    user_pos user;
    user.x = 0;
    user.y = 0;
    user.gem_count = 0;
    user.replace_value = 48;
    user.money = 0;

    do {
        printf("Welcome to the mining game!\n");
        system("cls");
        printf("Select an option and press ENTER to confirm:\n");
        while (game_running) {
            printf("%s 1. Begin game\n", (menu_choice ==1 ? "->":"  "));
            printf("%s 2. Exit\n", (menu_choice ==2 ? "->":"  "));

            ch = getch();
            if (ch == 0 || ch == 224) {
                ch = getch();
                if (ch == 72) {
                    menu_choice--;
                    if (menu_choice < 1) {
                        menu_choice = num_options;
                    }
                } else if (ch == 80) {
                    menu_choice++;
                    if (menu_choice > num_options) {
                        menu_choice = 1;
                    }
                }
                system("cls");
                printf("Welcome to the mining game!\n");
            } else if (ch == 13 || ch == 32) {
                game_running = false;
            }
        }
    } while (game_running);

    switch (menu_choice) {
        case 1:
            game_ran = true;
            start_menu(&user);
            goto end_game;
            break;
        case 2:
            end_game:
                if (game_ran) {
                    printf("Thanks for playing!\n");
                    end_stats(&user);
                } else {
                    printf("Take care!");
                }
                Sleep(2000);
                return 0;
    }


    return 0;
}