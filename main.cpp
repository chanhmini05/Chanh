// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Source.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Decimal a("153");
	string convert = a.DectoBin();
	cout << convert << endl;
	string test = a.DectoHex();
	cout << test << endl;
	system("pause");
	return 0;
}

