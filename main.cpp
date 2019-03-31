// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include"Source.h"
#include<math.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	Decimal a("8793278316383117319");
	string convert = a.DectoBin();
	if (convert == "111101000001000000000000000101000111011001010010010000000000111")
	{
		cout << "Yes"<<endl;
	}
	else
	{
		cout << "\nNo" << endl;
	}
	cout << convert << endl;
	
	string test = a.DectoHex();
	cout << test << endl;
	
	cout<< a.StringDiv2("8");*/

	/*Binary a("000010100010");

	a.ChuanHoa();

	cout << a.ToString();*/

	Hexadecimal a("4A6");
	Hexadecimal b("1B3");
	//
	Hexadecimal result = a + b;

	cout << result.ToString();

	Binary test("11000110");

	/*string t=test.Dichtrai(2);
	string t1 = test.Dichphai(1);*/

	string t = a.HexToBin();
	
	string t1 = a.Dichtrai(1);

	cout << t << endl;

	cout << t1 << endl;

	system("pause");
	return 0;
}

