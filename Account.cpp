#include "Account.h"

void listAccount(vector<Account>& vec_of_account)
{
	bool flag = true;

	while (flag)
	{
		switch (menuAccount())
		{
		case 1: showAccount(vec_of_account);
			break;
		case 2: addAccount(vec_of_account);
			break;
		case 3: deleteAccount(vec_of_account);
			break;
		case 4: updateAccount(vec_of_account);
			break;
		case 0: flag = false;
			break;
		}
	}
	system("pause");
}

int menuAccount()
{
	int item = 0;
	do
	{
		cout << "\n |Show Accounts - 1\n |Add Account - 2\n |Delete Account - 3\n |Update Account - 4\n |EXIT - 0";
		item = correctInputInt();
		cin >> item;
	} while (item > 4 || item < 0);
	return item;
}

void addAccount(vector<Account>& vec_of_account)
{
	string password, password_again, salted_hash_password, salt;
	Account account_temp;
	int count_of_trying = 0, n = 0, i = 1;

	do
	{
		account_temp.login = loginRepeatCheck(vec_of_account);
		password = passwordCheck();
		password_again = repeatPasswordCheck(password);

		if (password == password_again)
		{
			account_temp.salt = generateSalt(SALT_SIZE);
			account_temp.salted_hash_password = sha256(sha256(password + account_temp.salt) + sha256(password));
			account_temp.role = 0;
			account_temp.access = 0;
			vec_of_account.push_back(account_temp);
			i++;
			cout << "Registration is finished!" << endl;
		}

	} while (i < n + 1);
}

void showAccount(vector<Account>& vec_of_account)
{
	cout << "--|  User name | Role | Access |" << endl;
	for (int i = 0; i < vec_of_account.size(); i++)
	{
		cout << setw(2) << i + 1 << ")" << setw(12) << vec_of_account.at(i).login
			<< "|" << setw(6) << vec_of_account.at(i).role
			<< "|" << setw(8) << vec_of_account.at(i).access << "|" << endl;
	}
	cout << "________________________________" << endl << endl;
}

void deleteAccount(vector<Account>& vec_of_account)
{
	int index_of_deleted_item = 0;
	bool delete_confirm = true;

	cout << "Which Account do you want to delete?" << endl;
	index_of_deleted_item = correctInputInt();
	index_of_deleted_item--;

	if (index_of_deleted_item >= 0 && index_of_deleted_item < vec_of_account.size())
	{
		delete_confirm = deleteÑonfirmation();
		if (delete_confirm == true)
		{
			if (index_of_deleted_item == 0)
				cout << "You can't delete Main Administrator" << endl << endl;
			else
			{
				for (int i = index_of_deleted_item; i < vec_of_account.size() - 1; i++)
				{
					vec_of_account.at(i) = vec_of_account.at(i + 1);
				}
				vec_of_account.pop_back();
				writeFileAccount(vec_of_account);
				system("cls");
				cout << "Deleted succesfully!" << endl;
			}
		}
		else cout << "Cancelled!" << endl;
	}
}

void updateAccount(vector<Account>& vec_of_account)
{
	int index_for_update = 0;

	cout << "Which Account do you want to update?" << endl;
	index_for_update = correctInputInt();
	index_for_update--;

	if (index_for_update >= 0 && index_for_update < vec_of_account.size())
	{
		if (index_for_update == 0)
			cout << "You can't update Main Administrator" << endl << endl;
		else
		{
			cout << "----------ACCOUNT UPDATE----------" << endl;
			cout << "New Login: ";
			cin >> vec_of_account.at(index_for_update).login;
			cout << "New Role (0 - user, 1 - admin): ";
			cin >> vec_of_account.at(index_for_update).role;
			cout << "New Access (0 - no, 1 - yes): ";
			cin >> vec_of_account.at(index_for_update).access;
			cout << endl;
		}
	}
	else
		cout << "Cancelled!" << endl << endl;
}

