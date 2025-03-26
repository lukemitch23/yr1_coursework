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

void spot_mining(int (*game_matrix)[12], user_pos *user){
 if (user->store_value == 42) {
  printf("Gem found!\t");
  user->gem_count = user->gem_count + 1;
  printf("You now have %d gems!\n", user->gem_count);
  user->replace_value = 48;
  user->store_value = 48;
 } else {
  printf("\nNo gems found!\n");
 }
 Sleep(2000);
}
