#include <iostream>
#include "armor.h"

using namespace std;

Armor::Armor(char A, string percpt)
	: Event(A, percpt){
	}

char Armor::get_sprite(){
	return sprite;
}
string Armor::get_percept(){
	return percept;
}
// void Armor::action(){
// 	cout << "The Power\n";
// }
//
