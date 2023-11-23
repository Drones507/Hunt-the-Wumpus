#include <iostream>
#include <cstdlib>
#include <ctime>
#include "game.h"

using namespace std;

void greet(){
	cout << "\n\n**********************************************\n";
	cout << "       -       HUNT THE WUMPUS       -         \n";
	cout << "**********************************************\n\n";
	cout << "*Choose your difficulty: \n";
}
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
bool get_mode(bool debug){
	string choice;
	cout << "\n*Are you familiar with the cave?"; 
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



