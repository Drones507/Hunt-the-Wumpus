#include "event.h"

using namespace std;
//Event Big3 Implementation

//Default Constructor
Event::Event(char e, string p)
	: sprite(e), percept(p){
}
void Event::set_sprite(char e){
	sprite = e;
}
void Event::set_percept(string p){
	percept = p;
}
char Event::get_sprite(){
	return sprite;
}
string Event::get_percept(){
	return percept;
}
