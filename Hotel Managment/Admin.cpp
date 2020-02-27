//Below class will describe the things admins can do
#include "Includes.h"
#include <Windows.h>

ifstream fin, fin1, fin2, fin3, fin4, fin5, fins[5];
ofstream fout[5];

class Administrator
{
public:
	Administrator();
	//Administrator and checker are linked to each other the second is confirm correctness of user's login
	bool checker(string login, string password);
	//a place where the user can choose options
	void choice(bool is_branch, string location);
	//to waork with avaibility/pricelist
	void action_with_rooms(string location, string request);
	//in case of adding new hotel branches
	void hotels_adder(string hotel)
	{
		Hotels.push_back(hotel);
	}
	//an option to manipulate the prices
	void change_price(string location);
private:
	int tries = 0, number, temp_price;
	vector<string> Hotels;
	vector<string> Types;
	vector<int> Temp;
	string login, password, login_to_check, password_to_check, temp, names;
};

Administrator::Administrator()
{	
	do
	{
		system("cls");
		cout << "Enter login and password to procede: " << endl;
		cin >> login >> password;
		if (checker(login, password))
		{
			goto point;
		}
		else
		{
			tries++;
		}
	} while (tries !=2);
	if (tries == 2)
	{
		cout << "You tried too many times, wait until next session! Press to advance..." << endl;
		_getch();
		return;
	}
point:;
	tries = 0;
	cout << '\t' << '\t' << "Welcome, master!" << endl;
	Sleep(2000);
	//Some decoration in code
	while (tries !=1)
	{
		system("cls");
		cout << "The program is launching";
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		tries++;
	}
	system("cls");
	fin3.open("Hotels.txt");  
	while (!(fin3.eof()))
	{
		fin3 >> names;
		hotels_adder(names);
	}
	fin3.close();
}

bool Administrator::checker(string login, string password)
{
	int check(0);
	fin.open("Admins' logins.txt");
	fin1.open("Admins' passwords.txt");
	fin2.open("Admins' logins.txt");
	while (!(fin2.eof()))
	{
		fin2 >> temp;
		check++;
	}
	fin2.close();
	for (int i = 0; i != check; i++)
	{
		fin >> login_to_check;
		if ((login_to_check != login))
		{
			if (i == check)
			{
				cout << checking_enters::wrong_input;
				fin.close();
				return false;
			}
			else
			{
				continue;
			}
		}
		else
		{
			number = i;
			goto point;
		}
	}
point:;
	for (int i = 0; i != check; i++)
	{
		fin1 >> password_to_check;
		if (i == number&&password==password_to_check)
		{
			fin.close();
			fin1.close();
			return true;
		}
		else if (i != number&&i != check)
		{
			continue;
		}
		else
		{
			fin.close();
			fin1.close();
			return false;
		}
	}
}

void Administrator::choice(bool is_branch, string location)
{
	int wish;
	//AlijanovSardor
	//17JUN1999
	do
	{
		cout << "You are in main menu. What would you like to do: " << endl;
		cout << "1. - Status of rooms" << endl;
		cout << "2. - Change the price" << endl;
		cout << "3. - Exile residents" << endl;
		cout << "4. - Add new admin" << endl;
		cout << "0. - Exit" << endl;
		wish = checking_enters::enter_number();
		switch (wish)
		{
		case 0:
		{
				  break;
		}
		case 1:
		{
				  action_with_rooms(location, " rooms status.txt");
				  break;
		}
		case 2:
		{
				  action_with_rooms(location, " rooms' prices.txt");
				  break;
		}
		case 3:
		{

		}
		default:
			break;
		}
		cout << checking_enters::press_to_advance;
	} while (wish != 0);
	_getch();
}

void Administrator::action_with_rooms(string location,string request)
{
point:;
	int temp(0), count(0), places;
	string temp_type;
	for (int i = 0; i < Hotels.size(); i++)
	{
		cout<<i+1<<". - " << Hotels.at(i) << endl;
	}
	cout << "0. - Exit" << endl;
	cout << "Your option: ";
	int q = checking_enters::enter_number();
	if (q == 0)
	{
		goto end;
	}              
	try
	{  
		cout<<Hotels.at(q - 1);
		system("cls");
	}
	catch (const std::out_of_range &mistake)
	{
		cout << checking_enters::wrong_input;
		goto point;
	}
	fin4.open(Hotels[q - 1] + request);
	fin5.open(location + " rooms' types.txt");
	while (!(fin5.eof()))
	{
		fin5 >> temp_type;
		Types.push_back(temp_type);
		fin4 >> places;
		cout << count + 1<<". - " << Types.at(count) << ": " << places << endl;
		count++;
	}
	fin5.close();
	fin4.close();
	//this part is to manipulation of prices
	if ((location + " rooms' prices.txt") == (location + request))
	{
		change_price(location);
	}
end:;
}

void Administrator::change_price(string location)
{
	cout << "Your choise: ";
	int q = checking_enters::enter_number();
	try
	{
		cout << Types.at(q - 1);
		system("cls");
	}
	catch (const std::out_of_range &mistake)
	{
		cout << checking_enters::wrong_input;
		return;
	}
	fins[0].open(location + " rooms' prices.txt");
	while (!(fins[0].eof()))
	{
		fins[0] >> temp_price;
		Temp.push_back(temp_price);
	}
	fins[0].close();
	system("cls");
	cout << "New price for " << Types[q - 1] << " will be: ";
	temp_price = checking_enters::enter_number();
	Temp.at(q - 1) = temp_price;
	fout[0].open(location + " rooms' prices.txt");
	for (int i = 0; i < Temp.size(); i++)
	{
		if (i == Temp.size() - 1)
		{
			fout[0] << Temp[i];
		}
		else
		{
			fout[0] << Temp[i] << endl;
		}
	}
	fout[0].close();
	Temp.clear();
}

namespace admin_possibilities
{
	int main_menu(bool is_branch, string location)   
	{	
		Administrator a;
		a.choice(is_branch, location);
		return 0;
	}
}