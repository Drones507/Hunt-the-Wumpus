#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game{
private:
	//other member variables:
	int length; 			//length of the board
	int width;  			//width of the board
	int num_arrows; 		//keep track of number of arrows remaining
	bool debug_view;		//debug mode or not
	int player_y;
	int player_x;
	Room room;
	vector<vector<Room>> myvect(int, vector<Room>(int, Room()));
	//Wumpus_x
	//Wumpus_y
	//Bats_x[2] = {}
	//Bats_y[2] = {}
	//Gold_x
	//Gold_y
	//Stalactite_x[2] = {}
	//Stalactite_y[2] = {}
	//feel free to add more variables...

public:

	//suggested functions:
	Game();
	~Game();
	
	void set_player_x();
	void set_player_y();

	void set_up(int length, int width); 

	int randomize_location();

	void display_game() ;

	bool check_win() const;

	char get_dir();
	void wumpus_move();
	void fire_arrow();

	void move_up();
	void move_down();
	void move_left();
	void move_right();
	// Handle player's action: move or fire an arrow
	void move(char);

	char get_input();

	void play_game(int, int, bool);

	//void insert_Event(Event* e);

	//feel free (and you will need) to add more functions...

};
#endif