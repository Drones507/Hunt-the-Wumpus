#include "game.h"
#include "gold.h"
#include "stalactites.h"
#include "bats.h"
#include "wumpus.h"
#include "armor.h"
#include <vector>
#include <iostream>

using namespace std;

//Game Implementation

Game::Game(){
	// player_y = 0;
	// player_x = 0;
	// this->gold_x = 0;
	// this->gold_y = 0;
	// this->wumpus_x = 0;
	// this->wumpus_y = 0;
}

Game::~Game(){

}

void Game::set_up(int w, int l){
	this->length = l;
	this->width = w;
	this->num_arrows = 3; 	//start with 3 arrows 
	myvect.resize(this->length);
	for (int i = 0; i < this->length; i++)
		myvect.at(i).resize(this->width);
}

void Game::set_player_x(){
	this->player_x = rand()%this->width;
}
void Game::set_player_y() {
	this->player_y = rand()%this->length;
} 

void Game::set_bats(){
	bool check = true;
	bat_x = rand()%this->width;
	bat_y = rand()%this->length;
	while(check == true){
		if(myvect[bat_y][bat_x].get_event() != nullptr){
			bat_x = rand()%this->width;
			bat_y = rand()%this->length;
		}
		else{
			check = false;
		}
	}
	myvect[bat_y][bat_x].set_event(new Bats('B', "You hear wings flapping nearby...\n"));
}
void Game::set_stalactites(){
	bool check = true;
	stal_x = rand()%this->width;
	stal_y = rand()%this->length;
	while(check == true){
		if(myvect[stal_y][stal_x].get_event() != nullptr){
			stal_x = rand()%this->width;
			stal_y = rand()%this->length;
		}
		else{
			check = false;
		}
	}
	myvect[stal_y][stal_x].set_event(new Stalactites('S', "You hear water dripping nearby...\n"));
}
void Game::set_armor(){
	bool check = true;
	armor_x = rand()%this->width;
	armor_y = rand()%this->length;
	while(check == true){
		if(myvect[armor_y][armor_x].get_event() != nullptr){
			armor_x = rand()%this->width;
			armor_y = rand()%this->length;
		}
		else{
			check = false;
		}
	}
	myvect[armor_y][armor_x].set_event(new Armor('A', "You feel the power...\n"));
}
void Game::set_gold(){
	bool check = true;
	gold_x = rand()%this->width;
	gold_y = rand()%this->length;
	while(check == true){
		if(myvect[gold_y][gold_x].get_event() != nullptr){
			gold_x = rand()%this->width;
			gold_y = rand()%this->length;
		}
		else{
			check = false;
		}
	}
	myvect[gold_y][gold_x].set_event(new Gold('G', "You see something glimmering nearby...\n"));
}
void Game::set_wumpus(){
	// int wumpus_x, wumpus_y;
	bool check = true;
	wumpus_x = rand()%this->width;
	wumpus_y = rand()%this->length;
	while(check == true){
		if(myvect[wumpus_y][wumpus_x].get_event() != nullptr){
			wumpus_x = rand()%this->width;
			wumpus_y = rand()%this->length;
		}
		else{
			check = false;
		}
	}
	myvect[wumpus_y][wumpus_x].set_event(new Wumpus('W', "You smell a horrible stench...\n"));
}

