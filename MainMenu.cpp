#include "MainMenu.h"

void mainMenu(vector<Account>& vec_of_account, vector<Player>& vec_of_player)
{
	int i_main_menu;
	bool in_main_menu = true;

	while (in_main_menu == true)
	{
		/*system("cls");*/
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "-------------------------------------" << endl;

		cout << "1) Enter in the system " << endl;
		cout << "2) Registration" << endl;
		cout << "0) EXIT" << endl;

		i_main_menu = correctInputInt();

		switch (i_main_menu)
		{
		case 1:
			authorization(vec_of_account, vec_of_player);
			break;

		case 2:
			system("cls");
			showNow(getCurrentDate(), getCurrentTime());
			cout << endl;
			cout << "----------MENU-------------" << endl;
			cout << "-------REGISTRATION--------" << endl;
			cout << endl;

			addAccount(vec_of_account);
			break;

		case 0:
			in_main_menu = false;
			break;

		default:
			break;
		}
	}
}

void authorization(vector<Account>& vec_of_account, vector<Player>& vec_of_player)
{
	system("cls");

	string enter_login, enter_password, enter_salted_hash_password;
	bool right_authorization = false;

	showNow(getCurrentDate(), getCurrentTime());
	cout << endl;
	cout << "----------------MENU-----------------" << endl;
	cout << "-------ENTERING IN THE SYSTEM--------" << endl;
	cout << endl;

	cout << "Enter login: ";
	cin >> enter_login;

	cout << "Enter password: ";
	enter_password = passwordStar();
	cout << endl;
	for (int i = 0; i < vec_of_account.size(); i++)
	{
		enter_salted_hash_password = sha256(sha256(enter_password + vec_of_account.at(i).salt) + sha256(enter_password));

		if (enter_login == vec_of_account[i].login && enter_salted_hash_password == vec_of_account[i].salted_hash_password && vec_of_account[i].role == 1)
		{
				system("cls");
				right_authorization = true;
				adminMenu(vec_of_account, vec_of_player);
		}

		if (enter_login == vec_of_account[i].login && enter_salted_hash_password == vec_of_account[i].salted_hash_password && vec_of_account[i].role == 0)
		{
			if (vec_of_account[i].access == 1)
			{
				system("cls");
				right_authorization = true;
				userMenu(vec_of_player);
			}
			else
			{
				system("cls");
				right_authorization = true;
				cout << "You have no access!" << endl;
			}


		}
	}

	if (right_authorization == false)
	{
		system("cls");
		cout << "Wrong login or password." << endl;
		cout << endl;
	}
}

void adminMenu(vector<Account>& vec_of_account, vector<Player>& vec_of_player)
{
	bool in_admin_menu = true;
	int i_admin_menu;

	system("cls");

	while (in_admin_menu == true)
	{
		system("cls");

		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "------------ADMINISTRATOR------------" << endl;
		cout << "1)Accounts." << endl;
		cout << "2)Data." << endl;
		cout << "0) EXIT." << endl;

		i_admin_menu = correctInputInt();

		switch (i_admin_menu)
		{
		case 1:

			system("cls");
			workWithAccountMenu(vec_of_account);
			break;

		case 2:
			system("cls");
			workWithDataMenu(vec_of_player);
			break;
		case 0:
			system("cls");
			in_admin_menu = false;
			break;

		default:
			break;
		}
	}
}

void workWithAccountMenu(vector<Account>& vec_of_account)
{
	bool in_account_menu = true;
	int i_account_menu;

	while (in_account_menu == true)
	{
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "--------------ACCOUNTS---------------" << endl;
		cout << "1)Show." << endl;
		cout << "2)Add." << endl;
		cout << "3)Redact." << endl;
		cout << "4)Delete." << endl;
		cout << "0) BACK." << endl;

		i_account_menu = correctInputInt();

		switch (i_account_menu)
		{
		case 1:
			system("cls");
			showAccount(vec_of_account);
			break;

		case 2:
			system("cls");
			addAccount(vec_of_account);
			break;

		case 3:
			system("cls");
			showAccount(vec_of_account);
			updateAccount(vec_of_account);
			break;

		case 4:
			system("cls");
			showAccount(vec_of_account);
			deleteAccount(vec_of_account);
			break;

		case 0:
			system("cls");
			in_account_menu = false;
			break;

		default:
			break;
		}
	}
}

void workWithDataMenu(vector<Player>& vec_of_player)
{
	bool in_player_menu = true;
	int i_player_menu;

	while (in_player_menu == true)
	{
		showNow(getCurrentDate(), getCurrentTime());
		cout << endl;
		cout << "----------------MENU-----------------" << endl;
		cout << "----------------DATA-----------------" << endl;
		cout << "1)Show." << endl;
		cout << "2)Add." << endl;
		cout << "3)Redact." << endl;
		cout << "4)Delete." << endl;
		cout << "0) BACK." << endl;

		i_player_menu = correctInputInt();

		switch (i_player_menu)
		{
		case 1:
			system("cls");
			showPlayer(vec_of_player);
			break;

		case 2:
			system("cls");
			addPlayer(vec_of_player);
			break;

		case 3:
			system("cls");
			showPlayer(vec_of_player);
			updatePlayer(vec_of_player);
			break;

		case 4:
			system("cls");
			showPlayer(vec_of_player);
			deletePlayer(vec_of_player);
			break;

		case 0:
			system("cls");
			in_player_menu = false;
			break;

		default:
			break;
		}
	}
}