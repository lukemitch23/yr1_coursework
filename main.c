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

int main(void) {
    int game_matrix[12][12];
    int count = 0;

    generate_grid(game_matrix);

    // Print the top border
    printf("+----");
    for (int j = 0; j < 12; j++) {
        printf("----");
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
        printf("+----");
        for (int j = 0; j < 12; j++) {
            printf("----");
        }
        printf("+\n");
    }

    return 0;
}