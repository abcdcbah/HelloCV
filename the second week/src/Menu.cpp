#include "Crypto.h"
#include "FileHandler.h"
#include "Menu.h"
#include<iostream>
#include<limits>
using namespace std;

void Menu::showMenu()
{
	cout<<"文本加密/解密"<<endl;
	cout<<"1.文本加密"<<endl;
	cout<<"2.文本解密"<<endl;
	cout<<"3.文件加密"<<endl;
	cout<<"4.文本解密"<<endl;
	cout<<"5.退出"<<endl;
	cout<<"请输入：";
}

void Menu::selectChoice(int choice)
{
	switch(choice)
	{
		case 1:
			textEncryptMenu();
			break;
		case 2:
			textDecryptMenu();
			break;
		case 3:
			fileEncryptMenu();
			break;
		case 4:
			fileDecryptMenu();
			break;
		case 5:
			cout<<"慢走";
			break;
		default:
			cout<<"错误！请重新输入！"<<endl;
	}
}


void Menu::textEncryptMenu()
{
	string text,key;
	int method=selectMethod();

	cout<<"请输入要加密的文本：";
	getline(cin,text);
	cout<<"请输入密钥：";
	getline(cin,key);
	cout<<"加密结果："<<Crypto::Encrypt(text,key,method)<<endl;
}

void Menu::textDecryptMenu()
{
	string text,key;
	int method=selectMethod();
	cout<<"请输入要加密的文本：";
	getline(cin,text);
	cout<<"请输入密钥：";
	getline(cin,key);
	cout<<"加密结果："<<Crypto::Decrypt(text,key,method)<<endl;
}

void Menu::fileEncryptMenu()
{
	string inpath,key,outpath,text,ans;
	int method=selectMethod();
	cout<<"请输入要加密的文件：";
	getline(cin,inpath);
	
	cout<<"请输入密钥：";
	getline(cin,key);
	
	cout<<"请输入加密后结果保存到：";
	getline(cin,outpath);
	text=FileHandler::readFile(inpath);
	ans=Crypto::Encrypt(text,key,method);
	if(FileHandler::writeFile(outpath,ans))cout<<"加密结果已保存到："<<outpath<<endl;
	else cout<<"失败！";
}

void Menu::fileDecryptMenu()
{
	string inpath,key,outpath,text,ans;
	int method=selectMethod();
	cout<<"请输入要解密的文件：";
	getline(cin,inpath);
	
	cout<<"请输入密钥：";
	getline(cin,key);
	
	cout<<"请输入解密后结果保存到：";
	getline(cin,outpath);
	text=FileHandler::readFile(inpath);
	ans=Crypto::Decrypt(text,key,method);
	if(FileHandler::writeFile(outpath,ans))cout<<"解密结果已保存到："<<outpath<<endl;
	else cout<<"失败！";
}

int Menu::selectMethod()
{
	int method;
	cout<<"请选择加密/解密方式"<<endl;
	cout<<"1.凯撒密码"<<endl;
	cout<<"2.XOR加密"<<endl;
	cout<<"请输入：";
	cin>>method;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
	return method;
}