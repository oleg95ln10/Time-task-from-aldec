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
	inline	int AnalogClock::getHours() const
	{
		return m_hours;
	}
	inline	int AnalogClock::getMinutes() const
	{
		return m_minutes;
	}
	inline	int AnalogClock::getSeconds() const
	{
		return m_seconds;
	}
	inline	int AnalogClock::setHours(int hours)
	{
		return m_hours = hours;
	}
	inline	int AnalogClock::setMinutes(int minutes)
	{
		return m_minutes = minutes;
	}
	inline	int AnalogClock::setSeconds(int seconds)
	{
		return m_seconds = seconds;
	}
	void addHours(int hours);
	void addMinutes(int minutes);
	void addSeconds(int seconds);
	void substractHours(int hours);
	void substractMinutes(int minutes);
	void substractSeconds(int seconds);
	int getHoursArrowAngle();
	int getMinutesArrowAngle();
	int getSecondsArrowAngle();
	bool isValid();
	bool operator != (AnalogClock &a)const;
	bool operator == (AnalogClock &a)const;
	friend std::ostream & operator << (std::ofstream & o, AnalogClock & a);
};
