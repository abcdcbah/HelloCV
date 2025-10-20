#include"Menu.h"
#include<iostream>
#include<cstring>
#include<limits>
using namespace std;
int main()
{
	int choice=0;
	do
	{
		Menu::showMenu();
		cin>>choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		Menu::selectChoice(choice);

	}while(choice!=5);

	return 0;
}
