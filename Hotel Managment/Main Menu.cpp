#include "Includes.h"
class Main_Menu
{
public:
	Main_Menu();
private:
	int wish;
};

Main_Menu::Main_Menu()
{
	cout << '\t' << '\t' << '\t' << '\t' << "            Welcome" << endl << endl;
	cout << '\t' << "This is main menu of head hotel of a network of hotels throughout the world" << endl << endl;
	cout << '\t' << "Press to advance..." << endl;
	_getch();
point:;
	system("cls");
	cout << '\t' << '\t' << "Please, identify yourself" << endl;
	cout << '\t' << "1. - Admin" << endl << '\t' << "2. - Guest" << endl << '\t' << "0. - Exit" << endl;
	cout << "Your choice: ";
	switch (checking_enters::enter_number())
	{
	case 0:
	{
			  break;
	}
	case 1:
	{
			  admin_possibilities::main_menu(false,"London");
			  goto point;
			  break;
	}
	case 2:
	{

			  goto point;
			  break;
	}
	default:
		cout << "No such option, try again! Press any key to advance...";
		_getch();
		goto point;
	}
}

int main()
{
	Main_Menu mm;
	cout << "Bye, then!" << endl;
	system("PAUSE");
	return 0;
}