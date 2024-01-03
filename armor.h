#ifndef ARMOR_H
#define ARMOR_H

#include "event.h"
using namespace std;

class Armor : public Event{
	public:
		bool power = true; 
		Armor(char A, string percpt);
		char get_sprite();
		string get_percept();
		// void action() override;
};
#endif
