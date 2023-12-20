#include <iostream>
#include "armor.h"

using namespace std;

Armor::Armor(char e)
	: Event(e){
		cout << "Default Armor Constructor!"; //Delete this later
	}
void Armor::action(){
	cout << "The Power\n";
}
//x
