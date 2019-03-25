#include<iostream>
#include<string>
#include<sstream>

using namespace std;

// Chuyen doi thap phan sang nhi phan va thap phan sang thap luc phan

class Decimal
{
private:
	string value;
	int length;
public:
	Decimal(string s);
	string DectoBin();
	string StringDiv2(string str);
	string DectoHex();
};

class Binary
{
private:
	string value;
	int length;
public:
	Binary(string s);
};

class Hexadecimal
{
private:
	string value;
	int length;
public:
	Hexadecimal(string s);
};