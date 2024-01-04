#ifndef ROOM_H
#define ROOM_H 

#include "event.h"

using namespace std;
class Room
{
private: 
	Event *e;
	//EX: If the player gets the gold, it needs to despawn which I can do by setting the pointer to null
public:
/*********************************************************************
** Function: Default Constructor 
** Description: initializes pointer to nullptr
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
	Room();
/*********************************************************************
** Function: Destructor 
** Description: If the pointer points to memory, delete pointer memory pointed to
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
	~Room();
	Room(Event *new_event); 
/*********************************************************************
** Function: set_event 
** Description: sets a new event to a room if a event does not 
** already exist in that room. if it does delete...
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
	void set_event(Event *new_event);
/*********************************************************************
** Function: get_event
** Description: gets pointed to event and passes as const
** Parameters: none 
** Pre-Conditions: none 
** Post-Conditions: none 
*********************************************************************/
	Event* get_event();
/*********************************************************************
** Function: get_sprite 
** Description: passes event sprite (char)
** Parameters: none 
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
	char get_char();
	string get_string();
/*********************************************************************
** Function: check_event
** Description: only a debugger, checks if there is an event in the room, returns bool
** Parameters: none 
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/	
	bool check_event();

};

#endif
