#include "AnalogClock.h"
#include <cassert>

AnalogClock::AnalogClock(int _hours, int _minutes, int _seconds)
	:	m_hours(_hours),
	m_minutes(_minutes),
	m_seconds(_seconds)
{
	if (!IsValid())
			throw std::logic_error("Error: time is not valid!");
}
AnalogClock::AnalogClock(const char * _hhmmss, char _sep)
{
	char sep1, sep2;
	int match = sscanf(_hhmmss, "%d%c%d%c%d", &m_hours, &sep1, &m_minutes, &sep2, &m_seconds);

	if (match != 5 || sep1 != _sep || sep2 != _sep)
		throw std::logic_error("BAD TIME FORMAT!!!");

	if (!IsValid())
		throw std::logic_error("BAD TIME FORMAT!!!");
}

bool AnalogClock::IsValid() const
{
	if (m_hours < 0 || m_hours > 23)
		return false;

	return m_minutes >= 0 && m_minutes <= 59;
}

void AnalogClock::AddHours(int hours)
{
}

void AnalogClock::AddMinutes(int minutes)
{
}

void AnalogClock::AddSeconds(int seconds)
{
}

void AnalogClock::SubstractHours(int hours)
{
}

void AnalogClock::SubstractMinutes(int minutes)
{
}

void AnalogClock::SubstractSeconds(int seconds)
{
}

int AnalogClock::GetHoursArrowAngle()
{
	return 0;
}

int AnalogClock::GetMinutesArrowAngle()
{
	return 0;
}

int AnalogClock::GetSecondsArrowAngle()
{
	return 0;
}















bool AnalogClock::operator!=(AnalogClock & a) const
{
	return a.GetHours() != GetHours() &&
		a.GetMinutes() != GetMinutes() &&
		a.GetSeconds() != GetSeconds();
}

bool AnalogClock::operator==(AnalogClock & a)const
{
	return !(*this != a);
}
std::ostream & operator <<(std::ostream & _o, AnalogClock & _a)
{
	_o <<"Time is: " <<_a.GetHours() << " : " << _a.GetMinutes() << " : " << _a.GetSeconds()<<std::endl;
	return _o;
}
