#ifndef WUMPUS_H
#define WUMPUS_H 

#include "event.h"
using namespace std;

class Wumpus : public Event{
public:
	bool confused = false; 
	Wumpus(char W, string percpt); 
	char get_sprite();
	string get_percept();
	// void action();
	
};
#endif
