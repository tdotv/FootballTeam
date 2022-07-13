	#pragma once

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

const string DATA_FILE_PLAYERS = "data_player.txt";

struct Player
{
	string name;	// ФИО
	string birth;	// Дата рождения
	int matches = 0;	// Матчи
	int goals = 0;	// Забитые мячи
	int assists = 0;	// Голевые передачи
	int yellow = 0;	// Желтые карточки
	int red = 0;	// Красные карточки
};

void listPlayer(vector<Player>& vec_of_player);	// Меню для работы с игроками
int menuPlayer();	// Создание меню
void addPlayer(vector<Player>& vec_of_player);	// Добавить игрока и в вектор, и в файл
void showPlayer(vector<Player>& vec_of_player);	// Показать игроков
void deletePlayer(vector<Player>& vec_of_player);	// Удалить игрока
void updatePlayer(vector<Player>& vec_of_player);	// Изменить данные игрока
void writeFilePlayer(vector<Player>& vec_of_player);	// Записать игроков в файл
void readFilePlayer(vector<Player>& vec_of_player);	// Прочитать файл с аккаунтами
int getCountOfStructuresPlayer(string file_path);	// Получить кол-во строк для резервирования
