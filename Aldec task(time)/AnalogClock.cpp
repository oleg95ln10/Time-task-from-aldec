#include "AnalogClock.h"

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

void AnalogClock::AddHours(int _hours)
{
	if (GetHours() + _hours <= 23)
		m_hours += _hours;
	else
		m_hours = 0;
}

void AnalogClock::AddMinutes(int _minutes)
{
	if (GetMinutes() + _minutes <= 59)
		m_minutes += _minutes;
	else
	{
		AddHours((GetMinutes() + _minutes) / 60);
		m_minutes = (GetMinutes() + _minutes) % 60;
	}
}

void AnalogClock::AddSeconds(int _seconds)
{
	if (GetSeconds() + _seconds <= 59)
	{
		m_seconds += _seconds;
	}
	else
	{
		AddMinutes((GetSeconds() + _seconds) / 60);
		m_seconds = (GetSeconds() + _seconds) % 60;
	}
}

void AnalogClock::SubstractHours(int _hours)
{

}

void AnalogClock::SubstractMinutes(int _minutes)
{
}

void AnalogClock::SubstractSeconds(int _seconds)
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

bool AnalogClock::operator!=(AnalogClock & _a) const
{
	return _a.GetHours() != GetHours() &&
		_a.GetMinutes() != GetMinutes() &&
		_a.GetSeconds() != GetSeconds();
}

bool AnalogClock::operator==(AnalogClock & _a) const
{
	return !(*this != _a);
}

std::ostream & operator <<(std::ostream & _o, AnalogClock & _a)
{
	_o <<"Time is: " <<_a.GetHours() << " : " << _a.GetMinutes() << " : " << _a.GetSeconds()<<std::endl;
	return _o;
}
