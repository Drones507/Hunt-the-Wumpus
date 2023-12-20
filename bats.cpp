#include <iostream>
#include "bats.h"

using namespace std;

Bats::Bats(char B)
	: Event(B){
}
void Bats::action(){
	confused = true;
}
char Bats::get_sprite(){
	return sprite;
}
string Bats::get_percept(){
	// percept = "\n ! You hear wings flapping...\n";
	return percept;
}
//Bats Implementation
