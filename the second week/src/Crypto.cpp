#include"Crypto.h"
#include<iostream>
#include<cstring>
using namespace std;

string Crypto::caesarEncrypt(const string &text,int key)
{
	string result=text;
	key=key%26;

	for (char& c : result)
	{
		if(isalpha(c))
		{
		    char base=islower(c)?'a':'A';
			c=base+(c-base+key+26)%26;
		}
	}
	return result;
}

string Crypto::caesarDecrypt(const string &text,int key)
{
	return Crypto::caesarEncrypt(text,-key);
}

string Crypto::xorEncryptDecrypt(const string &text,const string &key)
{
	string result=text;
	int len=text.size();
	int T=key.size();
	for(int i=0;i<len;i++)
		result[i]=text[i]^key[i%T];
	return result;
}

string Crypto::Encrypt(const string &text,const string &key,int method)
{
	switch(method)
	{
		case 1:
			return caesarEncrypt(text,stoi(key));
		case 2:
			return xorEncryptDecrypt(text,key);
		default:
			cout<<"错误！"<<endl;
	}
}

string Crypto::Decrypt(const string &text,const string &key,int method)
{
	switch(method)
	{
		case 1:
			return caesarDecrypt(text,stoi(key));
		case 2:
			return xorEncryptDecrypt(text,key);
		default:
			cout<<"错误！"<<endl;
	}
}

