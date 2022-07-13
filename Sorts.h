#pragma once

#include "Account.h"
#include "Player.h"

#include<iostream>

using namespace std;

void sortAccountByLogin(vector<Account>& vec_of_account);	// Сортировка по логину
bool mySortByLogin(Account account_a, Account account_b); // Компаратор по алфавиту: от а до я

void sortPlayerByName(vector<Player>& vec_of_player);	// Сортировка по имени
bool CompSortByName(Player player_a, Player player_b);	// Компаратор по алфавиту: от а до я
void sortPlayerByMatches(vector<Player>& vec_of_player);	// Сортировка по матчам
bool CompSortByMatches(Player player_a, Player player_b);	// Компаратор по матчам
void sortPlayerByGoals(vector<Player>& vec_of_player);	// Сортировка по голам
bool CompSortByGoals(Player player_a, Player player_b);	// Компаратор по голам
void sortPlayerByRed(vector<Player>& vec_of_player);	// Сортировка по красным карточкам
bool CompSortByRed(Player player_a, Player player_b);	// Компаратор по красным карточкам

void sortPlayerByMVP(vector<Player>& vec_of_player);	// Сортировка по ценности игрока
bool mySortByMVP(Player player_a, Player player_b);	// Компаратор по ценности