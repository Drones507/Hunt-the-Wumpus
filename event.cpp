#include "event.h"

using namespace std;
//Default Constructor
Event::Event(char e)
	: sprite(e){
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

void action(){
	return;
}
