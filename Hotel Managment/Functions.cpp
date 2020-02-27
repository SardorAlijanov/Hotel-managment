//in order to shorten whole code, this part was created
#include "Includes.h"
namespace checking_enters
{
	//To make sure that all integers will be inputed correctly
	int enzter_number()
	{
		int number;
		while (!(cin >> number) || number < 0)
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "Wrong input, try again: ";
		}
		return number;
	}

	ostream &press_to_advance(ostream &sentence)
	{
		cout << "Press to advance...";
		_getch();
		system("cls");
		return sentence;
	}

	ostream &wrong_input(ostream &sentence)
	{
		cout << "Wrong input, try again, press to advance...";
		_getch();
		system("cls");
		return sentence;
	}
}