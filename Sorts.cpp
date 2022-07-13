#include "Sorts.h"

void sortAccountByLogin(vector<Account>&vec_of_account)
{
	sort(vec_of_account.begin(), vec_of_account.end(), mySortByLogin);
}

bool mySortByLogin(Account account_a, Account account_b)
{
	return account_a.login < account_b.login;
}

void sortPlayerByName(vector<Player>&vec_of_player)
{
	sort(vec_of_player.begin(), vec_of_player.end(), CompSortByName);
}

bool CompSortByName(Player player_a, Player player_b)
{
	return player_a.name < player_b.name;
}

void sortPlayerByMatches(vector<Player>&vec_of_player)
{
	sort(vec_of_player.begin(), vec_of_player.end(), CompSortByMatches);
}

bool CompSortByMatches(Player player_a, Player player_b)
{
	return player_a.matches < player_b.matches;
}

void sortPlayerByGoals(vector<Player>&vec_of_player)
{
	sort(vec_of_player.begin(), vec_of_player.end(), CompSortByGoals);
}

bool CompSortByGoals(Player player_a, Player player_b)
{
	return player_a.goals < player_b.goals;
}

void sortPlayerByRed(vector<Player>&vec_of_player)
{
	sort(vec_of_player.begin(), vec_of_player.end(), CompSortByRed);
}

bool CompSortByRed(Player player_a, Player player_b)
{
	return player_a.red < player_b.red;
}

//INDIVIDUAL//
void sortPlayerByMVP(vector<Player>&vec_of_player)
{
	sort(vec_of_player.begin(), vec_of_player.end(), mySortByMVP);
}																			

bool mySortByMVP(Player player_a, Player player_b)
{
	return (player_a.goals + player_a.assists) > (player_b.goals + player_b.assists);
}
																			