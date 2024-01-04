#include <iostream>
#include "stalactites.h"

using namespace std;

Stalactites::Stalactites(char S, string percpt)
	: Event(S, percpt){
	}
char Stalactites::get_sprite(){
	return sprite; 
}
string Stalactites::get_percept(){
	return percept;
}
