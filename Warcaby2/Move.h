#ifndef Move_HH
#define Move_HH

#include <iostream>
#include <climits> 

struct Move
{
	int x, y, dx, dy;
	Move() {}
	Move(int get_x, int get_y, int get_dx, int get_dy)
	{
		x = get_x;
		y = get_y;
		dx = get_dx;
		dy = get_dy;
	}
};

#endif
