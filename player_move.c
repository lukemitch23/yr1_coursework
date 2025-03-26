/*
Project title: 
 Description: 
 Inputs: none
 Outputs: none
 Date: 
 Author: Luke Mitchell
*/

#include <stdio.h>
#include "output_grid.h"
#include "main.h"
#include <stdbool.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "mining.h"




// Note here to check back and see whether or not we need both game_live and running

void player_move(int (*game_matrix)[12], user_pos *user, bool *moving) {
  // if (user_move == 'w') {
  //     if (user->x == 0) {
  //         printf("Invalid move \n");
  //     } else {
  //         user->store_value = game_matrix[user->x-1][user->y];
  //         game_matrix[user->x][user->y] = user->replace_value;
  //         user->x--;
  //         game_matrix[user->x][user->y] = 80;
  //         user->replace_value = user->store_value;
  //     }
  // } else if (user_move == 's') {
  //     if (user->x == 11) {
  //         printf("Invalid move \n");
  //     } else {
  //         user->store_value = game_matrix[user->x+1][user->y];
  //         game_matrix[user->x][user->y] = user->replace_value;
  //         user->x++;
  //         game_matrix[user->x][user->y] = 80;
  //         user->replace_value = user->store_value;
  //     }
  // } else if (user_move == 'a') {
  //     if (user->y == 0) {
  //         printf("Invalid move \n");
  //     } else {
  //         user->store_value = game_matrix[user->x][user->y-1];
  //         game_matrix[user->x][user->y] = user->replace_value;
  //         user->y--;
  //         game_matrix[user->x][user->y] = 80;
  //         user->replace_value = user->store_value;
  //     }
  // } else if (user_move == 'd') {
  //     if (user->y == 11) {
  //         printf("Invalid move \n");
  //     } else {
  //         user->store_value = game_matrix[user->x][user->y+1];
  //         game_matrix[user->x][user->y] = user->replace_value;
  //         user->y++;
  //         game_matrix[user->x][user->y] = 80;
  //         user->replace_value = user->store_value;
  //
  //     }
  // } else if (user_move == 'q') {
  //     *moving = false;
  // }
    int ch;
    bool update_required;
    printf("Use the arrow keys to move or esc to escape\n");
    do {
        ch = getch();
        if (ch == 27) {  // ESC key
            *moving = false;
            break;
        }

        if (ch == 13) {  // Enter key (ASCII 13)
            // *moving = false;
            spot_mining(game_matrix, user);
            break;
        }

        if (ch == 0 || ch == 224) {  // Arrow key indicator
            ch = getch();
            switch (ch) {
                case 72:  // Up arrow
                    if (user->x == 0) {
                        printf("Invalid move \n");
                    } else {
                        user->store_value = game_matrix[user->x-1][user->y];
                        game_matrix[user->x][user->y] = user->replace_value;
                        user->x--;
                        game_matrix[user->x][user->y] = 80;
                        user->replace_value = user->store_value;
                    }
                    break;
                case 80:  // Down arrow
                    if (user->x == 11) {
                        printf("Invalid move \n");
                    } else {
                        user->store_value = game_matrix[user->x+1][user->y];
                        game_matrix[user->x][user->y] = user->replace_value;
                        user->x++;
                        game_matrix[user->x][user->y] = 80;
                        user->replace_value = user->store_value;
                    }
                    break;
                case 75:  // Left arrow
                    if (user->y == 0) {
                        printf("Invalid move \n");
                    } else {
                        user->store_value = game_matrix[user->x][user->y-1];
                        game_matrix[user->x][user->y] = user->replace_value;
                        user->y--;
                        game_matrix[user->x][user->y] = 80;
                        user->replace_value = user->store_value;
                    }
                    break;
                case 77:  // Right arrow
                    if (user->y == 11) {
                        printf("Invalid move \n");
                    } else {
                        user->store_value = game_matrix[user->x][user->y+1];
                        game_matrix[user->x][user->y] = user->replace_value;
                        user->y++;
                        game_matrix[user->x][user->y] = 80;
                        user->replace_value = user->store_value;
                    }
                    break;
                default:
                    printf("Unhandled key: %d\n", ch);
                    break;
            }
            Sleep(200);  // Wait for 200ms to prevent spamming
        }
        system("cls");
        output_grid(game_matrix);
    } while (*moving);
}