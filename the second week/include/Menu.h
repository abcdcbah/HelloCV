#ifndef MENU_H
#define MENU_H

#include<cstring>

class Menu
{
public:
	static void showMenu();
	static void selectChoice(int choice);
	static void textEncryptMenu();
	static void textDecryptMenu();
	static void fileEncryptMenu();
	static void fileDecryptMenu();
	static int selectMethod();
};

#endif
