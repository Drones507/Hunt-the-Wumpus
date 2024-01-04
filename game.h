#ifndef GAME_H
#define GAME_H 

#include <vector>
#include <iostream> 
#include "room.h"

using namespace std;

//Game interface 
class Game{
private:
	//Primitives
	int length, width; 		
	int num_arrows; 		
	bool debug_view;		
	int player_y, player_x;
	int gold_x, gold_y;
	int stal_x, stal_y;
	int bat_x, bat_y;
	int armor_x, armor_y;
	int wumpus_x, wumpus_y;
	//Special data
	vector<vector<Room>> myvect;
	Event* e; 
public:
	//suggested functions:
	Game();
	~Game();
/*********************************************************************
** Function: set_player_x
** Description: randomizes the players initial starting position 
** Parameters: none
** Pre-Conditions: the player and grid exist
** Post-Conditions: places the player 
*********************************************************************/
	void set_player_x();
/*********************************************************************
** Function: set_player_y
** Description: randomizes the players initial starting position 
** Parameters: none
** Pre-Conditions: the player and grid exist
** Post-Conditions: places the player 
*********************************************************************/
	void set_player_y();
/*********************************************************************
** Function: set_up
** Description: sets up the size of the grid based on width and length retrieve from user 
** Parameters: int, int 
** Pre-Conditions: the player enters the correct data for parameters
** Post-Conditions: vector exists 
*******************************s**************************************/
	void set_up(int length, int width); 
/*********************************************************************
** Function: set_bats
** Description: randomizes the bats x and y coordinate
** Parameters: none
** Pre-Conditions: bat class is configured
** Post-Conditions: bats x and y coordinate
*********************************************************************/
	void set_bats();
	void set_stalactites();
	void set_armor();
	void set_gold();
	void set_wumpus();
/*********************************************************************
** Function: add_bats
** Description: places both bats in grid 
** Parameters: none
** Pre-Conditions: bat class is configured
** Post-Conditions: places the bat
*********************************************************************/
	void add_bats();
	void add_stalactites();
	void place_events();
/*********************************************************************
** Function: percept
** Description: notifies player that they are near a event
** Parameters: none
** Pre-Conditions: Player needs to be next to event. 
** Events must be configured and pure virtual
** Post-Conditions: print
*********************************************************************/
	void armor_percept();
	void bat_percept();
	void gold_percept();
	void stal_percept();
	void wumpus_percept();
/*********************************************************************
** Function: display_game
** Description: displays the game to terminal 
** Parameters: bool debug_mode
** Pre-Conditions: vector is created 
** Post-Conditions: prints until user wins/losses
*********************************************************************/
	void display_game(bool);
/*********************************************************************
** Function: check_win
** Description: 
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
	bool check_win() const;
/*********************************************************************
** Function: get_dir
** Description: called when the user choose to shoot an arrow, asks them which direction to shoot
** Parameters: none
** Pre-Conditions: must enter correct char
** Post-Conditions: -1 arrow
*********************************************************************/
	char get_dir();
/*********************************************************************
** Function:
** Description: 
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
	void wumpus_move();
/*********************************************************************
** Function: fire_arrow
** Description: fires an arrow in the chosen direction 3 spaces
** Parameters: none
** Pre-Conditions: arrows > 0
** Post-Conditions: -1 arrow
*********************************************************************/
	void fire_arrow();
/*********************************************************************
** Function: directional move functions
** Description: any function can be called based on WASD
** Parameters: none
** Pre-Conditions: grid exists and there isnt a wall where they input
** Post-Conditions: move player
*********************************************************************/
	void move_up();
	void move_down();
	void move_left();
	void move_right();
/*********************************************************************
** Function: move
** Description: handles player's action: move or fire an arrow
** Parameters: char
** Pre-Conditions: player and grid exists. User has >0 arrows
** Post-Conditions: moves player/shoots arrow
*********************************************************************/
	void move(char);
/*********************************************************************
** Function: get_input 
** Description: gets the input from the user. Either wasd or f
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the users choice as a char
*********************************************************************/
	char get_input();
/*********************************************************************
** Function: play_game
** Description: contains the loop and all functions for each turn 
** Parameters: width, length, debug mode
** Pre-Conditions: grid exists and the game is not over 
** Post-Conditions: delete memory
*********************************************************************/
	void play_game(int, int, bool);
};
#endif
