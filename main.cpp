/*********************************************************************
** Program Filename: Assignment 4
** Author: Christopher Harvey
** Date: 11/22/23
** Description: Hunt the Wumpus is a 2 dimensional text-based adventure game. 
* The player moves through a series of connected caves arranged as the verticies of a polyhedron.
** Input: length of cave, width of cave, wasd, f, q.
** Output: A 2 dimensional adventure experience. 
*********************************************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include "event.h"
#include "bats.h"
using namespace std;
/*********************************************************************
** Function: greet 
** Description: Greets the user 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: print 
*********************************************************************/
void greet(){
	cout << "\n\n**********************************************\n";
	cout << "       -       HUNT THE WUMPUS       -         \n";
	cout << "**********************************************\n\n";
	cout << "*Choose your difficulty: \n";
}
/*********************************************************************
** Function: get_wid
** Description: get the width from the user  
** Parameters: int wid
** Pre-Conditions: none
** Post-Conditions: return wid for grid 
*********************************************************************/
int get_wid(int wid){
	cout << "\n*Enter the width of your cave(must be between 4-50): ";
	bool check = false;
	while(check == false){
		cin >> wid;
		if(wid < 4){
			cout << "\n*You have to enter a number greater than 4.\n";
			cout << "*Try again: "; 
		}else if(wid > 50){
			cout << "\n*You have to enter a number less than 50.\n";
			cout << "*Try again: "; 
		}
		else{
			check = true;
		}
	}
return wid;
}
/*********************************************************************
** Function: get_len
** Description: gets the lendth from the user 
** Parameters: int wid
** Pre-Conditions: none
** Post-Conditions: return length for grid 
*********************************************************************/
int get_len(int len){
	cout << "\n*Enter the length of your cave(must be between 4-50): ";
	bool check = false;
	while(check == false){
		cin >> len;
		if(len < 4){
			cout << "\n*You have to enter a number greater than 4.\n";
			cout << "*Try again: "; 
		}else if(len > 50){
			cout << "\n*You have to enter a number less than 50.\n";
			cout << "*Try again: "; 
		}
		else{
			check = true;
		}
	}
return len;
}
/*********************************************************************
** Function: get_mode
** Description: Asks the user for debug mode or not 
** Parameters: bool 
** Pre-Conditions: none
** Post-Conditions: return bool 
*********************************************************************/
bool get_mode(bool debug){
	string choice;
	cout << "\n*Are you debugging?"; 
	cout << "\n**(yes or no):";
	cin.ignore(256, '\n');
	getline(cin, choice);
	if(choice == "yes"){
		debug = true; 
	}
	else{
		debug = false;
	}
return debug;
}
/*********************************************************************
** Function: main
** Description: driver function 
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none 
*********************************************************************/
int main()
{
	///////////random seed///////////
	srand(time(NULL));
	//////////Declare variables/////
	int wid, len; //Actual Variable
	int width, length; //Garbage Variable
	bool debug, mode = false;
	////////////Drive///////////////
	Game g;
	greet();
	wid = get_wid(width);
	len = get_len(length);
	debug = get_mode(mode); 
	//Play game
	g.play_game(wid, len, debug);

	return 0;
}


//NOTES::
//Current Step : Implement Action Functons 
//Next Step : Improve the functionality of events when >1



