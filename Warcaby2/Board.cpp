#include "Board.hh"

using namespace std;

Board::Board()
{
	int Tab_Temp[8][8] = { { 0,-1,0,-1,0,-1,0,-1 },
	{ -1,0,-1,0,-1,0,-1,0 },
	{ 0,-1,0,-1,0,-1,0,-1 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 1,0,1,0,1,0,1,0 },
	{ 0,1,0,1,0,1,0,1 },
	{ 1,0,1,0,1,0,1,0 }
	};
	for (int i = 7; i >= 0; i--)
	{
		for (int j = 7; j >= 0; j--)
		{
			Array[i][j] = Tab_Temp[i][j];
		}
	}
}
Board::Board(Board &p)
{
	for (int x = 7; x >= 0; x--)
	{
		for (int y = 7; y >= 0; y--)
		{
			this->Array[x][y] = p.Array[x][y];
		}
	}
}

Board& Board::operator=(Board const &p2)
{
	for (int x = 7; x >= 0; x--)
	{
		for (int y = 7; y >= 0; y--)
		{
			this->Array[x][y] = p2.Array[x][y];
		}
	}
	return *this;
}

//making the board in the terminal, which helps player to perform a motion
void Board::Display()
{
	int int_set[8] = { 8,7,6,5,4,3,2,1 };
	cout << endl << "    A      B      C      D      E      F      G      H" << endl;
	for (int i = 0; i<8; i++)
	{
		cout << int_set[i];
		for (int j = 0; j<8; j++)
		{
			if (Array[i][j] == -1)
				cout << "  [O]  ";
			if (Array[i][j] == -2)
				cout << " [D_O] ";
			if (Array[i][j] == 0)
				cout << "  [ ]  ";
			if (Array[i][j] == 1)
				cout << "  [#]  ";
			if (Array[i][j] == 2)
				cout << " [D_#] ";
		}
		cout << int_set[i] << endl;
	}
	cout << "    A      B      C      D      E      F      G      H" << endl;
}

