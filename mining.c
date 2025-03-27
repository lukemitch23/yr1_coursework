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

void spot_mining(int (*game_matrix)[12], user_pos *user){
 srand(time(NULL));
 int stamina_cost = 0;
 if (user->store_value == 42) {
  printf("Gem found!\t");
  user->gem_count = user->gem_count + 1;
  user->total_gems_collected++;
  printf("You now have %d gems!\n", user->gem_count);
  user->replace_value = 48;
  user->store_value = 48;
  stamina_cost = (rand() % 3) + 1;
  switch (stamina_cost) {
   case 1:
    printf("\nThat was easy! You only lost 5 stamina!");
    user->stamina = user->stamina - 5;
    printf("\nCurrent stamina: %d", user->stamina);
    break;

   case 2:
    printf("\nThat was quite taxing! You lost 10 stamina!");
    user->stamina = user->stamina - 10;
    printf("\nCurrent stamina: %d", user->stamina);
    break;

   case 3:
    printf("\nThat was really tough! You lost 15 stamina");
    user->stamina = user->stamina - 15;
    printf("\nCurrent stamina: %d", user->stamina);
    break;

  }
 } else {
  printf("\nNo gems found!\n");
 }
 Sleep(2000);
}
