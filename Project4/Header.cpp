#include "Header.h"

int turn = 0,turna = 0, turnb = 0;
char matrix[3][3];

/* Matrix init*/
void  init_matrix(void) {
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			matrix[i][j] = ' ';
		}
	}
}

// Проверяет наличие выиграшной комбинации любой из сторон
int win_check(char Turn1, char Turn2, char X) {
	int cou = 0;
	if ((matrix[0][0] == matrix[1][1] && matrix[0][0] == Turn1) || (matrix[1][1] == matrix[2][2] && matrix[1][1] == Turn1) || (matrix[0][0] == matrix[2][2] && matrix[0][0] == Turn1)) {
		if (matrix[0][0] == ' ') {
			matrix[0][0] = X;
			return 1;
		}
		else if (matrix[1][1] == ' ') {
			matrix[1][1] = X;
			return 1;
		}
		else if (matrix[2][2] == ' ') {
			matrix[2][2] = X;
			return 1;
		}
	}
	if ((matrix[0][2] == matrix[1][1] && matrix[0][2] == Turn1) || (matrix[1][1] == matrix[2][0] && matrix[1][1] == Turn1) || (matrix[0][2] == matrix[2][0] && matrix[0][2] == Turn1)) {
		if (matrix[2][0] == ' ') {
			matrix[2][0] = X;
			return 1;
		}
		else if (matrix[1][1] == ' ') {
			matrix[1][1] = X;
			return 1;
		}
		else if (matrix[0][2] == ' ') {
			matrix[0][2] = X;
			return 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] == Turn1) // 0 
				cou++;
			if (matrix[i][j] == Turn2) // X
				cou--;
		}
		if (cou == 2) {
			for (int j = 0; j < 3; j++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = X;
					return 1;
				}
			}
		}
		cou = 0;
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[j][i] == Turn1)
				cou++;
			if (matrix[j][i] == Turn2)
				cou--;
		}
		if (cou == 2) {
			for (int j = 0; j < 3; j++) {
				if (matrix[j][i] == ' ') {
					matrix[j][i] = X;
					return 1;
				}
			}
		}
		cou = 0;
	}
	return 0;
}


void display_matrix(void) {
	int t;
	for (t = 0; t < 3; t++) {
		printf(" %c | %c | %c ", matrix[t][0], matrix[t][1], matrix[t][2]);
		if (t != 2) {
			printf("\n---|---|---\n");
		}
	}
	printf("\n");
}


void get_player_move(char X) {
	int x, y;
	printf("Enter coordinates: ");
	scanf_s("%d%*c%d", &x, &y);
	x--;
	y--;
	if (matrix[x][y] != ' ') {
		printf("Wrong move. Try again\n");
		get_player_move(X);
	}
	else {
		matrix[x][y] = X;
	}
}


