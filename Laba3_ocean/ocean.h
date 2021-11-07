#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <conio.h>
#include <string>

using namespace std;


namespace ocean_life
{
	class Ocean_field
	{
		int width, height;
	public:
		char*** scene;
		Ocean_field(int width_inp, int height_inp)
		{
			width = width_inp;
			height = height_inp;
			scene = new char** [width];
			for (int i = 0; i < width; i++)
				scene[i] = new char* [height];

			for (int i = 0; i < width; i++)
			{
				for (int j = 0; j < height; j++)
				{
					scene[i][j] = new char[4];
					for (int k = 0; k < 4; k++) { scene[i][j][k] = ' '; }
				}
			}
		} 

		void put_fish(int posX, int posY, int posI, char fish_type)
		{
			scene[posX][posY][posI] = fish_type;
		}

		void display_field();

		int get_width()
		{
			return width;
		}

		int get_height()
		{
			return height;
		}
	};

	class Organism
	{
	public:
		string name;
		char type;
		int age, id, hp, hp_max, food, food_max, moves;
		bool isMale;
		int location[3];
	};

		class Plankton : public Organism

		class Passive : public Organism
	{
	};

			class Clownfish : public Passive
		{
		public:
			Clownfish(string sex)
			{
				hp_max = 15; hp = hp_max;
				food_max = 10; food = food_max;
				moves = 3;
				age = 0;
				type = 'C';
				if (sex == "Male") isMale = true;
				if (sex == "Female") isMale = false;
				if (sex == "Random") isMale = rand() % 2;
			}
		};

			class Fugu : public Passive
		{
		public:
			Fugu(string sex)
			{
				hp_max = 20; hp = hp_max;
				food_max = 10; food = food_max;
				moves = 3;
				age = 0;
				type = 'F';
				if (sex == "Male") isMale = true;
				if (sex == "Female") isMale = false;
				if (sex == "Random") isMale = rand() % 2;
			}
		};

		class Aggressive : public Organism
	{
	public:
		int damage;
	};

			class Killerwhale : public Aggressive
		{
		public:
			Killerwhale(string sex)
			{
				hp_max = 120; hp = hp_max;
				food_max = 30; food = food_max;
				moves = 4;
				damage = 50;
				age = 0;
				type = 'K';
				if (sex == "Male") isMale = true;
				if (sex == "Female") isMale = false;
				if (sex == "Random") isMale = rand() % 2;
			}
		};

			class Shark : public Aggressive
		{
		public:
			Shark(string sex)
			{
				hp_max = 150; hp = hp_max;
				food_max = 25; food = food_max;
				moves = 4;
				damage = 40;
				age = 0;
				type = 'S';
				if (sex == "Male") isMale = true;
				if (sex == "Female") isMale = false;
				if (sex == "Random") isMale = rand() % 2;
			}
		};

		class Neutral : public Organism
	{
	public:
		int damage;
	};

			class Whale : public Neutral
	{
	public:
		Whale(string sex)
		{
			hp_max = 300; hp = hp_max;
			food_max = 35; food = food_max;
			moves = 2;
			age = 0;
			type = 'W';
			if (sex == "Male") isMale = true;
			if (sex == "Female") isMale = false;
			if (sex == "Random") isMale = rand() % 2;
		}
	};
		
			class Dolphin : public Neutral
	{
	public:
		Dolphin(string sex)
		{
			hp_max = 100; hp = hp_max;
			food_max = 20; food = food_max;
			moves = 5;
			damage = 25;
			age = 0;
			type = 'D';
			if (sex == "Male") isMale = true;
			if (sex == "Female") isMale = false;
			if (sex == "Random") isMale = rand() % 2;
		}
	};


	{
	public:
		Plankton()
		{
			hp_max = 3; hp = hp_max;
			moves = 1;
			age = 0;
			type = 'P';
		}
	};

	class Ocean_master
	{
		Ocean_field* ocean_table; 

		vector<Whale> fish_whale;
		vector<Dolphin> fish_dolphin;
		vector<Killerwhale> fish_killerwhale;
		vector<Shark> fish_shark;
		vector<Clownfish> fish_clownfish;
		vector<Fugu> fish_fugu;
		vector<Plankton> fish_plankton;
		Plankton* p_extra = new Plankton();
		Clownfish* c_extra = new Clownfish();
		Fugu* c_extra = new Fugu();

		int* find_empty_cell(bool isPlankton);

		//PLANKTON

		void Plankton_move(Plankton* p_obj);

		void Plankton_replicate(Plankton* p_obj);

		void Plankton_age(Plankton* p_obj, int order);

		//PASSIVES

		void Passive_move(Passive* c_obj);

		void Passive_eat(Passive* c_obj);

		void Passive_replicate(Passive* c_obj);

		void Passive_age(Passive* c_obj, int order);

		//NEUTRALS

		void Neutral_move(Neutral* c_obj);

		void Neutral_attack(Neutral* c_obj);

		void Neutral_eat(Neutral* c_obj);

		void Neutral_replicate(Neutral* c_obj);

		void Neutral_age(Neutral* c_obj, int order);

		//AGGRESSIVES

		void Aggressive_move(Aggressive* c_obj);

		void Aggressive_attack(Aggressive* c_obj);

		void Aggressive_eat(Aggressive* c_obj);

		void Aggressive_replicate(Aggressive* c_obj);

		void Aggressive_age(Aggressive* c_obj);

		//EVERYTHING ELSE

		Plankton& return_plankton(int x, int y);

		Clownfish& return_clownfish(int x, int y);

		Fugu& return_fugu(int x, int y);

		Dolphin& return_dolphin(int x, int y);

		Whale& return_whale(int x, int y);

		int empty_place(int x, int y, bool isPlankton);

	public:
		Ocean_master(int width_inp, int height_inp)
		{
			srand(time(0));
			ocean_table = new Ocean_field(width_inp, height_inp);
		}

		void Tick();

		void Show();

		void start_random_place(int, int, int, int, int, int, int);

		void UpdateMap();
	};
}