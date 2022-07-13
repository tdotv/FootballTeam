#include "UserMenu.h"

void userMenu(vector<Player>& vec_of_player)
{
	int i_user_menu;
	bool in_user_menu = true;

	while (in_user_menu == true)  // цкюбмне лемч
	{
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "----------------USER-----------------" << endl;
		cout << "1)Show" << endl;
		cout << "2)Individual Task" << endl;
		cout << "3)Search" << endl;
		cout << "4)Sort" << endl;
		cout << "0) EXIT" << endl;

		i_user_menu = correctInputInt();
		switch (i_user_menu)
		{
		case 1:
			system("cls");
			showPlayer(vec_of_player);
			break;

		case 2:
			system("cls");
			individualTask(vec_of_player);
			break;

		case 3:
			system("cls");
			searchMenu(vec_of_player);
			break;

		case 4:
			system("cls");
			sortMenu(vec_of_player);
			break;

		case 0:
			system("cls");
			in_user_menu = false;
			break;

		default:
			break;
		}
	}
}

void searchMenu(vector<Player>& vec_of_player)
{
	int i_search_menu;
	bool in_search_menu = true;

	while (in_search_menu == true)  // цкюбмне лемч
	{
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "---------------Search----------------" << endl;
		cout << "1)By name." << endl;
		cout << "2)By matches." << endl;
		cout << "3)By goals." << endl;
		cout << "4)By red cards." << endl;
		cout << "0) BACK" << endl;

		i_search_menu = correctInputInt();

		switch (i_search_menu)
		{
		case 1:
			system("cls");
			searchByName(vec_of_player);
			break;

		case 2:
			system("cls");
			searchByMatches(vec_of_player);
			break;

		case 3:
			system("cls");
			searchByGoals(vec_of_player);
			break;

		case 4:
			system("cls");
			searchByRed(vec_of_player);
			break;

		case 0:
			system("cls");
			in_search_menu = false;
			break;

		default:
			break;
		}
	}
}

void sortMenu(vector<Player>& vec_of_player)
{
	int i_sort_menu;
	bool in_sort_menu = true;

	while (in_sort_menu == true)  // цкюбмне лемч
	{
		showPlayer(vec_of_player);

		cout << endl;
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "----------------SORT-----------------" << endl;
		cout << "1)By name." << endl;
		cout << "2)By matches." << endl;
		cout << "3)By goals." << endl;
		cout << "4)By red cards." << endl;
		cout << "0) BACK" << endl;

		i_sort_menu = correctInputInt();

		switch (i_sort_menu)
		{
		case 1:
			system("cls");
			sortPlayerByName(vec_of_player);
			break;

		case 2:
			system("cls");
			sortPlayerByMatches(vec_of_player);
			break;

		case 3:
			system("cls");
			sortPlayerByGoals(vec_of_player);
			break;

		case 4:
			system("cls");
			sortPlayerByRed(vec_of_player);
			break;

		case 0:
			system("cls");
			in_sort_menu = false;
			break;

		default:
			break;
		}
	}
}

void individualTask(vector<Player>& vec_of_player)
{
	sortPlayerByMVP(vec_of_player);

	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
			<< "|" << setw(11) << vec_of_player.at(i).birth
			<< "|" << setw(9) << vec_of_player.at(i).matches
			<< "|" << setw(7) << vec_of_player.at(i).goals
			<< "|" << setw(9) << vec_of_player.at(i).assists
			<< "|" << setw(8) << vec_of_player.at(i).yellow
			<< "|" << setw(5) << vec_of_player.at(i).red
			<< "|" << endl;
		if (i < vec_of_player.size() - 1)
			cout << endl;
	}
	cout << endl;
	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		if (vec_of_player.at(i).red>0)
		{
			cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
				<< "|" << setw(11) << vec_of_player.at(i).birth
				<< "|" << setw(9) << vec_of_player.at(i).matches
				<< "|" << setw(7) << vec_of_player.at(i).goals
				<< "|" << setw(9) << vec_of_player.at(i).assists
				<< "|" << setw(8) << vec_of_player.at(i).yellow
				<< "|" << setw(5) << vec_of_player.at(i).red
				<< "|" << endl;
			if (i < vec_of_player.size() - 1)
				cout << endl;
		}
	}
}