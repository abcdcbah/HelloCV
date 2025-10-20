#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include<iostream>
#include<cstring>
using namespace std;

class FileHandler
{
public:
	static string readFile(const string &path);
    static bool writeFile(const string &path,const string &content);
};

#endif