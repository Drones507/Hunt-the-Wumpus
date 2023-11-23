#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include <vector>
#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	//Game constructor
	//Your code here:
}

Game::~Game(){
	//Game destructor
	//Your code here:
}


void Game::set_up(int l, int w){
	//set up the game
	this->length = l;
	this->width = w;
	this->num_arrows = 3; 	//start with 3 arrows

//Maybe need to retweak this vecor, see lecture video
	vector<vector<Room>> gameboard(this->length, vector<Room>(this->width, Room())); 

	// randomly insert events (2 bats, 2 stalactites, 1 wumpus, 1 gold)
	// into the board
}

void Game::set_player_x(){
	this->player_x = rand()%this->length;
}
void Game::set_player_y() {
	this->player_y = rand()%this->width;
}

//Note: you need to modify this function
void Game::display_game() {
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;

	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";
	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			//The first char indicates whether there is a player in that room or not
			//if the room does not have the player, print space " "

			//else, print "*"

			//Fix the following

			if(player_x == j&& player_y == i){
				cout << "*"; 
			} else{
				cout << " ";
			}

			//The next two chars indicate the event in the room
			//if the room does not have an event, print "  ||" (2 spaces + ||)
			
			//else, 
				//if debug_view is true
					//print the corresponding char of the event
				//else
					//print " " (1 space)
				// print " ||" (1 space + ||)

			//Fix the following...
			cout << "  ||";
		}
		cout << endl;
	}
	cout << line << endl;

	//example output (when finished): 
	// --------------------
	//  B || G || B ||   ||
	// --------------------
	//    || W ||   || S ||
	// --------------------   
	//    ||   ||   || S ||
	// --------------------   
	// *  ||   ||   ||   ||
	// --------------------









//this->insert_event(new bats)
//this->insert_event(new bats);
//














}

bool Game::check_win() const{
	//check if game over/win
	//Your code here:
	cout << "Game::check_win() is not implemented..." << endl;
	return false;
}

void Game::move_up() {
	player_y -= 1;
	return;
}

void Game::move_down() {
	player_y += 1;
	return;
}

void Game::move_left() {
	player_x -= 1;
	return;
}
void Game::move_right() {
	player_x += 1;
	return;
}

char Game::get_dir(){
	//get direction of arrow:
	char dir;
	//Note: error checking is needed!! 
	//Your code here:
	cout << "Where will you shoot this arrow?" << endl;
	cout << "w-up" << endl;
	cout << "a-left" << endl;
	cout << "s-down" << endl;
	cout << "d-right" << endl;


	cout << "Enter direction: " << endl;
	cin >> dir;
	cin.ignore(256, '\n');

	return dir;
}

void Game::wumpus_move(){
	//after a missed arrow, 75% chance that the wumpus is moved to a different room

	//How to get 75%? 
	//Hint: generate a random number from 0-3, if the number is not 0, then move

	//Your code here:
	cout << "Game::wumpus_move() is not implemented..." << endl;
	
	return;
}

void Game::fire_arrow(){

	//NOTE::IF ARROW HITS WUMPUS NOT IMPLEMENTED 
	//////////////////////////////////////////////////////
	//Needs to subtract 1 arrow if shot
	//////////////////////////////////////////////////////
	char dir = get_dir();
	int arrow_y = this->player_y;
	int arrow_x = this->player_x;
	if(dir=='w'){
		num_arrows -= 1;
		for(int i = 0;i<3;i++){
			arrow_x+=1;
			if(arrow_x == 0){
		 		cout << "\nYour arrow hit a wall" << endl;
		 		return;
			}
			//IF ARROW HITS WUMPUS
		}
	}
	else if(dir=='s'){
		num_arrows -= 1;
		for(int i = 0;i<3;i++){
			if(arrow_x == width-1){
		 		cout << "\nYour arrow hit a wall" << endl;
		 	}
		 	//IF ARROW HITS WUMPUS
		} 
	}
	else if(dir=='a'){
		num_arrows -= 1;
		for(int i = 0;i < 3;i++){
			if(arrow_x == 0){
		 		cout << "\nYour arrow hit a wall" << endl;
		 	}
		 	//IF ARROW HITS WUMPUS
		}
	}
	else if(dir == 'd'){
		num_arrows -= 1;
		for(int i = 0;i < 3;i++){
			if(arrow_x == length-1){
				cout << "\nYour arrow hit a wall " << endl;
			}
			//IF ARROW HITS WUMPUS
		}
	}
	return;
}

void Game::move(char c) {
	switch(c){
		case 'w':
			if(player_y==0){
					cout << "\n*There is a wall here\n" << "**Try moving somewhere else" << endl;
			}
			else{
			Game::move_up();}
			break;
		case 'a':
			if(player_x == 0){
				cout << "\n*There is a wall here\n" << "**Try moving somewhere else" << endl;
			}
			else{
			Game::move_left();}
			break;
		case 's':
			if(player_y==width-1){
					cout << "\n*There is a wall here\n" << "**Try moving somewhere else" << endl;
			}
			else{
			Game::move_down();}
			break;
		case 'd':
			if(player_x == length-1){
					cout << "\n*There is a wall here\n" << "**Try moving somewhere else" << endl;
			}
			else{
			Game::move_right();}
			break;
		case 'f':
			if(num_arrows>0){
				fire_arrow();
				return;
			}
			else{
				cout << "\n*NO ARROWS REMAINING.";
			return;
		}

	}
}

char Game::get_input(){
	//get action, move direction or firing an arrow
	//Note: error checking is needed!!

	char c;

	cout << "w-up" << endl;
	cout << "a-left" << endl;
	cout << "s-down" << endl;
	cout << "d-right" << endl;
	cout << "f-fire an arrow" << endl;

	cout << "Enter input: " << endl;
	cin >> c;

	cin.ignore(256, '\n');

	return c;
}

//Note: you need to modify this function
void Game::play_game(int w, int l, bool d){


	Game::set_up(w, l);
	this->debug_view = d;
	char input;
	set_player_x();
	set_player_y();
	//int escaperope[2] = {set_player_x, set_player_y}; //const

	while (Game::check_win() == false){
		//print game board
		Game::display_game();

		//display percerts around player's location
		//Your code here:

		//Player move...
		//1. get input
		input = Game::get_input();
	
		//2. move player
		Game::move(input);

		//3. may or may not encounter events
		//Your code here:

	}
	return;
}



// void Game::insert_Event(Event* e){
// 	do{
// 		//Choose a random row 
// 		int row_idx = rand() % grid.size(); 
// 		//Choose a random collum
// 		int col_idx = rand() % (grid.at(0).size()); 
// 	}while(grid.at(row_idx).at(col_idx).get_event() != nullptr);

// 	//Place the event

// 	grid.at(row_idx).at(col_idx).set_event(e);



