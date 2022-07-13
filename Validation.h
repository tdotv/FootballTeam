#pragma once

#include "sha256.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <conio.h>
#include <Windows.h>

using namespace std;

const int LIMIT = 3;
const int SALT_SIZE = 16; // длина соли
const int SYMBOLS_SIZE = 62; // набор символов, из которых генерируется соль

int correctInputInt();	// Проверка на ввод int числа
string checkDate();	// Проверка на ввод даты
string enterText();	// Ввод только текста
string generateSalt(int salt_size);	// Функция генерации соли
string getSymbolsForSalt();	// Функция формирования набора символов
bool deleteСonfirmation();	// Подтверждение удаления
bool isCorrectDate(int day, int month, int year);	// Обработка исключений для checkDate