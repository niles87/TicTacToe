#pragma once
class GameBoard
{
public:
	GameBoard();
	void playGame();
private:
	int xCoord();
	int yCoord();
	bool placeIdentifier(int x, int y, char currentPlayer);
	bool checkForWin(char currentPlayer);
	void printBoard();
	void clearBoard();
	char board[3][3];
};

