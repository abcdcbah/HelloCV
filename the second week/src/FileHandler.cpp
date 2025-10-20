#include"FileHandler.h"
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

string FileHandler::readFile(const string &path)
{
    ifstream file(path);
    string content((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());
    file.close();
    return content;
}

bool FileHandler::writeFile(const string &path,const string &content)
{
    ofstream file(path);
    file<<content;
    file.close();
    return true;
}