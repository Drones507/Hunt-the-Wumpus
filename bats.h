#ifndef BATS_H
#define BATS_H 

#include "event.h"
using namespace std;

class Bats : public Event{
	public:
		bool confused = false; 
		Bats(char B, string percpt);
		char get_sprite();
		string get_percept();
};
#endif
