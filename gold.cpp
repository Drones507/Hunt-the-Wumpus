#include <iostream>
#include "gold.h"

using namespace std;

Gold::Gold(char G, string percpt)
	: Event(G, percpt){
	}
char Gold::get_sprite(){
	return sprite;
}
string Gold::get_percept(){
	return percept;
}
