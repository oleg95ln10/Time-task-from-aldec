#include <iostream>
#include "AnalogClock.h"


int main()
{
	AnalogClock *a = new AnalogClock("20/20/10",'/');

	std::cout << *a;

	delete a;
}