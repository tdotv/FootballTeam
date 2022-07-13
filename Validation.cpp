#include "Validation.h"

int correctInputInt()
{
	int a;
	while (true)
	{
		cin >> a;
		if (a >= 0)
		{
			if (cin.get() == '\n') {
				break;
			}
			else
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Error, please write INT numbers! Please try again!" << endl;
			}
		}
		else
			cout << "You can't enter negative numbers!" << endl;
	}
	return a;
}

string checkDate()
{
	int a, day, month, year;
	string str1, str2, str3, date;
	do
	{
		getline(cin, date);
		str1 = date;
		a = str1.find('.', 0);
		str2 = str1.substr(0, a);
		day = stoi(str2);
		str1.erase(0, a + 1);
		a = str1.find('.', 0);
		str3 = str1.substr(0, a);
		month = stoi(str3);
		str1.erase(0, a + 1);
		year = stoi(str1);
		//scanf_s("%d/%d/%d", &day, &month, &year);
	} while (!isCorrectDate(day, month, year));
	return date;
}

bool isCorrectDate(int day, int month, int year)
{
	time_t now = time(0);
	struct tm ltm;
	localtime_s(&ltm, &now);

	if (day > 31 || day < 01)
	{
		cout << "Wrong day!" << endl;
		return false;
	}
	else if (month > 12 || month < 01)
	{
		cout << "Wrong month!" << endl;
		return false;
	}
	else if (year > 1900 + ltm.tm_year || year < (1900 + ltm.tm_year) - 120)
	{
		cout << "Wrong year!" << endl;
		return false;
	}
	else if (year == 1900 + ltm.tm_year && month - 1 > ltm.tm_mon)//ÿíâàğü - 0
	{
		cout << "This month hasn't come!" << endl;
		return false;
	}
	else if (year == 1900 + ltm.tm_year && month - 1 == ltm.tm_mon && day > ltm.tm_mday)
	{
		cout << "This day hasn't come!" << endl;
		return false;
	}
	else
		return true;
}

string enterText()
{
	string buffer;
	char buff;
	int count = 0;

	while (true) {
		buff = _getch();
		if (buff == 13) {
			break;
		}
		else if (buff == 8) {
			if (count != 0) {
				cout << (char)8 << ' ' << char(8);
				buffer.erase(buffer.length() - 1);
				count--;
			}
		}
		else if (buff != 32 && !(buff >= 48 && buff <= 57)) {
			cout << buff;
			buffer += buff;
			count++;
		}
	}
	cout << endl;
	return buffer;
}

string checkForEnters() {
	string buffer;
	char buff;
	int count = 0;

	while (true) {
		buff = _getch();
		if (buff == 13) {
			break;
		}
		else if (buff == 8) {
			if (count != 0) {
				cout << (char)8 << ' ' << char(8);
				buffer.erase(buffer.length() - 1);
				count--;
			}
		}
		else if (buff != 32) {
			cout << buff;
			buffer += buff;
			count++;
		}
	}
	cout << endl;
	return buffer;
}

string generateSalt(int salt_size)
{
	string symbols = getSymbolsForSalt();
	/*cout << symbols << endl;*/

	srand(time(NULL));

	string salt;
	salt.reserve(salt_size);

	for (int i = 0; i < salt_size; i++)
	{
		salt.push_back(symbols[rand() % SYMBOLS_SIZE]);
	}

	return salt;
}

string getSymbolsForSalt()
{
	string symbols;
	symbols.reserve(SYMBOLS_SIZE);

	char little_letter = 'a';
	char big_letter = 'A';
	char number = '0';
	int i = 0;
	for (int k = 0; k < 26; k++)
	{
		symbols.push_back(little_letter++);
		symbols.push_back(big_letter++);
		if (k < 10) symbols.push_back(number++);
	}

	return symbols;
}

bool deleteÑonfirmation()
{
	bool confirm = true;
	int i_conf = -1;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	do
	{
		cout << "	Do you really want to DELETE?" << endl;

		SetConsoleTextAttribute(hConsole, 12);
		cout << "1 - Accept." << endl;
		SetConsoleTextAttribute(hConsole, 15); //set back to black background and white text

		cout << "0 - Cancel." << endl;

		i_conf = correctInputInt();
		switch (i_conf)
		{
		case 1:
			return confirm;
		case 0:
			confirm = false;
			return confirm;
		default:
			break;
		}
	} while (i_conf != 1 && i_conf != 0);
}
