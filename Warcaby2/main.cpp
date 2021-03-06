#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include "Board.hh"

using namespace std;

int main()
{
	Board p;
	int Kto_Ruch = 1;
	int poziom_trudnosci = 0;
	cout << "\t\tWARCABY" << endl;

	cout << "Wybierz poziom trudnosci:\n1.latwy\n2.trudny" << endl;



	cin >> poziom_trudnosci;
	switch (poziom_trudnosci)
	{
	case 1:
		poziom_trudnosci = 2;
		break;
	case 2:
		poziom_trudnosci = 4;
		break;
	default:
		cout << "Wybierz poziom trudnosci:\n1.latwy\n2.trudny" << endl;
		break;
	}
	for (; poziom_trudnosci != 2 && poziom_trudnosci != 4;)
	{
		cin >> poziom_trudnosci;
		switch (poziom_trudnosci)
		{
		case 1:
			poziom_trudnosci = 2;
			break;
		case 2:
			poziom_trudnosci = 4;
			break;
		default:
			cout << "Wybierz poziom trudnosci:\n1.latwy\n2.trudny" << endl;
			break;
		}

	}

	system("clear");
	for (; !p.End_Of_Board(p);)
	{

		Move r;
		if (Kto_Ruch == 1)
		{
			p.Display();
			r = p.Gamer_Turn(p);
			p = p.Make_Movement(p, 1, r.x, r.y, r.dx, r.dy);
		}
		else
		{
			system("clear");
			r = p.Computer_Turn(p, poziom_trudnosci);
			p = p.Make_Movement(p, -1, r.x, r.y, r.dx, r.dy);
		}

		Kto_Ruch = -Kto_Ruch;
	}
	return 0;
}
s