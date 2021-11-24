#include "Header.h"

int main(void) {
	char done = ' ';
	char X;
	printf("Tic-Tac Game.\n");
	printf("You will play with computer\n");
	printf("Who will you play for(X/0): ");
	X = getchar();
	init_matrix();

	if (X == 'X') {
		do {
			system("cls");
			display_matrix();
			get_player_move('X');
			done = check();
			if (done != ' ') break;
			get_computer_move('0');
			done = check();
		} while (done == ' ');
	}

	if (X == '0') {
		do {
			system("cls");
			get_computer_move('X');
			display_matrix();
			done = check();
			if (done != ' ') break;
			get_player_move('0');
			done = check();
		} while (done == ' ');
	}

	system("cls");
	display_matrix();
	if (done == 'X' && X == 'X') printf("\nYou win, congratulations! :O\n");
	if (done == '0' && X == 'X') printf("\nComputer win :c\n");
	if (done == '0' && X == '0') printf("\nYou win, congratulations! :O\n");
	if (done == 'X' && X == '0') printf("\nComputer win :c\n");
	if (done == 'D') printf("\nDraw\n");
	return 0;
}