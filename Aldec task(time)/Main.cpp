#include <iostream>
#include "AnalogClock.h"


int main()
{
	AnalogClock *a = new AnalogClock("20:59:10",':');

	std::cout << *a;
	a->AddSeconds(725);
	std::cout << *a;

	std::cout << *a;
	std::cout << *a;
	std::cout << *a;
	std::cout << *a;
	delete a;
}