/*
Project title: 
 Description: 
 Inputs: none
 Outputs: none
 Date: 
 Author: Luke Mitchell
*/

#include <stdio.h>
#include "main.h"
#include "ascii_art.h"
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include "main_menu.h"




void game_start_shop(user_pos *user){
 bool welcome_accepted = false;
 int ch;
 system("cls");
 starting_shop_text();

 printf("Welcome to the starting shop, lets get you equipped!\n");
 system("pause");

 bool tool_chosen = false;
 int selected =1;
 int num_options = 3;
 do {
  system("cls");
  shop_tools_text();

  printf("\n\nRight lets get you started by picking a tool\n");
  printf("Starting money: %d \n\n", user->money);
  printf("%s 1. Pickaxe\n", (selected == 1 ? "->" : "  "));
  printf("\t Trustly and reliable....\n");
  printf("%s 2. Shovel \n", (selected == 2 ? "->" : "  "));
  printf("\t Time consuming but that care and attention could be beneficial.\n");
  printf("%s 3. Drill\n", (selected == 3 ? "->" : "  "));
  printf("\t Brutal and costly but efficient.\n");

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
   tool_chosen = true;
  }
 } while (!tool_chosen);

 switch (selected) {
  case 1:
   printf("Pickaxe, great choice!\n");
   user->money = user->money - 50;
  user->tool_carry = 1;
  system("pause");
  break;

  case 2:
   printf("Shovel, great choice!\n");
  user->money = user->money - 100;
  user->tool_carry = 2;
  system("pause");
  break;

  case 3:
   printf("Drill, great choice!\n");
  user->money = user->money - 200;
  user->tool_carry = 3;
  system("pause");
  break;
 }

 bool power_up_chosen = false;
 int pu_selected = 1;
 do {
  system("cls");
  shop_power_up_text();

  printf("Welcome to the shop, pick an option!\n");
  printf("Current money: %d \n\n", user->money);
  printf("%s 1. Gem bonus chance\n", (pu_selected == 1 ? "->" : "  "));
  printf("\t Any gems you find have a chance of being multiple\n");
  printf("%s 2. Starting additional stamina\n", (pu_selected == 2 ? "->" : "  "));
  printf("\t Go down the mine with additional stamina to keep working longer\n");
  printf("%s 3. 3x Energy drinks\n", (pu_selected == 3 ? "->" : "  "));
  printf("\t A quick and easy way to refuel your stamina\n");

  ch = getch();
  if (ch == 0 || ch == 224) {
   ch = getch();
   if (ch == 72) { // Up arrow key
    pu_selected--;
    if (pu_selected < 1) {
     pu_selected = num_options;
    }
   } else if (ch == 80) { // Down arrow key
    pu_selected++;
    if (pu_selected > num_options) {
     pu_selected = 1;
    }
   }
  } else if (ch == 13 || ch == 32) { // Enter or Space key to select
   power_up_chosen = true;
  }
 } while (!power_up_chosen);

 switch (pu_selected) {
  case 1:
   printf("Gem bonus, great choice!\n");
   user->money = user->money - 50;
   user->power_up_carry = 1;
  break;

  case 2:
   printf("Stamina, great choice!\n");
   user->money = user->money - 150;
   user->power_up_carry = 2;
  break;

  case 3:
   printf("Energy drinks, great choice!\n");
   user->money = user->money - 100;
   user->power_up_carry = 3;
   user->energy_drinks = 3;
  break;
 }

 printf("\nThanks for picking, you finished with %d remaining in your account! Enjoy mining!\n ", user->money);
 system("pause");
 start_menu(user);
}
