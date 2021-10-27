#include "ocean.h"

using namespace std;
using namespace ocean_life;


void Ocean_field::display_field()
{
	for (int i = 0; i < width; i++)
	{
		cout << "----";
	}
	cout << "-" << endl;
	for (int i = 0; i < height; i++)
	{
		cout << "|";
		for (int j = 0; j < width; j++) {
			cout << scene[j][i][0] << " " << scene[j][i][1] << "|";
		}
		cout << endl << "|";
		for (int j = 0; j < width; j++) {
			cout << "   |";
		}
		cout << endl << "|";
		for (int j = 0; j < width; j++) {
			cout << scene[j][i][2] << " " << scene[j][i][3] << "|";
		}
		cout << endl << "-";
		for (int j = 0; j < width; j++) {
			cout << "----";
		}
		cout << endl;
	}
}

int* Ocean_master::find_empty_cell(bool isPlankton)
{
	int width = ocean_table->get_width();
	int height = ocean_table->get_height();
	int* coords = new int[3];
	int variations = 0;
	int i = rand() % width;
	int j = rand() % height;
	int k = 0;

	while (ocean_table->scene[i][j][k] != ' ' && variations < width * height) // if we are looking for an empty cell and not every cell is full
	{
		for (int c = 0; c < 4; c++)
		{
			if (isPlankton)
			{
				if (ocean_table->scene[i][j][c] == 'P') break;
			}
			if (ocean_table->scene[i][j][c] == ' ')
			{
				coords[0] = i; coords[1] = j; coords[2] = c;
				return coords;
			}
		}
		i = rand() % width;
		j = rand() % height;
		variations++;
	}
	if (variations < width * height)
	{
		coords[0] = i; coords[1] = j; coords[2] = k;
		return coords;
	} //if an empty cell is found

	coords[0] = -1; coords[1] = -1; coords[2] = -1;
	return coords; //if an empty field does not exist
}

void Ocean_master::Tick()
{
	system("cls");

	for (int i = 0; i < fish_plankton.size(); i++)
	{
		Plankton_move(&fish_plankton[i]);
	}


	UpdateMap();
	Show();
}

void Ocean_master::Show()
{
	ocean_table->display_field();
}

void Ocean_master::start_random_place()
{
	// number of mobs
	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 != 0)
		{
			Whale fish_whale_obj("Male");
			fish_whale.push_back(fish_whale_obj);
		}
		else
		{
			Whale fish_whale_obj("Female");
			fish_whale.push_back(fish_whale_obj);
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 != 0)
		{
			Dolphin fish_dolphin_obj("Male");
			fish_dolphin.push_back(fish_dolphin_obj);
		}
		else
		{
			Dolphin fish_dolphin_obj("Female");
			fish_dolphin.push_back(fish_dolphin_obj);
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 != 0)
		{
			Killerwhale fish_killerwhale_obj("Male");
			fish_killerwhale.push_back(fish_killerwhale_obj);
		}
		else
		{
			Killerwhale fish_killerwhale_obj("Female");
			fish_killerwhale.push_back(fish_killerwhale_obj);
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 != 0)
		{
			Shark fish_shark_obj("Male");
			fish_shark.push_back(fish_shark_obj);
		}
		else
		{
			Shark fish_shark_obj("Female");
			fish_shark.push_back(fish_shark_obj);
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		if (i % 2 != 0)
		{
			Clownfish fish_clownfish_obj("Male");
			fish_clownfish.push_back(fish_clownfish_obj);
		}
		else
		{
			Clownfish fish_clownfish_obj("Female");
			fish_clownfish.push_back(fish_clownfish_obj);
		}
	}

	for (int i = 0; i < 4; i++)
	{
		if (i % 2)
		{
			Fugu fish_fugu_obj("Male");
			fish_fugu.push_back(fish_fugu_obj);
		}
		else
		{
			Fugu fish_fugu_obj("Female");
			fish_fugu.push_back(fish_fugu_obj);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		Plankton fish_plankton_obj;
		fish_plankton.push_back(fish_plankton_obj);
	}

	// start place
	for (int i = 0; i < fish_whale.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_whale[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0],cell_coords[1],cell_coords[2],'W');
	}

	for (int i = 0; i < fish_shark.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_shark[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'S');
	}

	for (int i = 0; i < fish_killerwhale.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_killerwhale[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'K');
	}

	for (int i = 0; i < fish_dolphin.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_dolphin[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'D');
	}

	for (int i = 0; i < fish_fugu.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_fugu[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'F');
	}

	for (int i = 0; i < fish_clownfish.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(0);

		for (int j = 0; j < 3; j++)
		{
			fish_clownfish[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'C');
	}

	for (int i = 0; i < fish_plankton.size(); i++)
	{
		int* cell_coords;
		cell_coords = find_empty_cell(1);

		for (int j = 0; j < 3; j++)
		{
			fish_plankton[i].location[j] = cell_coords[j];
		}
		ocean_table->put_fish(cell_coords[0], cell_coords[1], cell_coords[2], 'P');
	}

	UpdateMap();
}

