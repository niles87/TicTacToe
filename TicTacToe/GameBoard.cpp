#include "GameBoard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard()
{
	clearBoard();
}

void GameBoard::playGame()
{
	char playerOne = 'X';
	char playerTwo = 'O';

	char currentPlayer = 'X';
	bool isDone = false;

	int x, y;
	int turn = 0;

	while (isDone == false) {
		printBoard();
		x = xCoord();
		y = yCoord();

		if (placeIdentifier(x, y, currentPlayer) == false) {
			cout << "That place is taken!!\n";
		}
		else {
			turn++;

			if (checkForWin(currentPlayer) == true) {
				cout << "The game is over! Player " << currentPlayer << " has one!!!" << endl;
				isDone = true;
				clearBoard();
			}
			else if (turn == 9) {
				cout << "Its a Tie!" << endl;
				isDone == true;
				clearBoard();
			}

			if (currentPlayer == playerOne) {
				currentPlayer = playerTwo;
			}
			else {
				currentPlayer = playerOne;
			}
		}
	}
}

int GameBoard::xCoord()
{
	bool badInput = true;
	int x;

	while (badInput) {
		cout << "\nEnter X coordinate: ";
		cin >> x;

		if (x < 1 || x > 3) {
			cout << "Invalid coordinate.\n";
		}
		else {
			badInput = false;
		}
		cout << endl;
	}
	return x - 1;
}

int GameBoard::yCoord()
{
	bool badInput = true;
	int y;

	while (badInput) {
		cout << "\nEnter Y coordinate: ";
		cin >> y;

		if (y < 1 || y > 3) {
			cout << "Invalid coordinate.\n";
		}
		else {
			badInput = false;
		}
		cout << endl;
	}
	return y - 1;
}

bool GameBoard::placeIdentifier(int x, int y, char currentPlayer)
{
	if (board[y][x] != ' ') {
		return false;
	}
	board[y][x] = currentPlayer;
	return true;
}

bool GameBoard::checkForWin(char currentPlayer)
{
	// Check Rows
	for (int i = 0; i < 3; i++) {

		if (board[i][0] == currentPlayer && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
			return true;
		}
	}
	// Check Columns
	for (int i = 0; i < 3; i++) {

		if (board[0][i] == currentPlayer && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
			return true;
		}
	}
	// Diagonal from top left to bottom right
	if (board[0][0] == currentPlayer && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		return true;
	}
	// Diagonal from bottom left to top right
	if (board[0][2] == currentPlayer && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		return true;
	}

	return false;
}

void GameBoard::printBoard()
{
	cout << endl;
	cout << " |1|2|3| \n";
	for (int i = 0; i < 3; i++) {
		cout << " -------\n";
		cout << i + 1 << "|" << board[i][0] << "|" << board[i][1] << "|" << board[i][2] << "|\n";
	}
	cout << " -------\n";
}

void GameBoard::clearBoard()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			
			board[i][j] = ' ';
				
		}
		
	}
}