void get_computer_move(char X) {
	// Ход 1, если за Х
	if (X == 'X' && !turn) {
		matrix[1][1] = 'X';
		turn = 3;
		return;
	}
	// Ход 1, если за 0
	if (matrix[1][1] == ' ' && !turn) {
		matrix[1][1] = '0';
		turna++;
		turn++;
		return;
	}
	else if (!turn) {
		matrix[0][0] = X;
		turnb++;
		turn++;
		return;
	}
	// Ход 2 a
	if (turna == 1) {
		if (matrix[0][0] != ' ') {
			if (matrix[0][1] != ' ')
				matrix[0][2] = '0';
			else if (matrix[0][2] != ' ')
				matrix[0][1] = '0';
			else if (matrix[1][0] != ' ')
				matrix[2][0] = '0';
			else if (matrix[2][0] != ' ')
				matrix[1][0] = '0';
			else if (matrix[2][1] == ' ')
				matrix[2][1] = '0';
			else
				matrix[2][0] = '0';
		}
		else if (matrix[0][1] != ' ') {
			if (matrix[0][2] != ' ')
				matrix[0][0] = '0';
			else if (matrix[1][0] != ' ')
				matrix[0][0] = '0';
			else if (matrix[2][0] != ' ')
				matrix[1][0] = '0';
			else if (matrix[2][1] != ' ')
				matrix[1][0] = '0';
			else if (matrix[2][2] != ' ')
				matrix[1][2] = '0';
			else if (matrix[1][2] != ' ')
				matrix[2][2] = '0';
		}
		else if (matrix[0][2] != ' ') {
			if (matrix[1][0] != ' ')
				matrix[0][0] = '0';
			else if (matrix[2][0] != ' ')
				matrix[2][1] = '0';
			else if (matrix[2][1] != ' ')
				matrix[2][2] = '0';
			else if (matrix[2][2] != ' ')
				matrix[1][2] = '0';
			else if (matrix[1][2] != ' ')
				matrix[2][2] = '0';
		}
		else if (matrix[1][0] != ' ') {
			if (matrix[2][0] != ' ')
				matrix[0][0] = '0';
			else if (matrix[2][1] != ' ')
				matrix[2][0] = '0';
			else if (matrix[2][2] != ' ')
				matrix[2][0] = '0';
			else if (matrix[1][2] != ' ')
				matrix[0][2] = '0';
		}
		else if (matrix[1][2] != ' ') {
			if (matrix[2][0] != ' ')
				matrix[2][2] = '0';
			else if (matrix[2][1] != ' ')
				matrix[2][2] = '0';
			else if (matrix[2][2] != ' ')
				matrix[0][2] = '0';
		}
		else if (matrix[2][0] != ' ') {
			if (matrix[2][1] != ' ')
				matrix[2][2] = '0';
			else if (matrix[2][2] != ' ')
				matrix[2][1] = '0';
		}
		else if (matrix[2][1] != ' ') {
			if (matrix[2][2] != ' ')
				matrix[2][0] = '0';
		}
		turna++;
		turn++;
		return;
	}
	// Ход 2 b
	else if (turnb == 1) {
		if (matrix[0][2] != ' ')
			matrix[2][0] = '0';
		else if (matrix[2][0] != ' ')
			matrix[0][2] = '0';
		else if (matrix[0][1] != ' ')
			matrix[2][1] = '0';
		else if (matrix[1][0] != ' ')
			matrix[1][2] = '0';
		else if (matrix[1][2] != ' ')
			matrix[1][0] = '0';
		else if (matrix[2][1] != ' ')
			matrix[0][1] = '0';
		else matrix[2][0] = '0';
		turnb++;
		turn++;
		return;
	}
	// Ход 2, если начинать X
	if (turn == 3) {
		if (matrix[0][0] == '0' || matrix[2][2] == '0') 
			matrix[0][2] = 'X';
		else if (matrix[0][2] == '0' || matrix[2][0] == '0') 
			matrix[0][0] = 'X';
		else if (matrix[2][1] == '0' || matrix[1][2] == '0') 
			matrix[0][0] = 'X';
		else
			matrix[2][2] = 'X';
		turn = 2;
		return;
	}
	// Ход 3 и далее
	if (turn == 2) {
		if (win_check('X', '0', X))
			return;
		if (win_check('0', 'X', X))
			return;
		// Рандомит, если нет вариантов победы и Х не могут победить следующим ходом
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (matrix[i][j] == ' ') {
					matrix[i][j] = X;
					return;
				}
			}
		}
	}
}


char check(void) {
	int i, cou = 0;
	/* check raws*/
	for (i = 0; i < 3; i++) {
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2]) {
			return matrix[i][0];
		}
	}

	/* check columns */
	for (i = 0; i < 3; i++) {
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i]) {
			return matrix[0][i];
		}
	}

	/* check diagonales */
	if (matrix[0][0] == matrix[1][1] && matrix[0][0] == matrix[2][2]) {
		return matrix[0][0];
	}

	if (matrix[0][2] == matrix[1][1] && matrix[0][2] == matrix[2][0]) {
		return matrix[0][2];
	}
	for (i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (matrix[i][j] != ' ')
				cou++;
		}
	}
	if (cou == 9) return 'D';
	cou = 0;
	return ' ';
}