#include"Source.h"

Decimal::Decimal(string s)
{
	value = s;
	if (length > 38)
		length = 38;
	else
		length = s.length();
}

Binary::Binary(string s)
{
	value = s;
	if (length > 128)
		length = 128;
	else
		length = s.length();
}

Hexadecimal::Hexadecimal(string s)
{
	value = s;
	if (length > 32)
		length = 32;
	else
		length = s.length();
}

string Decimal::StringDiv2(string str)
{
	string temp;
	int i = 0, j = 0, k = 0;
	if (str == "1")
		return "0";
	temp.resize(str.length());
	if (str[0] - 48 < 2)
	{
		i = 1;
		j = 10;
	}
	for (; i < str.length(); i++)
	{
		temp[k++] = ((str[i] - 48 + j) / 2 + 48);
		j = ((str[i] - 48 + j) % 2) * 10;
	}
	temp.resize(k);
	return temp;
}


string Decimal::DectoBin()
{
	int isNegative = 0; // bien so am
	string result;
	string temp = value;
	// chua xu li truong hop so am
	/*if (this->value[0] == '-')
	{
		isNegative = 1;
		this->value.erase(0, 1);
	}*/

	if (temp[0] == '-')
	{
		isNegative = 1;
		temp.erase(0, 1);
	}

	while (temp != "0")
	{
		int du = (temp[temp.length() - 1] - 48) % 2;
		result.push_back((char)(48+du)); // ep kieu de dua vao chuoi
		temp = StringDiv2(temp); // chia du
	}


	// doi nguoc chuoi nhi phan se ra ket qua
	int len = result.length();
	for (int i = 0; i <= (len - 1) / 2; i++)
	{
		char temp = result[i];
		result[i] = result[len - 1 - i];
		result[len - 1 - i] = temp;
	}

	return result;
}


string Decimal::DectoHex()
{
	string result;
	string str = DectoBin();
	int du = str.length() % 4;
	switch (du)
	{
	case 1:
		str = "0000" + str;
		break;
	case 2:
		str = "00" + str;
		break;
	case 3:
		str = '0' + str;
		break;
	default:
		break;
	}
	for (int i = 0; i < str.length(); i += 4)
	{
		string temp;
		for (int j = i; j < i + 4; j++)
			temp += str[j];
		if (temp == "0000")
			result += '0';
		else if (temp == "0001")
			result += '1';
		else if (temp == "0010")
			result += '2';
		else if (temp == "0011")
			result += '3';
		else if (temp == "0100")
			result += '4';
		else if (temp == "0101")
			result += '5';
		else if (temp == "0110")
			result += '6';
		else if (temp == "0111")
			result += '7';
		else if (temp == "1000")
			result += '8';
		else if (temp == "1001")
			result += '9';
		else if (temp == "1010")
			result += 'A';
		else if (temp == "1011")
			result += 'B';
		else if (temp == "1100")
			result += 'C';
		else if (temp == "1101")
			result += 'D';
		else if (temp == "1110")
			result += 'E';
		else if (temp == "1111")
			result += 'F';
	}
	return result;
}

