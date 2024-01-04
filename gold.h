#ifndef GOLD_H
#define GOLD_H 

#include "event.h"
using namespace std;

class Gold : public Event{
	public: 
		bool hasgold = false;
		Gold(char G, string percpt);
		char get_sprite();
		string get_percept();
};
#endif
