/*
Project title: 
 Description: 
 Inputs: none
 Outputs: none
 Date: 
 Author: Luke Mitchell
*/

#include <stdlib.h>
#include <time.h>
#include "grid_generation.h"
#include <stdio.h>

// Function that generates a 12x12 grid using the provided pointer parameter.
// The grid is filled with ascii codes: '0' (48), '*' (42), and a starting 'P' (80) at game_matrix[0][0].
void generate_grid(int (*game_matrix)[12]) {
 int count = 0;
 int gem_distributor = 6;
 int blockage_count = 0;
 int blockage_distributor = 6;
 // Seed the random number generator
 srand(time(NULL));

 // Fill the matrix with random numbers (using ascii values)
 for (int i = 0; i < 12; i++) {
  for (int j = 0; j < 12; j++) {
   int random_number = rand() % 3 + 48;  // Generates ascii codes for '0'-'9'
   if (random_number == 49) {             // If ascii value equals '1'
    if (count < 12) {
     if (gem_distributor == 0) {
      game_matrix[i][j] = 42;        // '*' (asterisk)
      count++;
      gem_distributor = 6;
     } else {
      gem_distributor--;
      game_matrix[i][j] = 42;
     }
    } else {
     game_matrix[i][j] = 48;        // '0'
    }
   } else if (random_number > 49){
    if (blockage_count < 8) {
     if (blockage_distributor == 0) {
      blockage_count++;
      game_matrix[i][j] = 178;
      blockage_distributor = 6;
     } else {
      blockage_distributor--;
      game_matrix[i][j] = 48;
     }
    } else {
     game_matrix[i][j] = 48;
    }
  } else{
    game_matrix[i][j] = 48;            // '0'
   }
  }
 }

 // Set the first element to 'P' (ascii 80)
 game_matrix[0][0] = 80;
}

