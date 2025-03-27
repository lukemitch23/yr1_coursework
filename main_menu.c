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
#include "shop.h"
#include "end_stats.h"
#include <uchar.h>
#include "ascii_art.h"

void start_menu(user_pos *user) {
    bool game_live = true;
    int game_matrix[12][12];
    bool shop_open = false;

    generate_grid(game_matrix);

    int game_menu_choice = 0;
    int selected = 1;
    int ch;
    int num_options = 5;
    int valid = 0;
    bool moving = true;

    output_grid(game_matrix);

    do {
        game_live = true;
        // Reset the arrow-key menu variables.
        valid = 0;
        selected = 1;

        if (user->stamina <= 0) {
            printf("You have run out of stamina! The game will now end\n");
            end_stats(user);
        }
        // Use arrow keys to select a menu option.
        // Clear the screen (Windows-specific).
        system("cls");
        main_text();

        printf("\n\nWhat would you like to do?\n");
        while (!valid) {
            // Display menu options with pointer
            printf("%s 1. Move character \n", (selected == 1 ? "->" : "  "));
            printf("%s 2. Dig!\n", (selected == 2 ? "->" : "  "));
            printf("%s 3. Player inventory\n", (selected == 3 ? "->" : "  "));
            printf("%s 4. Shop\n", (selected == 4 ? "->" : "  "));
            printf("%s 5. Stop game\n", (selected == 5 ? "->" : "  "));
            printf("\nUse up/down arrow keys to navigate, then press SPACE or ENTER to select.\n");

            ch = getch();
            if (ch == 0 || ch == 224) {  // Arrow key prefix
                ch = getch();
                if (ch == 72) { // Up arrow
                    selected--;
                    if (selected < 1)
                        selected = num_options;
                } else if (ch == 80) { // Down arrow
                    selected++;
                    if (selected > num_options)
                        selected = 1;
                }
                // Clear the console and re-display the menu:
                system("cls");
                main_text();

                printf("\n\nWhat would you like to do?\n");
            } else if (ch == 13 || ch == 32) {  // ENTER (13) or SPACE (32)
                valid = 1;
            }
        } // End arrow-key menu loop

        game_menu_choice = selected;

        // Execute action based on the menu choice.
        switch (game_menu_choice) {
            case 1:
                // Move character: This loop calls player_move until 'moving' becomes false.
                do {
                    moving = true;
                    system("cls");
                    output_grid(game_matrix);
                    player_move(game_matrix, user, &moving);
                } while (moving);
                break;
            case 2:
                // Dig!
                spot_mining(game_matrix, user);
                break;
            case 3:
                system("cls");
                inventory_text();

                // Inventory: Show gem count.
                printf("You currently have %d gems!\n", user->gem_count);
                printf("Bank balance: %d\n", user->money);
                printf("Current stamina %d/100\n", user->stamina);
                system("pause"); // Wait for user to press a key.
                break;
            case 4:
                shop_open = true;
                do {
                    shop(user, &shop_open);
                } while (shop_open);
                break;
            case 5:
                // Stop game: Return to the main menu.
                printf("Returning to menu\n");
                game_live = false;
                break;
            default:
                printf("Invalid choice, please try again.\n");
                getchar();
                break;
        }
    } while (game_live);
}