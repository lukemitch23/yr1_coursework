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

void end_stats(user_pos *user) {
 char username[50];
 FILE *fp;

 printf("\n You successfully collected: %d gems across your time player!", user->gem_count);
 printf("\n Enter your username so we can save the score: ");
 scanf("%s", username);

 fp = fopen("user_scores.txt", "a");
 if (fp == NULL) {
  printf("We encountered an error in saving sorry!");
 }
 fprintf(fp, "Username: %s, Gems: %d\n", username, user->gem_count);
 fclose(fp);
 printf("\nScore saved the game will now quit.");
 Sleep(2000);
}