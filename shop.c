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
#include "ascii_art.h"

void shop(user_pos *user, bool *shop_open) {
    int selected = 1;
    int num_options = 3;
    int gems_to_sell = 0;
    int ch;

    srand(time(NULL)); // Ideally, you should call srand only once in your program
    store_home:
    *shop_open = true;
    while (*shop_open) {
        // Reset the input loop flag each time the menu is re-displayed
        bool valid = true;

        // Display the menu and handle key navigation
        do {
            system("cls");
            shop_text();

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
                shop_text();
                printf("The current price of gems is: %d (per gem)\n", price_of_gems);
                if (user->gem_count > 0) {
                    printf("You currently have %d gems, how many do you want to sell: ", user->gem_count);
                    scanf("%d", &gems_to_sell);
                    while (gems_to_sell > user->gem_count || gems_to_sell < 0) {
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

                int stamina_price = (rand() % 100) + 100;
                int buy_ch;
                int buy_selected = 1;
                int by_num_options = 2;
                int buy_valid = true;
                int stamina_to_buy = 0;

                if (user->money == 0 || user->money < stamina_price) {
                    printf("You don't have enough money or gems to buy things!");
                    Sleep(2000);
                    break;
                }

                do {
                    system("cls");
                    shop_text();

                    printf("What would you like to buy? You have %d\n", user->money);
                    while (buy_valid) {
                        printf("%s 1. Stamina \n", (buy_selected == 1 ? "->" : "  "));
                        printf("%s 2. Product to come!\n", (buy_selected == 2 ? "->" : "  "));
                        printf("%s 3. Return to shop home\n", (buy_selected == 3 ? "->" : "  "));

                        buy_ch = getch();
                        if (buy_ch == 27) {
                            buy_valid = false;
                            valid = true;
                            goto store_home;
                        }
                        if (buy_ch == 0 || buy_ch == 224) {
                            buy_ch = getch();
                            if (buy_ch == 72) {
                                buy_selected--;
                                if (buy_selected < 1) {
                                    buy_selected = by_num_options;
                                }
                            } else if (buy_ch == 80) {
                                buy_selected++;
                                if (buy_selected > by_num_options) {
                                    buy_selected = 1;
                                }
                            }
                            system("cls");
                            shop_text();

                            printf("What would you like to buy?");
                        } else if (buy_ch == 13 || buy_ch == 32) {
                            buy_valid = false;
                        }
                    }

                    int buy_menu_choice = buy_selected;
                    switch (buy_menu_choice) {
                        case 1:
                            system("cls");
                            shop_text();

                        printf("\n20 stamina costs %d, how much do you want to buy considering you have %d: ", stamina_price, user->money);
                        scanf("%d", &stamina_to_buy);

                        while (stamina_to_buy <= 0){
                            printf("\n20 stamina costs %d, how much do you want to buy considering you have %d: ", stamina_price, user->money);
                            scanf("%d", &stamina_to_buy);
                        }

                        while (user->money < (stamina_to_buy * stamina_price)) {
                            printf("\nYou can't afford that much!");
                            printf("\n20 stamina costs %d, how much do you want to buy considering you have %d: ", stamina_price, user->money);
                            scanf("%d", &stamina_to_buy);
                        }

                        user->stamina = user->stamina + (stamina_to_buy * 20);
                        user->money = user->money - (stamina_to_buy * stamina_price);

                        printf("\n%d Stamina bought, your stamina is now: %d", (stamina_to_buy*20), user->stamina);
                    }
                    Sleep(3000);
                } while (buy_valid);
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