//here are rules how we can move the checker.
bool Board::Permitted_Movement(Board p, int player, int x, int y, int dx, int dy)
{
	if (x >= 0 && y >= 0 && dx >= 0 && dy >= 0 && x <= 7 && y <= 7 && dx <= 7 && dy <= 7)
	{
		if (player == GAMER && p.Array[y][x] == 2) // cheking if player can make his  movement
		{
			if (dx>x && dy<y)
			{
				if ((dx == x + 1 && dy == y - 1) || (dx == x + 2 && dy == y - 2) ||
					(dx == x + 3 && dy == y - 3) || (dx == x + 4 && dy == y - 4) ||
					(dx == x + 4 && dy == y - 4) || (dx == x + 5 && dy == y - 5) ||
					(dx == x + 6 && dy == y - 6) || (dx == x + 7 && dy == y - 7))
				{
					int temp_y = y - 1;
					int i = x + 1;
					while (i <= dx)
					{
						i++;
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != 1 && p.Array[temp_y][i] != 2)
							{
								if (temp_y != 0 || i != 7)
								{
									if (p.Array[temp_y - 1][i + 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y--;
					}
					return true;
				}
				return false;
			}

			if (dx>x && dy>y)
			{
				if ((dx == x + 1 && dy == y + 1) || (dx == x + 2 && dy == y + 2) ||
					(dx == x + 3 && dy == y + 3) || (dx == x + 4 && dy == y + 4) ||
					(dx == x + 4 && dy == y + 4) || (dx == x + 5 && dy == y + 5) ||
					(dx == x + 6 && dy == y + 6) || (dx == x + 7 && dy == y + 7))
				{
					int temp_y = y + 1; int i = x + 1;
					while (i <= dx)
					{
						i++;
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != 1 && p.Array[temp_y][i] != 2)
							{
								if (temp_y != 7 || i != 7)
								{
									if (p.Array[temp_y + 1][i + 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y++;
					}
					return true;
				}
				return false;
			}

			if (dx<x && dy<y)
			{
				if ((dx == x - 1 && dy == y - 1) || (dx == x - 2 && dy == y - 2) ||
					(dx == x - 3 && dy == y - 3) || (dx == x - 4 && dy == y - 4) ||
					(dx == x - 4 && dy == y - 4) || (dx == x - 5 && dy == y - 5) ||
					(dx == x - 6 && dy == y - 6) || (dx == x - 7 && dy == y - 7))
				{
					int temp_y = y - 1;
					int i = x - 1;
					while ((i--) >= dx)
					{
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != 1 && p.Array[temp_y][i] != 2)
							{
								if (temp_y != 0 || i != 0)
								{
									if (p.Array[temp_y - 1][i - 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y--;
					}
					return true;
				}
				return false;
			}

			if (dx<x && dy>y)
			{
				if ((dx == x - 1 && dy == y + 1) || (dx == x - 2 && dy == y + 2) ||
					(dx == x - 3 && dy == y + 3) || (dx == x - 4 && dy == y + 4) ||
					(dx == x - 4 && dy == y + 4) || (dx == x - 5 && dy == y + 5) ||
					(dx == x - 6 && dy == y + 6) || (dx == x - 7 && dy == y + 7))
				{
					int temp_y = y + 1; int i = x - 1;
					while (i >= dx)
					{
						i--;
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != 1 && p.Array[temp_y][i] != 2)
							{
								if (temp_y != 7 || i != 0)
								{
									if (p.Array[temp_y + 1][i - 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y++;
					}
					return true;
				}
				return false;
			};
		}

		if (player == COMPUTER && p.Array[y][x] == -2) //cheking if computer can make his movement
		{
			if (dx>x && dy<y)
			{
				if ((dx == x + 1 && dy == y - 1) || (dx == x + 2 && dy == y - 2) ||
					(dx == x + 3 && dy == y - 3) || (dx == x + 4 && dy == y - 4) ||
					(dx == x + 4 && dy == y - 4) || (dx == x + 5 && dy == y - 5) ||
					(dx == x + 6 && dy == y - 6) || (dx == x + 7 && dy == y - 7))
				{
					int temp_y = y - 1;
					int i = x + 1;
					while ((i++) <= dx)
					{
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != -1 && p.Array[temp_y][i] != -2)
							{
								if (temp_y != 0 || i != 7)
								{
									if (p.Array[temp_y - 1][i + 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y--;
					}
					return true;
				}
				return false;
			}

			if (dx>x && dy>y)
			{
				if ((dx == x + 1 && dy == y + 1) || (dx == x + 2 && dy == y + 2) ||
					(dx == x + 3 && dy == y + 3) || (dx == x + 4 && dy == y + 4) ||
					(dx == x + 4 && dy == y + 4) || (dx == x + 5 && dy == y + 5) ||
					(dx == x + 6 && dy == y + 6) || (dx == x + 7 && dy == y + 7))
				{
					int temp_y = y + 1;
					int i = x + 1;
					while ((i++) <= dx)
					{
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != -1 && p.Array[temp_y][i] != -2)
							{
								if (temp_y != 7 || i != 7)
								{
									if (p.Array[temp_y + 1][i + 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y++;
					}
					return true;
				}
				return false;
			}

			if (dx<x && dy<y)
			{
				if ((dx == x - 1 && dy == y - 1) || (dx == x - 2 && dy == y - 2) ||
					(dx == x - 3 && dy == y - 3) || (dx == x - 4 && dy == y - 4) ||
					(dx == x - 4 && dy == y - 4) || (dx == x - 5 && dy == y - 5) ||
					(dx == x - 6 && dy == y - 6) || (dx == x - 7 && dy == y - 7))
				{
					int temp_y = y - 1;
					int i = x - 1;
					while ((i--) >= dx)
					{
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != -1 && p.Array[temp_y][i] != -2)
							{
								if (temp_y != 0 || i != 0)
								{
									if (p.Array[temp_y - 1][i - 1] != 0)
									{
										return false;
									};
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y--;
					}
					return true;
				}
				return false;
			}

			if (dx<x && dy>y)
			{
				if ((dx == x - 1 && dy == y + 1) || (dx == x - 2 && dy == y + 2) ||
					(dx == x - 3 && dy == y + 3) || (dx == x - 4 && dy == y + 4) ||
					(dx == x - 4 && dy == y + 4) || (dx == x - 5 && dy == y + 5) ||
					(dx == x - 6 && dy == y + 6) || (dx == x - 7 && dy == y + 7))
				{
					int temp_y = y + 1;
					int i = x - 1;
					while ((i--) >= dx)
					{
						if (p.Array[temp_y][i] != 0)
						{
							if (p.Array[temp_y][i] != -1 && p.Array[temp_y][i] != -2)
							{
								if (temp_y != 7 || i != 0)
								{
									if (p.Array[temp_y + 1][i - 1] != 0)
									{
										return false;
									}
								}
								else
								{
									return false;
								}
							}
							else
							{
								return false;
							}
						}
						temp_y++;
					}
					return true;
				}
				return false;
			}
		}

		if (player == COMPUTER)
		{
			if (p.Array[y][x] == -1)
			{
				if (p.Array[dy][dx] == 0)
				{
					if (dy == y + 1)
					{
						if (dx == x + 1 || dx == x - 1)
						{
							return true;
						}
					}
				}
				if (dy == y + 2)
				{
					if (dx == x + 2)
					{
						if (p.Array[dy][dx] == 0)
						{
							if (p.Array[y + 1][x + 1]>0)
							{
								return true;
							}
						}
					}
					if (dx == x - 2)
					{
						if (p.Array[dy][dx] == 0)
						{
							if (p.Array[y + 1][x - 1]>0)
							{
								return true;
							}
						}
					}
				}
			}
		}
		else if (player == GAMER)
		{
			if (p.Array[y][x] == 1)
			{
				if (p.Array[dy][dx] == 0)
				{
					if (dy == y - 1)
					{
						if (dx == x + 1 || dx == x - 1)
						{
							return true;
						}

					}
					if (dy == y - 2)
					{
						if (dx == x + 2)
						{
							if (p.Array[y - 1][x + 1]<0)
							{
								return true;
							}
						}
						if (dx == x - 2)
						{
							if (p.Array[y - 1][x - 1]<0)
							{
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
//cheking if checker is at the end of the border
bool Board::End_Of_Board(Board p)
{
	int licz_biale = 0;
	int licz_czarne = 0;
	for (int x = 7; x >= 0; x--)
	{
		for (int y = 7; y >= 0; y--)

		{
			if (p.Array[y][x] == 1 || p.Array[y][x] == 2)
				licz_biale++;
			if (p.Array[y][x] == -1 || p.Array[y][x] == -2)
				licz_czarne++;
		}
	}

	return licz_biale == 0 || licz_czarne == 0;

}

Board Board::Make_Movement(const Board p, int player, int x, int y, int dx, int dy)
{

	Board final_score;
	final_score = p;

	if (final_score.Array[y][x] == 2 || final_score.Array[y][x] == -2)
	{
		if (player == GAMER)
		{
			if (dx>x && dy<y)
			{
				int temp_y = y - 1;
				int i = x + 1;
				while ((i++) <= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y--;
				}
				final_score.Array[dy][dx] = 2;
				final_score.Array[y][x] = 0;
			}

			if (dx>x && dy>y)

			{
				int temp_y = y + 1;
				int i = x + 1;
				while ((i++) <= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y++;
				}
				final_score.Array[dy][dx] = 2;
				final_score.Array[y][x] = 0;
			}

			if (dx<x && dy<y)
			{
				int temp_y = y - 1;
				int i = x - 1;
				while ((i--) >= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y--;
				}
				final_score.Array[dy][dx] = 2;
				final_score.Array[y][x] = 0;
			}

			if (dx<x && dy>y)
			{
				int temp_y = y + 1;
				int i = x - 1;
				while ((i--) >= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y++;
				}
				final_score.Array[dy][dx] = 2;
				final_score.Array[y][x] = 0;
			}
		}

		if (player == COMPUTER)
		{

			if (dx>x && dy<y)
			{
				int temp_y = y - 1;
				int i = x + 1;
				while ((i++) <= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y--;
				}
				final_score.Array[dy][dx] = -2;
				final_score.Array[y][x] = 0;
			}

			if (dx>x && dy>y)
			{
				int temp_y = y + 1;
				int i = x + 1;
				while ((i++) <= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y++;
				}
				final_score.Array[dy][dx] = -2;
				final_score.Array[y][x] = 0;
			}

			if (dx<x && dy<y)
			{
				int temp_y = y - 1;
				int i = x - 1;
				while ((i--) >= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y--;
				}
				final_score.Array[dy][dx] = -2;
				final_score.Array[y][x] = 0;
			}

			if (dx<x && dy>y)
			{
				int temp_y = y + 1;
				int i = x - 1;
				while ((i--) >= dx)
				{
					if (p.Array[temp_y][i] != 0)
					{
						final_score.Array[temp_y][i] = 0;
					}
					temp_y++;
				}
				final_score.Array[dy][dx] = -2;
				final_score.Array[y][x] = 0;
			}
		}
	}

	if (player == GAMER && ((dy == 0) || (dy == 2) || (dy == 4) || (dy == 6)))
	{
		final_score.Array[dy][dx] = 2;
	}
	if (player == COMPUTER)
	{
		if (p.Array[y][x] == -1)
		{
			if (dy == y + 1)
			{
				if (dx == x + 1 || dx == x - 1)
				{
					final_score.Array[dy][dx] = final_score.Array[y][x];
					final_score.Array[y][x] = 0;
				}
			}
			if (dy == y + 2)
			{
				if (dx == x + 2)
				{
					if (final_score.Array[y + 1][x + 1]>0)
					{
						final_score.Array[y + 1][x + 1] = 0;
						final_score.Array[dy][dx] = final_score.Array[y][x];
						final_score.Array[y][x] = 0;
					}
				}
				if (dx == x - 2)
				{
					if (p.Array[y + 1][x - 1]>0)
					{
						final_score.Array[y + 1][x - 1] = 0;
						final_score.Array[dy][dx] = final_score.Array[y][x];
						final_score.Array[y][x] = 0;
					}
				}
			}
		}
	}
	else if (player == GAMER)
	{
		if (p.Array[y][x] == 1)
		{
			if (dy == y - 1)
			{
				if (dx == x + 1 || dx == x - 1)
				{
					final_score.Array[dy][dx] = final_score.Array[y][x];
					final_score.Array[y][x] = 0;
				}
			}
			if (dy == y - 2)
			{
				if (dx == x + 2)
				{
					if (p.Array[y - 1][x + 1]<0)
					{
						final_score.Array[y - 1][x + 1] = 0;
						final_score.Array[dy][dx] = p.Array[y][x];
						final_score.Array[y][x] = 0;
					}
				}
				if (dx == x - 2)
				{
					if (p.Array[y - 1][x - 1]<0)
					{
						final_score.Array[y - 1][x - 1] = 0;
						final_score.Array[dy][dx] = final_score.Array[y][x];
						final_score.Array[y][x] = 0;
					}
				}
			}
		}
	}
	if ((dy == 0 || dy == 7))
	{
		if (player == 1)
		{
			final_score.Array[dy][dx] = 2;
		}
		else
		{
			final_score.Array[dy][dx] = -2;
		}
	}
	return final_score;
}
//alpha-beta pruning algorithm implementation
int Board::Score(Board p)
{
	int final_score = 0, final_score_player = 0;
	for (int x = 7; x >= 0; x--)
	{
		for (int y = 7; y >= 0; y--)
		{
			if (p.Array[x][y] == 1)
			{
				final_score_player += 5;
			}
			else if (p.Array[x][y] == -1)
			{
				final_score += 5;
			}
			else if (p.Array[x][y] == 2)
			{
				final_score_player += 100;
			}
			else if (p.Array[x][y] == -2)
			{
				final_score += 100;
			}
		}
	}
	final_score = final_score - final_score_player;
	return final_score;
}
//implementation of MINIMAX algorithm
int Board::Min_Max(Board p, int player, int depth, Move &final_score)
{
	if (depth == 0)
		return Score(p);

	int preferable;

	if (player == COMPUTER) preferable = INT_MIN;
	else preferable = INT_MAX;

	Move best_move;

	for (int x = 0; x < 8; x++)
		for (int y = 0; y < 8; y++)
			for (int dx = 0; dx < 8; dx++)
				for (int dy = 0; dy < 8; dy++)
				{
					if (Permitted_Movement(p, player, x, y, dx, dy))
					{
						Board p_prim;
						p_prim = Make_Movement(p, player, x, y, dx, dy);
						int how_good = Min_Max(p_prim, -player, depth - 1, final_score);
						if (player == COMPUTER)
						{
							if (how_good > preferable)
							{
								preferable = how_good;
								best_move.x = x;
								best_move.y = y;
								best_move.dx = dx;
								best_move.dy = dy;

							}
						}
						else
						{
							if (how_good < preferable)
							{
								preferable = how_good;
								best_move.x = x;
								best_move.y = y;
								best_move.dx = dx;
								best_move.dy = dy;


							}
						}
					}
				}
	final_score = best_move;

	return preferable;
}

Move Board::Computer_Turn(Board p, int level)
{
	Move r;
	Min_Max(p, -1, level, r);
	cout << endl << "####  Komputer wykonal swoj ruch  ####" << endl << endl;
	return r;
}

Move Board::Gamer_Turn(Board p)
{
	Move r;
	string temp1, temp2;
	char char_temp1, char_temp2;
	int int_temp1, int_temp2;
	int intset[9] = { 0,7,6,5,4,3,2,1,0 };
	int x = 0, y = 0, dx = 0, dy = 0;

	cout << endl << "Kolej Gracza: " << endl;
	for (; !Permitted_Movement(p, GAMER, x, y, dx, dy);)
	{
		cout << "Wybierz pionek: ->";
		cin >> temp1;
		if (temp1.length() != 2)
		{
			cout << endl << "####### Bledne Wspolrzedne! #######" << endl;
			continue;
		}
		cout << "Wybierz pole docelowe: ->";
		cin >> temp2;
		if (temp2.length() != 2)
		{
			cout << endl << "####### Bledne Wspolrzedne! #######" << endl;
			continue;
		}

		char_temp1 = temp1[0];
		char_temp2 = temp2[0];
		int_temp1 = temp1[1] - 48;
		int_temp2 = temp2[1] - 48;

		x = (int(char_temp1)) - 65;
		y = intset[int_temp1];
		dx = (int(char_temp2)) - 65;
		dy = intset[int_temp2];

		r.x = (int(char_temp1)) - 65;
		r.y = intset[int_temp1];
		r.dx = (int(char_temp2)) - 65;
		r.dy = intset[int_temp2];

		if (r.x>7 || r.x<0 || r.y>7 || r.y<0 ||
			r.dy>7 || r.dy<0 || r.dx>7 || r.dx<0)
		{
			cout << endl << "####### Bledne Wspolrzedne! #######" << endl;
			continue;
		}
	}
	return r;
}
