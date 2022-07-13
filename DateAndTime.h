#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>

using namespace std;

struct Date
{
	string day;
	string month;
	string year;
};

struct Time
{
	string hour;
	string minute;
	string second;
};

Date getCurrentDate();	// Получить текущую дату вида dd.mm.yyyy
Time getCurrentTime();	// Получить текущее время вида hh.mm.ss
void showDate(Date date);	// Показать дату
void showTime(Time time);	// Показать время
void showNow(Date date, Time time);	// Показать текущую дату и время