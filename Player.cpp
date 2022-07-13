#include "Player.h"

void listPlayer(vector<Player>& vec_of_player)
{
	bool flag = true;

	while (flag)
	{
		switch (menuPlayer())
		{
		case 1: showPlayer(vec_of_player);
			break;
		case 2: addPlayer(vec_of_player);
			break;
		case 3: deletePlayer(vec_of_player);
			break;
		case 4: updatePlayer(vec_of_player);
			break;
		case 0: flag = false;
			break;
		}
	}
	system("pause");
}

int menuPlayer()
{
	int item = 0;
	do
	{
		cout << "\n |Show Players - 1\n |Add Player - 2\n |Delete Player - 3\n |Update Player - 4\n |EXIT - 0";
		item = correctInputInt();
	} while (item > 4 || item < 0);
	return item;
}

void addPlayer(vector<Player>& vec_of_player)
{
	Player player_temp;
	int n = 0, i = 1;

	do
	{
		printf("How many people do you want to add?: ");
		n = correctInputInt();
	} while (n < 1);
	do
	{
		cout << "Name: ";
		player_temp.name = enterText();
		cout << "Date of birth: ";
		player_temp.birth = checkDate();
		cout << "Matches played: ";
		player_temp.matches = correctInputInt();
		cout << "Goals: ";
		player_temp.goals = correctInputInt();
		cout << "Assists: ";
		player_temp.assists = correctInputInt();
		cout << "Yellow cards: ";
		player_temp.yellow = correctInputInt();
		cout << "Red cards: ";
		player_temp.red = correctInputInt();
		cout << "\n";
		vec_of_player.push_back(player_temp);
		i++;
	} while (i < n + 1);
}

void showPlayer(vector<Player>& vec_of_player)
{
	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
			<< "|" << setw(11) << vec_of_player.at(i).birth
			<< "|" << setw(9) << vec_of_player.at(i).matches
			<< "|" << setw(7) << vec_of_player.at(i).goals
			<< "|" << setw(9) << vec_of_player.at(i).assists
			<< "|" << setw(8) << vec_of_player.at(i).yellow
			<< "|" << setw(5) << vec_of_player.at(i).red
			<< "|" << endl;
	}
	cout << endl;
}

void deletePlayer(vector<Player>& vec_of_player)
{
	int index_of_deleted_item = 0;
	bool delete_confirm = true;

	cout << "Which Player do you want to delete?" << endl;
	index_of_deleted_item = correctInputInt();
	index_of_deleted_item--;

	if (index_of_deleted_item >= 0 && index_of_deleted_item < vec_of_player.size())
	{
		delete_confirm = deleteÑonfirmation();
		if (delete_confirm == true)
		{
			for (int i = index_of_deleted_item; i < vec_of_player.size() - 1; i++)
			{
				vec_of_player.at(i) = vec_of_player.at(i + 1);
			}
			vec_of_player.pop_back();
			writeFilePlayer(vec_of_player);
			system("cls");
			cout << "Deleted succesfully!" << endl;
		}
		else cout << "Cancelled!" << endl;
	}
	else
		cout << "Cancelled!" << endl << endl;
}

void updatePlayer(vector<Player>& vec_of_player)
{
	int index_for_update = 0;

	cout << "Which Player do you want to update?" << endl;
	index_for_update = correctInputInt();
	index_for_update--;

	if (index_for_update >= 0 && index_for_update < vec_of_player.size())
	{
		cout << "Name: ";
		vec_of_player.at(index_for_update).name = enterText();
		cout << "Date of birth: ";
		vec_of_player.at(index_for_update).birth = checkDate();
		cout << "Matches played: ";
		vec_of_player.at(index_for_update).matches = correctInputInt();
		cout << "Goals: ";
		vec_of_player.at(index_for_update).goals = correctInputInt();
		cout << "Assists: ";
		vec_of_player.at(index_for_update).assists = correctInputInt();
		cout << "Yellow cards: ";
		vec_of_player.at(index_for_update).yellow = correctInputInt();
		cout << "Red cards: ";
		vec_of_player.at(index_for_update).red = correctInputInt();
	}
	else
		cout << "Cancelled!" << endl << endl;
}

void writeFilePlayer(vector<Player>& vec_of_player)
{
	ofstream fout(DATA_FILE_PLAYERS, ios::out);
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		fout << vec_of_player.at(i).name << " " << vec_of_player.at(i).birth << " " << vec_of_player.at(i).matches << " " << vec_of_player.at(i).goals << " " << vec_of_player.at(i).assists << " " << vec_of_player.at(i).yellow << " " << vec_of_player.at(i).red;
		if (i < vec_of_player.size() - 1)
			fout << endl;
	}
	fout.close();
}

void readFilePlayer(vector<Player>& vec_of_player)
{
	ifstream fin(DATA_FILE_PLAYERS, ios::in);
	if (!fin.is_open())
		cout << "The data file doesn't exist!" << endl;
	else
	{
		if (fin.peek() != EOF)
		{
			Player player_temp;
			while (!fin.eof())
			{
				fin >> player_temp.name >> player_temp.birth >> player_temp.matches >> player_temp.goals >> player_temp.assists >> player_temp.yellow >> player_temp.red;
				vec_of_player.push_back(player_temp);
			}
		}
		else
			cout << "File is empty!" << endl;
	}
	fin.close();
}

int getCountOfStructuresPlayer(string file_path)
{
	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open())
	{
		while (file.ignore((numeric_limits<streamsize>::max)(), '\n'))
		{
			number_of_strings++;
		}
	}
	file.close();
	return number_of_strings;
}