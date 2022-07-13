#include "MainMenu.h"

int main()
{
	setlocale(LC_ALL, "rus");
	vector<Account> vec_of_account;
	vec_of_account.reserve(getCountOfStructuresAccount(DATA_FILE_ACCOUNTS));
	readFileAccount(vec_of_account);
	vector<Player> vec_of_player;
	vec_of_player.reserve(getCountOfStructuresPlayer(DATA_FILE_PLAYERS));
	readFilePlayer(vec_of_player);
	mainMenu(vec_of_account, vec_of_player);
	writeFileAccount(vec_of_account);
	writeFilePlayer(vec_of_player);
	system("pause");
}