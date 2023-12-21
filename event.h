#ifndef EVENT_H
#define EVENT_H 

#include <string>
#include <iostream>
using namespace std;

//Event Interface
//Note: this must be an abstract class!

class Event{
protected: 
	char sprite;
	string percept;
public:
/*********************************************************************
** Function: Event non-defualt constructor 
** Description: Constructs all Event class variables for every member class 
** Parameters: char
** Pre-Conditions: none  
** Post-Conditions: none
*********************************************************************/
	Event(char sprite);
/*********************************************************************
** Function: set_sprite
** Description: 
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
	void set_sprite(char e);
/*********************************************************************
** Function: set_percept
** Description: 
** Parameters: 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
	void set_percept(string p);
/*********************************************************************
** Function: get_sprite
** Description: pure virtual function 
** Parameters: char 
** Pre-Conditions:
** Post-Conditions:
*********************************************************************/
	virtual char get_sprite() = 0;
/*********************************************************************
** Function: get_percept
** Description: pure virtual function  
** Parameters: char
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
	virtual string get_percept() = 0;
	//Polymorphic Function 
	virtual void action() = 0;
};
#endif