void Game::add_bats(){
	for(int i=0;i<2;i++){
		set_bats();
	}
}
void Game::add_stalactites(){
	for(int i=0;i<2;i++){
		set_stalactites();
	}
}
void Game::place_events(){
	add_bats();
	add_stalactites();
	set_armor();
	set_gold();
	set_wumpus();
}
void Game::armor_percept(){
	if((player_x == armor_x+1) && (player_y == armor_y)){
		cout << myvect[armor_y][armor_x].get_string();
		}
	else if((player_x == armor_x-1) && (player_y == armor_y)){
		cout << myvect[armor_y][armor_x].get_string();
		}
	else if((player_x == armor_x) && (player_y == armor_y-1)){
		cout << myvect[armor_y][armor_x].get_string();
		}
	else if((player_x == armor_x) && (player_y == armor_y+1)){
		cout << myvect[armor_y][armor_x].get_string();
		}
}
void Game::bat_percept(){
	if((player_x == bat_x+1) && (player_y == bat_y)){
		cout << myvect[bat_y][bat_x].get_string();
		}
	else if((player_x == bat_x-1) && (player_y == bat_y)){
		cout << myvect[bat_y][bat_x].get_string();
		}
	else if((player_x == bat_x) && (player_y == bat_y-1)){
		cout << myvect[bat_y][bat_x].get_string();
		}
	else if((player_x == bat_x) && (player_y == bat_y+1)){
		cout << myvect[bat_y][bat_x].get_string();
		}
}	
void Game::gold_percept(){
	if((player_x == gold_x+1) && (player_y == gold_y)){
		cout << myvect[gold_y][gold_x].get_string();
		}
	else if((player_x == gold_x-1) && (player_y == gold_y)){
		cout << myvect[gold_y][gold_x].get_string();
		}
	else if((player_x == gold_x) && (player_y == gold_y-1)){
		cout << myvect[gold_y][gold_x].get_string();
		}
	else if((player_x == gold_x) && (player_y == gold_y+1)){
		cout << myvect[gold_y][gold_x].get_string();
		}
}
void Game::stal_percept(){
	if((player_x == stal_x+1) && (player_y == stal_y)){
		cout << myvect[stal_y][stal_x].get_string();
		}
	else if((player_x == stal_x-1) && (player_y == stal_y)){
		cout << myvect[stal_y][stal_x].get_string();
		}
	else if((player_x == stal_x) && (player_y == stal_y-1)){
		cout << myvect[stal_y][stal_x].get_string();
		}
	else if((player_x == stal_x) && (player_y == stal_y+1)){
		cout << myvect[stal_y][stal_x].get_string();
		}
}
void Game::wumpus_percept(){
	if((player_x == wumpus_x+1) && (player_y == wumpus_y)){
		cout << myvect[wumpus_y][wumpus_x].get_string();
		}
	else if((player_x == wumpus_x-1) && (player_y == wumpus_y)){
		cout << myvect[wumpus_y][wumpus_x].get_string();
		}
	else if((player_x == wumpus_x) && (player_y == wumpus_y-1)){
		cout << myvect[wumpus_y][wumpus_x].get_string();
		}
	else if((player_x == wumpus_x) && (player_y == wumpus_y+1)){
		cout << myvect[wumpus_y][wumpus_x].get_string();
		}
}
void Game::display_game(bool d) {
	//Store events in a room ((A vector container))
	//Create a display_events function
	//Display Events polymorphically with display_events function
	//Make sure to free memory
	cout << endl << endl;
	cout << "Arrows remaining: " << this->num_arrows << endl;
	cout << this->debug_view << endl;
	cout << "\n Wumpus: " << wumpus_x << "," << wumpus_y << endl;
	cout << "\n Gold: " << gold_x << "," << gold_y << endl;
	armor_percept();
	bat_percept();
	gold_percept();
	stal_percept();
	wumpus_percept();
	string line = "";
	for (int i = 0; i < this->width; ++i)
		line += "-----";
	for (int i = 0; i < this->length; ++i)
	{
		cout << line << endl;
		for (int j = 0; j < this->width; ++j)
		{
			// if (myvect[i][j].check_event()==true){
			//  	cout << myvect[i][j].get_char();
			// } Written by TA during offic hours 		
			if(player_x == j && player_y == i){
			   cout << "*"; 
			}else{
				cout << " ";
			}
			if(myvect[i][j].get_event() == nullptr){
				cout << "  ||";
			}
			else{
				//Debug game mode. Prints event sprites as characters
				if(this->debug_view == true){
					cout << myvect[i][j].get_char();
					cout << " ||";
				}
				//Regular game mode
				else{
					cout << "  ||";
				}
			}
		}
		cout << endl;
	}
	cout << line << endl;
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
    char dir;

    cout << "Where will you shoot this arrow?" << endl;
    cout << "w-up" << endl;
    cout << "a-left" << endl;
    cout << "s-down" << endl;
    cout << "d-right" << endl;
    cout << "Enter direction: " << endl;

    cin >> dir;
    cin.ignore(256, '\n');

    // Use && instead of ||
    if (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd') {
        do {
            cout << "Not a valid input, Try again :"; 
            cin >> dir;
            cin.ignore(256, '\n');
        } while (dir != 'w' && dir != 'a' && dir != 's' && dir != 'd');
    }
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

	char dir = get_dir();
	int arrow_y = this->player_y;
	int arrow_x = this->player_x;
	if(dir=='w'){
		num_arrows -= 1;
		for(int i=0;i<3;i++){
			arrow_y-=1;
			if(arrow_y+1 == 0){
		 		cout << "\nYour arrow hit a wall" << endl;
		 		i=3;
			}
			//IF ARROW HITS WUMPUS
		}
	}
	else if(dir=='s'){
		num_arrows -= 1;
		for(int i = 0;i<3;i++){
			arrow_y+=1;
			if(arrow_y == length-1){
		 		cout << "\nYour arrow hit a wall" << endl;
		 	}
		 	//IF ARROW HITS WUMPUS
		} 
	}
	else if(dir=='a'){
		num_arrows -= 1;
		for(int i = 0;i < 3;i++){
			arrow_x-=1;
			if(arrow_x+1 == 0){
		 		cout << "\nYour arrow hit a wall" << endl;
		 	}
		 	//IF ARROW HITS WUMPUS
		}
	}
	else if(dir == 'd'){
		num_arrows -= 1;
		for(int i = 0;i < 3;i++){
			arrow_x+=1;
			if(arrow_x == width-1){
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
			if(player_y==length-1){
					cout << "\n*There is a wall here\n" << "**Try moving somewhere else" << endl;
			}
			else{
			Game::move_down();}
			break;
		case 'd':
			if(player_x == width-1){
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
	place_events();
	while (Game::check_win() == false){
		//print game board
		Game::display_game(this->debug_view);
		//display percerts around player's location
		input = Game::get_input();
		Game::move(input);
		//3. may or may not encounter events
// Game::percept();
		//Action
	}
	return;
}
