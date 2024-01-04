#include <iostream>
#include "bats.h"

using namespace std;

Bats::Bats(char B, string percpt)
	: Event(B, percpt){
	}

char Bats::get_sprite(){
	return sprite;
}
string Bats::get_percept(){
	return percept;
}
