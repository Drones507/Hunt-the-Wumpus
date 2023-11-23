#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;

//Room Interface
//Note: Each room may be empty or has an event (bat, gold, pit, or wumpus);
//		Use event polymorphically

class Room
{
private: 
	Event *e;
	//EX: If the player gets the goal, it needs to despawn which I can do by setting the pointer to null

public:
	void set_event(Event *new_event);
	Event* get_event() const;

};

#endif