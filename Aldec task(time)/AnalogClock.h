#pragma once
#include <iostream>
#include <string>
class AnalogClock
{
public:
	AnalogClock(int hours, int minutes, int seconds);
	AnalogClock(const char * time,char sep);

private:
	int m_hours;
	int m_minutes;
	int m_seconds;
public:
	inline	int AnalogClock::GetHours() const
	{
		return m_hours;
	}
	inline	int AnalogClock::GetMinutes() const
	{
		return m_minutes;
	}
	inline	int AnalogClock::GetSeconds() const
	{
		return m_seconds;
	}
	void AddHours(int hours);
	void AddMinutes(int minutes);
	void AddSeconds(int seconds);
	void SubstractHours(int hours);
	void SubstractMinutes(int minutes);
	void SubstractSeconds(int seconds);
	int GetHoursArrowAngle();
	int GetMinutesArrowAngle();
	int GetSecondsArrowAngle();
	bool IsValid() const;
	bool operator != (AnalogClock &a)const;
	bool operator == (AnalogClock &a)const;
	friend std::ostream & operator << (std::ostream & o, AnalogClock & a);
};
