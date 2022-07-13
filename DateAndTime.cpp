#include "DateAndTime.h"

Date getCurrentDate()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	Date currentDate;
	currentDate.day = to_string(tm.wDay);
	currentDate.month = to_string(tm.wMonth);
	currentDate.year = to_string(tm.wYear);
	return currentDate;
}

Time getCurrentTime()
{
	SYSTEMTIME tm;
	GetLocalTime(&tm);
	Time currentTime;
	currentTime.hour = to_string(tm.wHour);
	currentTime.minute = to_string(tm.wMinute);
	currentTime.second = to_string(tm.wSecond);
	return currentTime;
}

void showDate(Date date)
{
	cout << date.day << "." << date.month << "." << date.year << endl;
}

void showTime(Time time)
{
	cout << time.hour << ":" << time.minute << ":" << time.second << endl;
}

void showNow(Date date, Time time)
{
	cout << "Now: " << date.day << "." << date.month << "." << date.year << " and " << time.hour << ":" << time.minute << ":" << time.second << endl;
}