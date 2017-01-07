#include <iostream>
#include "AnalogClock.h"


int main()
{
	AnalogClock *a = new AnalogClock("20:59:59",':');

	std::cout << *a;
	a->SubstractSeconds(120);
	std::cout << *a;
	delete a;
}