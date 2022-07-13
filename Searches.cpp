#include "Searches.h"

void searchByName(vector<Player>&vec_of_player)
{
	string search_name;
	bool found_a_match = false;
	cout << " Enter Name: ";
	cin >> search_name;
	cout << endl;

	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		if (search_name == vec_of_player.at(i).name)
		{
			found_a_match = true;
			cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
				<< "|" << setw(11) << vec_of_player.at(i).birth
				<< "|" << setw(9) << vec_of_player.at(i).matches
				<< "|" << setw(7) << vec_of_player.at(i).goals
				<< "|" << setw(9) << vec_of_player.at(i).assists
				<< "|" << setw(8) << vec_of_player.at(i).yellow
				<< "|" << setw(5) << vec_of_player.at(i).red
				<< "|" << endl;
			cout << endl;

		}
	}
	if (found_a_match == false) cout << " Nothing Found " << endl << endl;
}

void searchByMatches(vector<Player>&vec_of_player)
{
	int search_matches = 0;
	bool found_a_match = false;
	cout << " Enter Number Of Matches: ";
	cin >> search_matches;
	cout << endl;

	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		if (search_matches == vec_of_player.at(i).matches)
		{
			found_a_match = true;
			cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
				<< "|" << setw(11) << vec_of_player.at(i).birth
				<< "|" << setw(9) << vec_of_player.at(i).matches
				<< "|" << setw(7) << vec_of_player.at(i).goals
				<< "|" << setw(9) << vec_of_player.at(i).assists
				<< "|" << setw(8) << vec_of_player.at(i).yellow
				<< "|" << setw(5) << vec_of_player.at(i).red
				<< "|" << endl;
			cout << endl;

		}
	}
	if (found_a_match == false) cout << " Nothing found " << endl << endl;
}

void searchByGoals(vector<Player>&vec_of_player)
{
	int search_goals = 0;
	bool found_a_match = false;
	cout << " Enter Number Of Goals: ";
	cin >> search_goals;
	cout << endl;

	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		if (search_goals == vec_of_player.at(i).goals)
		{
			found_a_match = true;
			cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
				<< "|" << setw(11) << vec_of_player.at(i).birth
				<< "|" << setw(9) << vec_of_player.at(i).matches
				<< "|" << setw(7) << vec_of_player.at(i).goals
				<< "|" << setw(9) << vec_of_player.at(i).assists
				<< "|" << setw(8) << vec_of_player.at(i).yellow
				<< "|" << setw(5) << vec_of_player.at(i).red
				<< "|" << endl;
			cout << endl;
		}
	}
	if (found_a_match == false) cout << " Nothing found " << endl << endl;
}

void searchByRed(vector<Player>&vec_of_player)
{
	int search_red = 0;
	bool found_a_match = false;
	cout << " Enter Number Of Red Cards: ";
	cin >> search_red;
	cout << endl;

	cout << "--|	 Name	 |   Birth   | Matches | Goals | Assists | Yellow | Red |" << endl;
	for (int i = 0; i < vec_of_player.size(); i++)
	{
		if (search_red == vec_of_player.at(i).red)
		{
			found_a_match = true;
			cout << setw(2) << i + 1 << ")" << setw(14) << vec_of_player.at(i).name
				<< "|" << setw(11) << vec_of_player.at(i).birth
				<< "|" << setw(9) << vec_of_player.at(i).matches
				<< "|" << setw(7) << vec_of_player.at(i).goals
				<< "|" << setw(9) << vec_of_player.at(i).assists
				<< "|" << setw(8) << vec_of_player.at(i).yellow
				<< "|" << setw(5) << vec_of_player.at(i).red
				<< "|" << endl;
			cout << endl;
		}
	}
	if (found_a_match == false) cout << " Nothing found " << endl << endl;
}