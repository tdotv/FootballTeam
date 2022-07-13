#pragma once

#include "Validation.h"
#include "Account.h"
#include "Player.h"
#include "UserMenu.h"
#include "sha256.h"
#include "DateAndTime.h"

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>

using namespace std;

void mainMenu(vector<Account>& vec_of_account, vector<Player>& vec_of_player);	// Меню Авторизации и регистрации
void authorization(vector<Account>& vec_of_account, vector<Player>& vec_of_player);	// Авторизация
void adminMenu(vector<Account>& vec_of_account, vector<Player>& vec_of_player);	// Меню администратора по работе или обработке данных
void workWithAccountMenu(vector<Account>& vec_of_account); // Меню работы с аккаунтами
void workWithDataMenu(vector<Player>& vec_of_player);	// Меню работы с данными игроков
