#include "wumpus.h"
#include <iostream>
using namespace std;

Wumpus::Wumpus(char W, string percpt)
	: Event(W, percpt){
	}
char Wumpus::get_sprite(){
	return sprite;
}	
string Wumpus::get_percept(){
	return percept;
}
