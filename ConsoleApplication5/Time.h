#pragma once
#ifndef __TIME_H
#define __TIME_H



#include <iostream>
using namespace std;
class Time
{
private:
	friend class member;
	int hours;
	int minutes;
public:
	Time(int hours, int minutes);
	void showTime();
	void sethour(int hour);
	void setminutes(int minutes);
	int gethour() { return hours; }
	int getminutes(){return minutes; }
	Time();
};
#endif // 


