#ifndef Board_HH
#define Board_HH

#include <iostream>
#include <climits>
#include "Move.hh"
#define COMPUTER -1
#define GAMER 1

class Board
{
	int Array[8][8];
public:

	Board();
	Board(Board &p);
	Board& operator=(Board const &p2);
	void Display();
	bool Permitted_Movement(Board p, int player, int x, int y, int dx, int dy);
	bool End_Of_Board(Board p);
	Board Make_Movement(const Board p, int player, int x, int y, int dx, int dy);
	int Score(Board p);
	int Min_Max(Board p, int player, int depth, Move &final_score);
	Move Computer_Turn(Board p, int level);
	Move Gamer_Turn(Board p);
};
#endif
