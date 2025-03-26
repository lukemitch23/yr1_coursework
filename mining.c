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

void spot_mining(int (*game_matrix)[12], user_pos *user, int *gem_count){
 if (user->store_value == 42) {
  printf("Gem found!\t");
  *gem_count = *gem_count + 1;
  printf("You now have %d gems!", *gem_count);
  user->replace_value = 48;
 } else {
  printf("\nNo gems found!");
 }
}
