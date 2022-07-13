#pragma once

#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <string>

#include "Account.h"
#include "Player.h"
#include "Sorts.h"
#include "Searches.h"
#include "Validation.h"
#include "DateAndTime.h"

using namespace std;

void userMenu(vector<Player>& vec_of_player);	// Меню Пользователя
void searchMenu(vector<Player>& vec_of_player);	// Меню поиска
void sortMenu(vector<Player>& vec_of_player);	// Меню сортировкм
void individualTask(vector<Player>& vec_of_player);	// Вывести шесть лучших игроков (голы + передачи) с указанием их результативности. Вывести всех игроков, имеющих в активе красные карточки.