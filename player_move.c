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

// Note here to check back and see whether or not we need both game_live and running

void player_move(int (*game_matrix)[12], char user_move, user_pos *user, bool *running, bool *game_live) {
  if (user_move == 'w') {
      if (user->x == 0) {
          printf("Invalid move \n");
      } else {
          game_matrix[user->x][user->y] = 88;
          user->x--;
          game_matrix[user->x][user->y] = 80;
      }
  } else if (user_move == 's') {
      if (user->x == 11) {
          printf("Invalid move \n");
      } else {
          game_matrix[user->x][user->y] = 88;
          user->x++;
          game_matrix[user->x][user->y] = 80;
      } 
  } else if (user_move == 'a') {
      if (user->y == 0) {
          printf("Invalid move \n");
      } else {
          game_matrix[user->x][user->y] = 88;
          user->y--;
          game_matrix[user->x][user->y] = 80;
      }
  } else if (user_move == 'd') {
      if (user->y == 11) {
          printf("Invalid move \n");
      } else {
          game_matrix[user->x][user->y] = 88;
          user->y++;
          game_matrix[user->x][user->y] = 80;
      }
  } else if (user_move == 'q') {
      printf("Quitting ...\n");
      *running = false;
      *game_live = false;
  }
}