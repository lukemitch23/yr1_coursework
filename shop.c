/*
Project title: 
 Description: 
 Inputs: none
 Outputs: none
 Date: 
 Author: Luke Mitchell (modified by ChatGPT)
*/

#include <stdio.h>
#include "main.h"
#include <stdbool.h>
#include <conio.h>
#include <iso646.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void shop(user_pos *user, bool *shop_open) {
    int selected = 1;
    int num_options = 3;
    int gems_to_sell = 0;
    int ch;

    srand(time(NULL)); // Ideally, you should call srand only once in your program

    *shop_open = true;
    while (*shop_open) {
        // Reset the input loop flag each time the menu is re-displayed
        bool valid = true;

        // Display the menu and handle key navigation
        do {
            system("cls");
            printf("Welcome to the shop, pick an option!\n");
            printf("Current money: %d \n\n", user->money);
            printf("%s 1. Sell gems\n", (selected == 1 ? "->" : "  "));
            printf("%s 2. Buy power ups!\n", (selected == 2 ? "->" : "  "));
            printf("%s 3. Return to game\n", (selected == 3 ? "->" : "  "));

            ch = getch();
            if (ch == 0 || ch == 224) {
                ch = getch();
                if (ch == 72) { // Up arrow key
                    selected--;
                    if (selected < 1) {
                        selected = num_options;
                    }
                } else if (ch == 80) { // Down arrow key
                    selected++;
                    if (selected > num_options) {
                        selected = 1;
                    }
                }
            } else if (ch == 13 || ch == 32) { // Enter or Space key to select
                valid = false;
            }
        } while (valid);

        // Process the selected menu option
        switch (selected) {
            case 1: {
                int price_of_gems = (rand() % 50) + 50;
                system("cls");
                printf("The current price of gems is: %d (per gem)\n", price_of_gems);
                if (user->gem_count > 0) {
                    printf("You currently have %d gems, how many do you want to sell: ", user->gem_count);
                    scanf("%d", &gems_to_sell);
                    while (gems_to_sell > user->gem_count) {
                        printf("\nYou don't have that many gems!\n");
                        printf("You currently have %d gems, how many do you want to sell: ", user->gem_count);
                        scanf("%d", &gems_to_sell);
                    }
                    int money_made = gems_to_sell * price_of_gems;
                    user->gem_count = user->gem_count - gems_to_sell;
                    user->money += money_made;
                    printf("You made %d and now have %d in total.\n", money_made, user->money);
                    printf("You now have %d gems left\n", user->gem_count);
                } else {
                    printf("Sorry, you don't have any gems to sell!\n");
                }
                printf("\nPress any key to return to the shop menu...");
                getch();
                break;
            }
            case 2: {
                system("cls");
                printf("Feature not built yet!\n");
                printf("\nPress any key to return to the shop menu...");
                getch();
                break;
            }
            case 3: {
                system("cls");
                printf("Returning to the main game...\n");
                Sleep(1000);
                *shop_open = false; // This will break the loop and return to main menu
                break;
            }
        }
    }
}
