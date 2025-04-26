/*
Project title:
 Description:
 Inputs: none
 Outputs: none
 Date:
 Author: Luke Mitchell
*/

#include <stdio.h>
#include <stdbool.h>
#include "main.h"
#include <conio.h>
#include <windows.h>
#include "end_stats.h"
#include "initial_shop.h"


int main(void) {
    int ch, menu_choice=1, num_options=2, game_running=true, game_ran = false;
    user_pos user;
    user.x = 0;
    user.y = 0;
    user.gem_count = 0;
    user.replace_value = 48;
    user.money = 500;
    user.stamina = 100;
    user.total_gems_collected = 0;
    user.energy_drinks = 0;

    do {
        printf("\n");
        printf("   ____                                   _  _        __  __  _         _               \n");
        printf("  / __ \\                                 | |(_)      |  \\/  |(_)       (_)              \n");
        printf(" | |  | | _ __  ___   ___   _ __    ___  | | _  ___  | \\  / | _  _ __   _  _ __    __ _ \n");
        printf(" | |  | || '__|/ _ \\ / _ \\ | '_ \\  / _ \\ | || |/ __| | |\\/| || || '_ \\ | || '_ \\  / _` |\n");
        printf(" | |__| || |  |  __/| (_) || |_) || (_) || || |\\__ \\ | |  | || || | | || || | | || (_| |\n");
        printf("  \\____/ |_|   \\___| \\___/ | .__/  \\___/ |_||_||___/ |_|  |_||_||_| |_||_||_| |_| \\__, |\n");
        printf("                           | |                                                     __/ |\n");
        printf("                           |_|                                                    |___/ \n");

        printf("Welcome to the mining game!\n");
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
                printf("\n");
                printf("   ____                                   _  _        __  __  _         _               \n");
                printf("  / __ \\                                 | |(_)      |  \\/  |(_)       (_)              \n");
                printf(" | |  | | _ __  ___   ___   _ __    ___  | | _  ___  | \\  / | _  _ __   _  _ __    __ _ \n");
                printf(" | |  | || '__|/ _ \\ / _ \\ | '_ \\  / _ \\ | || |/ __| | |\\/| || || '_ \\ | || '_ \\  / _` |\n");
                printf(" | |__| || |  |  __/| (_) || |_) || (_) || || |\\__ \\ | |  | || || | | || || | | || (_| |\n");
                printf("  \\____/ |_|   \\___| \\___/ | .__/  \\___/ |_||_||___/ |_|  |_||_||_| |_||_||_| |_| \\__, |\n");
                printf("                           | |                                                     __/ |\n");
                printf("                           |_|                                                    |___/ \n");
                printf("Welcome to the mining game!\n");
                printf("Select an option and press ENTER to confirm:\n");
            } else if (ch == 13 || ch == 32) {
                game_running = false;
            }
        }
    } while (game_running);

    switch (menu_choice) {
        case 1:
            game_ran = true;
            game_start_shop(&user);
            // goto end_game;
            // break;
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