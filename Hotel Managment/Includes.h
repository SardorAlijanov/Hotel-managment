#pragma once
#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

namespace checking_enters
{
	int enter_number();
	ostream &press_to_advance(ostream &sentence);
	ostream &wrong_input(ostream &sentence);
}

namespace admin_possibilities
{
	int main_menu(bool is_branch, string location);
}