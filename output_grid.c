/*
Project title: 
 Description: 
 Inputs: none
 Outputs: none
 Date: 
 Author: Luke Mitchell
*/

#include <stdio.h>

void output_grid(int (*game_matrix)[12]) {
 // Print the top border
 printf("+---");
 for (int j = 0; j < 12; j++) {
  printf("---");
 }
 printf("+\n");

 // Print the matrix with borders
 for (int i = 0; i < 12; i++) {
  printf("| ");  // Left border
  for (int j = 0; j < 12; j++) {
   printf("%2c|", game_matrix[i][j]);  // Print each number with spacing and right border
  }
  printf("\n");

  // Print row separator
  printf("+---");
  for (int j = 0; j < 12; j++) {
   printf("---");
  }
  printf("+\n");
 }
}
