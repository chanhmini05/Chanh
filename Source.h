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
	string getValue();
	string DectoBin();
	string DectoBin(string);
	string StringDiv2(string str);
	string DectoHex();
	string DectoHex(string x);
	string add(string, string);
	void ChuanHoa(string&);
	Decimal& operator+(Decimal& other);
	Decimal& operator=(Decimal& target);
	string ToString();
public:
	Decimal(string s);
	Decimal();
};

class Binary
{
private:
	string value;
	int length;
public:
	Binary();
	Binary(string s);
	void ChuanHoa();
	string ToString();
	string BinToHex(string);
	string BinToHex();
	Binary& operator=(Binary& target);
	string Dichtrai(int n);
	string Dichphai(int n);
};

class Hexadecimal
{
private:
	string value;
	int length;
public:
	Hexadecimal();
	Hexadecimal(string s);
	string HexToBin();
	string HexToDec();
	string Dichtrai(int n);
//	Hexadecimal& operator+(Hexadecimal* other);
	Hexadecimal operator+(Hexadecimal);
	Hexadecimal operator-(Hexadecimal);
	Hexadecimal operator*(Hexadecimal);
	Hexadecimal operator/(Hexadecimal);
	string multiply(string, string);
	string add(string, string);
	void ChuanHoa(string&);
	Hexadecimal& operator=(Hexadecimal& target);
	Hexadecimal& operator=(string x);
	string ToString();
};