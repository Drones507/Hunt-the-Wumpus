#include "room.h"

using namespace std;
Room::Room(){
	this->e = nullptr;
}
Room::~Room(){
	if(this->e != nullptr){
		delete this->e;
	}
}
//CC
Room::Room(Event* new_event){
	this->e = new_event;
}
//AOO
//implement...
void Room::set_event(Event* new_event){
	if(this->e != nullptr){
		delete this->e;
	}
	this->e = new_event;
}
Event* Room::get_event(){
	return this->e;
}
char Room::get_char(){
	return e->get_sprite();
}
string Room::get_string(){
	return e->get_percept();
}
