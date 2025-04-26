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
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "end_stats.h"
#include "main_menu.h"

void spot_mining(game_grid *game_matrix, user_pos *user){
 srand(time(NULL));
 int stamina_cost = 0;
 if (user->store_value == 42) {
  printf("Gem found!\n");
  if (user->power_up_carry == 1) {
   int gem_bonus = rand() % 9 + 1 ;
   switch (gem_bonus) {
    case 1 ... 6:
     gem_bonus = 1;
     printf("Your bonus didn't cash in this time sadly! Only one gem found.\n");
     user->gem_count += gem_bonus;
     user->total_gems_collected++;
     break;
    case 7 ... 9:
     gem_bonus = 2;
     printf("Your bonus is paying off, it turned out to be %d gems\n", gem_bonus);
     user->gem_count += gem_bonus;
     user->total_gems_collected++;
     break;
    case 10:
     gem_bonus = 3;
     printf("Your bonus is paying off, it turned out to be %d gems\n", gem_bonus);
     user->gem_count += gem_bonus;
     user->total_gems_collected++;
     break;
   }
  } else {
   user->gem_count = user->gem_count + 1;
   user->total_gems_collected++;
  }

  game_matrix->gems_in_grid--;
  printf("You now have %d gems!\n", user->gem_count);
  user->replace_value = 48;
  user->store_value = 48;
  stamina_cost = (rand() % 3) + 1;
  switch (stamina_cost) {
   case 1:
    if (user->stamina > 5) {
     printf("\nThat was easy! You only lost 5 stamina!");
     user->stamina = user->stamina - 5;
     printf("\nCurrent stamina: %d", user->stamina);
    } else {
     printf("Unfortunately that was the last of your stamina!");
     Sleep(2000);
     end_stats(user);
     break;
    }
    break;

   case 2:
    if (user->stamina > 10) {
     printf("\nThat was quite taxing! You lost 10 stamina!");
     user->stamina = user->stamina - 10;
     printf("\nCurrent stamina: %d", user->stamina);
    } else {
     printf("Unfortunately that was the last of your stamina!");
     Sleep(2000);
     end_stats(user);
     break;
    }
    break;

   case 3:
    if (user->stamina > 15) {
    printf("\nThat was really tough! You lost 15 stamina");
     user->stamina = user->stamina - 15;
     printf("\nCurrent stamina: %d", user->stamina);
    } else {
     printf("Unfortunately that was the last of your stamina!");
     Sleep(2000);
     end_stats(user);
     break;
    }
    break;

  }
 } else {
  printf("\nNo gems found!\n");
 }
 Sleep(3000);
}
