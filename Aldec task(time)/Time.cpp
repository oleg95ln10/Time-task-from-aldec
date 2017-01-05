#include "Time.h"
#include <cassert>

AnalogClock::AnalogClock(int hours, int minutes, int seconds)
{
	if (!isValid())
	{
		m_hours = hours;
		m_minutes = minutes;
		m_seconds = seconds;
	}
}
AnalogClock::AnalogClock(const char * _time,char _sep)
{
	char sep1, sep2;
	auto match = scanf_s(_time, "%d%c%d%c%d", &m_hours, &sep1, &m_minutes, &sep2, &m_seconds);

	if (match != 5 || sep1 != _sep || sep2 != _sep)
	{
		throw std::logic_error("BAD TIME FORMAT!!!");
	}

	if (!isValid())
	{
		throw std::logic_error("BAD TIME FORMAT!!!");
	}
}
void AnalogClock::addHours(int value)//23 59 12
{
	m_hours += value;
}
void AnalogClock::addMinutes(int value)
{
	int i = 0;
	if (value >= 59)
	{
		addHours(1);
		i = value - 59;
		addMinutes(i);
	}
	m_minutes += i;
}
void AnalogClock::addSeconds(int value)
{
	int i = 0;//для точного высчета времени
	if (value >= 59)
	{
		addMinutes(1);
		i = value - 59;
		addSeconds(i);
	}
	m_seconds += i;
}
void AnalogClock::substractHours(int hours)
{
	m_hours - hours;
}
void AnalogClock::substractMinutes(int minutes)//70
{
	int i = 0;
	if (minutes > 59)
	{
		setHours(-1);
		i = minutes - 60;
		substractMinutes(i);
	}
	m_minutes += i;
}
void AnalogClock::substractSeconds(int seconds)
{
	int i = 0;
	if (seconds > 59)
	{
		setHours(-1);
		i = seconds - 60;
		substractSeconds(i);
	}
	m_minutes += i;
}
int AnalogClock::getHoursArrowAngle()//*30
{
	int grad;
	if (m_hours > 12)
	{
		grad = (m_hours - 12)*30;
	}
	else
	{
		grad = m_hours * 30;
	}
	return grad;
}
int AnalogClock::getMinutesArrowAngle()
{
	int grad;
	if (m_minutes > 59)
	{
		grad = ( m_minutes - 60) * 6;
	}
	else
	{
		grad = m_minutes * 6;
	}
	return grad;
}
int AnalogClock::getSecondsArrowAngle()
{
	return getMinutesArrowAngle();
}
bool AnalogClock::isValid()
{
	if (m_hours < 23 || m_minutes < 59 || m_seconds < 59)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool AnalogClock::operator!=(AnalogClock & a)const
{
	return a.getHours() != getHours() &&
		a.getMinutes() != getMinutes() &&
		a.getSeconds() != getSeconds();
}

bool AnalogClock::operator==(AnalogClock & a)const
{
	return !(*this != a);
}
std::ostream & operator <<(std::ostream & _o, AnalogClock & _a)
{
	_o << _a.getHours() << " " << _a.getMinutes() << " " << _a.getSeconds();
	return _o;
}
