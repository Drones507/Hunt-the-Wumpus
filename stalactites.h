#ifndef STALACTITES_H
#define STALACTITES_H 

#include "event.h"
using namespace std;

class Stalactites : public Event{
public:
	bool falling = false;
	Stalactites(char S, string percpt);
	char get_sprite(); 
	string get_percept();
	// void action() override; 
	
};
#endif
