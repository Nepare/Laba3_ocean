#include <iostream>
#include <conio.h>
#include "ocean.h"

using namespace std;
using namespace ocean_life;


int main()
{
	srand(time(0));
	Ocean_master ocean(12,5);

	ocean.start_random_place(4, 4, 4, 4, 6, 4, 9); 
	//						 W  D  K  S  C  F  P
	ocean.Show();

	int move_count = 0;
	while (true) 
	{
		move_count++;
		cout << "Move #" << move_count << endl;

		char input = _getch();
		if (input == '\033') return 0; // if you press ESC, the program ends
		ocean.Tick();
	}
}