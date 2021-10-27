#include <iostream>
#include <conio.h>
#include "ocean.h"

using namespace std;
using namespace ocean_life;




int main()
{
	srand(time(0));
	Ocean_master ocean(12,5);

	ocean.start_random_place();
	ocean.Show();

	int move_count = 0;
	while (true) 
	{
		move_count++;
		cout << "Move #" << move_count << endl;

		_getch();
		ocean.Tick();
	}
}