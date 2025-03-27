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

int end_stats(user_pos *user) {
 system("cls");
 char username[50];
 FILE *fp;

 printf("\nYou successfully collected: %d gems across your time player!", user->total_gems_collected);
 printf("\nYou died with %d gems on your person, these will be sold off at 25 per gem", user->gem_count);

 user->money = user->money + (user->gem_count * 25);
 printf("\nYou ended up making %d money", user->money);
 printf("\nEnter your username so we can save the score: ");
 scanf("%s", username);

 fp = fopen("user_scores.txt", "a");
 if (fp == NULL) {
  printf("We encountered an error in saving sorry!");
 }
 fprintf(fp, "Username: %s, Gems: %d, Money: %d\n", username, user->gem_count, user->money);
 fclose(fp);
 printf("\nScore saved the game will now quit.");
 Sleep(2000);
 system("exit");
 exit(0);
}