void writeFileAccount(vector<Account>& vec_of_account)
{
	ofstream fout(DATA_FILE_ACCOUNTS, ios::out);
	for (int i = 0; i < vec_of_account.size(); i++)
	{
		fout << vec_of_account.at(i).login << " " << vec_of_account.at(i).salt << " " << vec_of_account.at(i).salted_hash_password << " " << vec_of_account.at(i).role << " " << vec_of_account.at(i).access;

		if (i < vec_of_account.size() - 1)
			fout << endl;
	}
	fout.close();
}

void readFileAccount(vector<Account>& vec_of_account)
{
	ifstream fin(DATA_FILE_ACCOUNTS, ios::in);
	if (!fin.is_open())
	{
		cout << "The account file doesn't exist!" << endl;
		Account temp_account;
		temp_account.login = ADMIN_LOGIN;
		temp_account.salt = generateSalt(SALT_SIZE);
		temp_account.salted_hash_password = sha256(sha256(ADMIN_PASSWORD + temp_account.salt) + sha256(ADMIN_PASSWORD));
		temp_account.role = ADMIN_ROLE;
		temp_account.access = ADMIN_ACCESS;
		vec_of_account.push_back(temp_account);
		writeFileAccount(vec_of_account);
	}
	else
	{
		if (fin.peek() != EOF)
		{
			Account account_temp;
			while (!fin.eof())
			{
				fin >> account_temp.login >> account_temp.salt >> account_temp.salted_hash_password >> account_temp.role >> account_temp.access;
				vec_of_account.push_back(account_temp);
			}
		}
		else
			cout << "File is empty!" << endl;
	}
	fin.close();
}

int getCountOfStructuresAccount(string file_path)
{
	ifstream file(file_path, ios::in);
	int number_of_strings = 0;
	if (file.is_open())
	{
		while (file.ignore((numeric_limits<streamsize>::max)(), '\n'))
			number_of_strings++;
	}
	file.close();
	return number_of_strings;
}

string loginRepeatCheck(vector<Account>& vec_of_account)
{
	string enter_login;
	bool correct_login = true;
	do
	{
		correct_login = true;
		cout << "Enter Login: ";
		cin >> enter_login;
		for (int i = 0; i < vec_of_account.size(); i++, correct_login == true)
		{
			if (vec_of_account[i].login == enter_login)
			{
				cout << "Such name is already exist. Please try again " << endl;
				correct_login = false;
			}
		}

	} while (correct_login == false);

	return enter_login;
}

string passwordStar()
{
	string password;
	int p;

	while (true)
	{
		p = _getch();

		if (p == 13)
		{
			break;
		}
		else
			if (p == 8)
			{
				cout << (char)8 << ' ' << (char)8;
				if (!password.empty())
					password.erase(password.length() - 1); // ôóíêöèÿ ïîçâîëÿåò óäàëèòü îäèí ñèìâîë
			}

			else
			{
				cout << "*";
				password += (char)p;
			}
	}
	return password;
}

string passwordCheck()
{
	string enter_password;
	do
	{
		cout << endl;	
		cout << "Password must be from 6 to 16 symbols " << endl;
		cout << "Enter Password: ";
		enter_password = passwordStar();
	} while (enter_password.size() < 6 || enter_password.size() > 16);
	return enter_password;
}

string repeatPasswordCheck(string password)
{
	string enter_password_again;
	int count_of_trying = 0;

	do
	{
		cout << endl;
		cout << "Repeat  Password: ";
		enter_password_again = passwordStar();

		if (enter_password_again != password)
		{
			cout << "Wrong password. Please try again...  " << endl;
			cout << "There are still attempts left:" << 2 - count_of_trying << endl;
			count_of_trying++;
		}
	} while (count_of_trying <= 2 && enter_password_again != password);

	if (count_of_trying == 3)	cout << "Too much attemptions" << endl;
	cout << endl;
	return enter_password_again;
}