void Ocean_master::UpdateMap()
{
	for (int i = 0; i < ocean_table->get_width(); i++)
	{
		for (int j = 0; j < ocean_table->get_height(); j++)
		{
			for (int k = 0; k < 4; k++)
			{
				ocean_table->scene[i][j][k] = ' ';
			}
		}
	}
	
	for (int i = 0; i < fish_plankton.size(); i++)
	{
		ocean_table->scene[fish_plankton[i].location[0]][fish_plankton[i].location[1]][fish_plankton[i].location[2]] = 'P';
	}
	for (int i = 0; i < fish_clownfish.size(); i++)
	{
		ocean_table->scene[fish_clownfish[i].location[0]][fish_clownfish[i].location[1]][fish_clownfish[i].location[2]] = 'C';
	}
	for (int i = 0; i < fish_fugu.size(); i++)
	{
		ocean_table->scene[fish_fugu[i].location[0]][fish_fugu[i].location[1]][fish_fugu[i].location[2]] = 'F';
	}
	for (int i = 0; i < fish_whale.size(); i++)
	{
		ocean_table->scene[fish_whale[i].location[0]][fish_whale[i].location[1]][fish_whale[i].location[2]] = 'W';
	}
	for (int i = 0; i < fish_killerwhale.size(); i++)
	{
		ocean_table->scene[fish_killerwhale[i].location[0]][fish_killerwhale[i].location[1]][fish_killerwhale[i].location[2]] = 'K';
	}
	for (int i = 0; i < fish_dolphin.size(); i++)
	{
		ocean_table->scene[fish_dolphin[i].location[0]][fish_dolphin[i].location[1]][fish_dolphin[i].location[2]] = 'D';
	}
	for (int i = 0; i < fish_shark.size(); i++)
	{
		ocean_table->scene[fish_shark[i].location[0]][fish_shark[i].location[1]][fish_shark[i].location[2]] = 'S';
	}

}

void Ocean_master::Plankton_move(Plankton* p_obj)
{
	int x = p_obj->location[0], y = p_obj->location[1], index = 0;
	int direction = rand() % 4 + 1; //1 - up, 2 - down, 3 - right, 4 - left
	int variations = 0, 
		current_width = ocean_table->get_width(), 
		current_height = ocean_table->get_height();

	//MOVING PHASE

	while (variations < current_width * current_height)
	{
		if (direction == 1)
		{
			index = empty_place(x, y - 1, 1);
			if (index != -1) //the place is busy
			{
				p_obj->location[1] = y - 1;
				p_obj->location[2] = index;
				break;
			}
			else
			{
				direction = rand() % 4 + 1;
			}
		}
		if (direction == 2)
		{
			index = empty_place(x, y + 1, 1);
			if (index != -1)
			{
				p_obj->location[1] = y + 1;
				p_obj->location[2] = index;
				break;
			}
			else
			{
				direction = rand() % 4 + 1;
			}
		}
		if (direction == 3)
		{
			index = empty_place(x + 1, y, 1);
			if (index != -1)
			{
				p_obj->location[0] = x + 1;
				p_obj->location[2] = index;
				break;
			}
			else
			{
				direction = rand() % 4 + 1;
			}
		}
		if (direction == 4)
		{
			index = empty_place(x - 1, y, 1);
			if (index != -1)
			{
				p_obj->location[0] = x - 1;
				p_obj->location[2] = index;
				break;
			}
			else
			{
				direction = rand() % 4 + 1;
			}
		}
		variations++;
	}

}

