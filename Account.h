#pragma once

#include "sha256.h"
#include "Validation.h"

#include <conio.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>
#include <iomanip>

using namespace std;

const string ADMIN_LOGIN = "ADMIN";
const string ADMIN_PASSWORD = "BSUIR";
const int ADMIN_ROLE = 1;
const int ADMIN_ACCESS = 1;

const string DATA_FILE_ACCOUNTS = "data_account.txt";

struct Account
{
	string login;
	string password;
	int role = 0;
	int access = 0;
	string salt;
	string salted_hash_password;
};

void listAccount(vector<Account>&vec_of_account);	// Меню для работы с аккаунтами
int menuAccount();	// Создание меню
void addAccount(vector<Account>& vec_of_account);	// Добавить аккаунт и в вектор, и в файл
void showAccount(vector<Account>& vec_of_account);	// Показать аккаунты
void deleteAccount(vector<Account>& vec_of_account);	// Удалить аккаунт
void updateAccount(vector<Account>& vec_of_account);	// Изменить данные аккаунта
void writeFileAccount(vector<Account>& vec_of_account);	// Записать вектор в файл
void readFileAccount(vector<Account>& vec_of_account);	// Прочитать файл с аккаунтами
int getCountOfStructuresAccount(string file_path);	// Получить кол-во строк файла для резервирования
string loginRepeatCheck(vector<Account>& vec_of_account);	// Проверка на оригинальность логина
string passwordCheck();	// Проверка на пароль, чтобы был от 6 до 16 символов
string repeatPasswordCheck(string password);	// Повторение пароля
string passwordStar();	// Замена пароля звёздочками при входе