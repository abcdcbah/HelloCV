#ifndef CRYPTO_H
#define CRYPTO_H

#include<iostream>
#include<cstring>
using namespace std;

class Crypto
{
public:
	static string caesarEncrypt(const string &text,int key);
	static string caesarDecrypt(const string &text,int key);
	static string xorEncryptDecrypt(const string &text,const string &key);
	static string Encrypt(const string &text,const string &key,int method);
	static string Decrypt(const string &text,const string &key,int method);
};

#endif
