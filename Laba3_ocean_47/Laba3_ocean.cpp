#include <iostream>
#include <conio.h>
#include "ocean.h"

using namespace std;
using namespace ocean_life;


int main()
{
	srand(time(0));
	Ocean_master ocean(14, 5);

	ocean.start_random_place(4, 4, 4, 4, 6, 4, 9);
	//						 W  D  K  S  C  F  P
	// some fish that can fight, a little bit more defenseless clownfish, a lot of plankton 

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


// THE PLANKTON DOESN'T EAT BUT REPLICATES RAPIDLY
// THE PASSIVES ONLY EAT PLANKTON 
// THE NEUTRALS EAT PLANKTON BUT CAN EAT THE PASSIVES
// THE AGGRESSIVES CAN NOT EAT PLANKTON, BUT CAN EAT BOTH PASSIVES AND NEUTRALS