/*void Ocean_master::Plankton_replicate(Plankton* p_obj)
{
	int x = p_obj->location[0], y = p_obj->location[1];
	int direction = rand() % 4 + 1; //1 - up, 2 - down, 3 - right, 4 - left

	//REPLICATING PHASE

	while (true)
	{
		if (direction == 1)
		{
			if (empty_place(x, y - 1, 1) != -1) //if there is no plankton in this direction
			{
				Plankton p_child;
				p_child.location[0] = x;
				p_child.location[1] = y - 1;
				p_child.location[2] = empty_place(x, y - 1, 1);
				fish_plankton.push_back(p_child);
				break;
			}
			if (empty_place(x, y - 1, 1) == -1 && empty_place(x, y - 1, 0) != -1) //if there is plankton in this direction
			{
				for (int i = 0; i < fish_plankton.size(); i++)
				{
					if (fish_plankton[i].location[0] == x && fish_plankton[i].location[1] == y - 1)
					{
						fish_plankton[i].hp = 15;
					}
				}
				break;
			}
			if (empty_place(x, y - 1, 0) == -1)
			{
				direction = rand() % 4 + 1;
				continue;
			}
		}
		if (direction == 2)
		{
			if (empty_place(x, y + 1, 1) != -1) //if there is no plankton in this direction
			{
				Plankton p_child;
				p_child.location[0] = x;
				p_child.location[1] = y + 1;
				p_child.location[2] = empty_place(x, y + 1, 1);
				fish_plankton.push_back(p_child);
				break;
			}
			if (empty_place(x, y + 1, 1) == -1 && empty_place(x, y + 1, 0) != -1) //if there is plankton in this direction
			{
				for (int i = 0; i < fish_plankton.size(); i++)
				{
					if (fish_plankton[i].location[0] == x && fish_plankton[i].location[1] == y + 1)
					{
						fish_plankton[i].hp = 15;
					}
				}
				break;
			}
			if (empty_place(x, y + 1, 0) == -1)
			{
				direction = rand() % 4 + 1;
				continue;
			}
		}
		if (direction == 3)
		{
			if (empty_place(x + 1, y, 1) != -1) //if there is no plankton in this direction
			{
				Plankton p_child;
				p_child.location[0] = x + 1;
				p_child.location[1] = y;
				p_child.location[2] = empty_place(x + 1, y, 1);
				fish_plankton.push_back(p_child);
				break;
			}
			if (empty_place(x + 1, y, 1) == -1 && empty_place(x + 1, y, 0) != -1) //if there is plankton in this direction
			{
				for (int i = 0; i < fish_plankton.size(); i++)
				{
					if (fish_plankton[i].location[0] == x + 1 && fish_plankton[i].location[1] == y)
					{
						fish_plankton[i].hp = 15;
					}
				}
				break;
			}
			if (empty_place(x + 1, y, 0) == -1)
			{
				direction = rand() % 4 + 1;
				continue;
			}
		}
		if (direction == 4)
		{
			if (empty_place(x - 1, y, 1) != -1) //if there is no plankton in this direction
			{
				Plankton p_child;
				p_child.location[0] = x - 1;
				p_child.location[1] = y;
				p_child.location[2] = empty_place(x - 1, y, 1);
				fish_plankton.push_back(p_child);
				break;
			}
			if (empty_place(x - 1, y, 1) == -1 && empty_place(x - 1, y, 0) != -1) //if there is plankton in this direction
			{
				for (int i = 0; i < fish_plankton.size(); i++)
				{
					if (fish_plankton[i].location[0] == x + 1 && fish_plankton[i].location[1] == y)
					{
						fish_plankton[i].hp = 15;
					}
				}
				break;
			}
			if (empty_place(x - 1, y, 0) == -1)
			{
				direction = rand() % 4 + 1;
				continue;
			}
		}
	}
}*/

int Ocean_master::empty_place(int x1, int y1, bool isPlankton)
{
	if (x1 < 0 || y1 < 0 || x1 >= ocean_table->get_width() || y1 >= ocean_table->get_height()) 
	{ 
		return -1; 
	}
	
	if (isPlankton)
	{
		for (int i = 0; i < fish_plankton.size(); i++)
		{
			if (fish_plankton[i].location[0] == x1 && fish_plankton[i].location[1] == y1)
				return -1;
		}
	} // only 1 plankton per 1 cell
	
	for (int i = 0; i < 4; i++)
	{
		if (ocean_table->scene[x1][y1][i] == ' ')
		{
			return i;
		}
	}
	return -1;
}