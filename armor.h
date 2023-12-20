#ifndef ARMOR_H
#define ARMOR_H

#include "event.h"
using namespace std;

class Armor : public Event{
public:
	Armor(char e);
	void action() override;
}
