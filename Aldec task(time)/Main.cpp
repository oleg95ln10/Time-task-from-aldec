#include <iostream>
#include "AnalogClock.h"


int main()
{
	AnalogClock *a = new AnalogClock("20:59:10",':');

	std::cout << *a;
	//a->AddHours(4);
	a->AddMinutes(125);
	std::cout << *a;

	std::cout << *a;
	std::cout << *a;
	std::cout << *a;
	std::cout << *a;
	delete a;
}