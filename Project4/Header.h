#pragma once
#ifndef HEADER1
#define HEADER1

#include <stdio.h>
#include <stdlib.h>


void init_matrix(void);
void display_matrix(void);
void get_player_move(char X);
void get_computer_move(char X);
char check(void);
#endif