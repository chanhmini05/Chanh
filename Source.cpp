#include"Source.h"

Decimal::Decimal()
{
	value = "";
	length = 0;
}

Decimal::Decimal(string s)
{
	value = s;
	if (length > 38)
		length = 38;
	else
		length = s.length();
}

void Decimal::ChuanHoa(string &x)
{
	int i = 0;
	while (x[i] == '0' && x.length() > 1)
	{
		i++;

	}
	x.erase(0, i); // ( vi tri , so phan tu can xoa)
}

string Decimal::ToString()
{
	stringstream out;
	out << value << endl;
	return out.str();
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

	if (temp[0] == '-')
	{
		isNegative = 1;
		temp.erase(0, 1);
	}

	ChuanHoa(temp);

	while (temp != "0")
	{
		int du = (temp[temp.length() - 1] - 48) % 2;
		result.push_back((char)(48 + du)); // ep kieu de dua vao chuoi
		temp = StringDiv2(temp); // chia nguyen
	}


	// doi nguoc chuoi nhi phan se ra ket qua
	int len = result.length();
	for (int i = 0; i <= (len - 1) / 2; i++)
	{
		char temp = result[i];
		result[i] = result[len - 1 - i];
		result[len - 1 - i] = temp;
	}

	if (isNegative == 1)
	{
		//Chuyen sang bu 1
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '1')
				temp[i] = '0';
			else if (temp[i] == '0')
				temp[i] == '1';
		}
		// + 1 vao kq
	}

	return result;
}

string Decimal::DectoBin(string temp)
{
	int isNegative = 0; // bien so am
	string result;
	// chua xu li truong hop so am

	if (temp[0] == '-')
	{
		isNegative = 1;
		temp.erase(0, 1);
	}

	ChuanHoa(temp);

	while (temp != "0")
	{
		int du = (temp[temp.length() - 1] - 48) % 2;
		result.push_back((char)(48 + du)); // ep kieu de dua vao chuoi
		temp = StringDiv2(temp); // chia nguyen
	}


	// doi nguoc chuoi nhi phan se ra ket qua
	int len = result.length();
	for (int i = 0; i <= (len - 1) / 2; i++)
	{
		char temp = result[i];
		result[i] = result[len - 1 - i];
		result[len - 1 - i] = temp;
	}

	if (isNegative == 1)
	{
		//Chuyen sang bu 1
		for (int i = 0; i < temp.length(); i++)
		{
			if (temp[i] == '1')
				temp[i] = '0';
			else if (temp[i] == '0')
				temp[i] == '1';
		}
		// + 1 vao kq
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

string Decimal::DectoHex(string temp)
{
	string result;
	string str = DectoBin(temp);
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

string Decimal::getValue()
{
	return value;
}

Decimal& Decimal::operator+(Decimal& other)
{
	Decimal* str;
	if (this->length > other.length)
	{
		str = new Decimal(this->value);
	}
	else
	{
		str = new Decimal(other.value);
	}
	char mem = '0';
	if (this->length > other.length)
		other.value.insert(0, this->length - other.length, '0');
	else if (other.length > this->length)
		this->value.insert(0, other.length - this->length, '0');
	for (int i = this->length - 1; i >= 0; i--)
	{
		str->value[i] = (value[i] - '0') + (other.value[i] - '0') + (mem - '0') + '0';
		if (i != 0)
		{
			if ((str->value[i] - '0') > 9)
			{
				mem = '1';
				str->value[i] = ((str->value[i] - '0') - 10) + '0';
			}
			else
				mem = '0';
		}
	}
	if ((str->value[0] - '0') > 9)
	{
		str->value[0] = ((str->value[0] - '0') - 10) + '0';
		str->value.insert(0, 1, '1');
	}
	return *str;
}

Decimal& Decimal::operator=(Decimal& other)
{
	this->length = other.length;
	this->value = other.value;
	return *this;
}


Binary::Binary(string s)
{
	value = s;
	if (length > 128)
		length = 128;
	else
		length = s.length();
}

string Binary::ToString()
{
	stringstream out;
	out << value << endl;
	return out.str();
}

Binary::Binary()
{
	value = "";
	length = 0;
}

Binary& Binary::operator=(Binary& other)
{
	this->length = other.length;
	this->value = other.value;
	return *this;
}

void Binary::ChuanHoa()
{
	int i = 0;
	int length_old = length;
	while (value[i] == '0' && length > 1)
	{
		i++;

	}
	value.erase(0, i); // ( vi tri , so phan tu can xoa)
	length = length - i;
}

string Binary::BinToHex()
{
	string result;
	//string str = this->value;
	int du = length % 4;
	switch (du)
	{
	case 1:
		value = "0000" + value;
		break;
	case 2:
		value = "00" + value;
		break;
	case 3:
		value = '0' + value;
		break;
	default:
		break;
	}
	for (int i = 0; i < length; i += 4)
	{
		string temp;
		for (int j = i; j < i + 4; j++)
			temp += value[j];
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

string Binary::Dichtrai(int n){
	/*if (n > this->length) return "0";
	string s;
	for (int i = this->length - 1; i > n; i--) {
		s = this->value[i] + s;
	}
	for (int i = 0; i < n; i++) s = s + '0';
	return s;*/
	if (n >= this->length) return "0";
	string s;
	string temp = this->value;
	for (int i = 0; i < n; i++)
	{
		temp.erase(0, 1); // xoa bit dau tien, detele temp[0] ,sau khi xoa thi bit temp[1] la bit dau
		cout << temp.length() << endl; 
		temp += '0'; // them cac bit 0 vao sau khi xoa bit dau tuong ung voi dich 1 bit
		
	}
	return temp;
}

string Binary::Dichphai(int n) {
	/*char first = this->value[0];
	string s;
	if (n >= this->length && first == '0') return "0";
	else if (n >= this->length && first == '1') {
		for (int i = 0; i < this->length; i++) s = s + '1';
		return s;
	}
	for (int i = 0; i < this->length - 1 - n; i++) {
		s = s + this->value[i];
	}
	if (first == '1')
	for (int i = 0; i < n; i++) s = first + s;
	return s;*/

	char first = this->value[0];
	string temp;
	if (n >= this->length && first == '0') return "0";
	else if (n >= this->length && first == '1') {
		for (int i = 0; i < this->length; i++) temp = temp + '1';
		return temp;
	}

	temp = this->value;

	for (int i = 0; i < n; i++)
	{
		temp.erase(temp.length()-1, 1); // xoa bo bit cuoi cung , sau do kiem tra bit dau tien
		if (first == '1') // neu la bit 1 thi them vao bit dau so 1
			temp.insert(0, "1");
		else // neu la bit 0 cung them vao bit dau bit 0 de du so luong bit
			// bit dau tien la bit 0
			temp.insert(0, "0");
	}
	return temp;
}



Hexadecimal::Hexadecimal(string s)
{
	value = s;
	if (length > 32)
		length = 32;
	else
		length = s.length();
}

Hexadecimal::Hexadecimal()
{
	value = "";
	length = 0;
}

string Hexadecimal::ToString()
{
	stringstream out;
	out << value << endl;
	return out.str();
}

string Hexadecimal::HectoBin()
{
	string result;
	for (int i = 0; i < length; i++){
		switch (value[i]) {
		case '0':
			result += "0000";
			break;
		case '1':
			result += "0001";
			break;
		case '2':
			result += "0010";
			break;
		case '3':
			result += "0011";
			break;
		case '4':
			result += "0100";
			break;
		case '5':
			result += "0101";
			break;
		case '6':
			result += "0110";
			break;
		case '7':
			result += "0111";
			break;
		case '8':
			result += "1000";
			break;
		case '9':
			result += "1001";
			break;
		case 'A':
			result += "1010";
			break;
		case 'B':
			result += "1011";
			break;
		case 'C':
			result += "1100";
			break;
		case 'D':
			result += "1101";
			break;
		case 'E':
			result += "1110";
			break;
		case 'F':
			result += "1111";
			break;
		default:
			break;
		}
	}
	return result;
}

string Hexadecimal::multiply(string str1, string str2) {
	int *res;
	string str;
	res = new int[str1.size() + str2.size()];
	for (int i = 0; i <= str1.size() + str2.size(); i++) res[i] = 0;

	for (int i = str1.size() - 1; i >= 0; i--) {
		for (int j = str2.size() - 1; j >= 0; j--)
			res[i + 1 + j] += (str1[i] - '0') * (str2[j] - '0');
	}

	for (int i = str1.size() + str2.size(); i >= 0; i--)
	if (res[i] > 9) {
		res[i - 1] += res[i] / 10;
		res[i] %= 10;
	}
	for (int i = 0; i < str1.size() + str2.size(); i++)
		str += (res[i] + '0');
	return str;
}

string Hexadecimal::add(string str1, string str2)
{
	string str = (str1.length() > str2.length()) ? str1 : str2;
	char mem = '0';
	if (str1.length() > str2.length())
		str2.insert(0, str1.length() - str2.length(), '0');
	else
	if (str2.length()>str1.length())
		str1.insert(0, str2.length() - str1.length(), '0');
	for (int i = str1.length() - 1; i >= 0; i--)
	{
		str[i] = (str1[i] - '0') + (str2[i] - '0') + (mem - '0') + '0';
		if (i != 0)
		{
			if ((str[i] - '0') > 9)
			{
				mem = '1';
				str[i] = ((str[i] - '0') - 10) + '0';
			}
			else
				mem = '0';
		}
	}
	if ((str[0] - '0') > 9)
	{
		str[0] = ((str[0] - '0') - 10) + '0';
		str.insert(0, 1, '1');
	}
	return str;
}

//Hexadecimal& Hexadecimal::operator+(Hexadecimal* other)
//{
//	auto clone = new Hexadecimal(this->value);
//	auto plus1 = new Decimal(clone->HectoDec());
//	auto plus2 = new Decimal(other->HectoDec());
//	auto plus = new Decimal("");
////	plus = plus1 + plus2;
//	auto result = new Hexadecimal(plus->DectoHex());
//	return *result;
//}

Hexadecimal Hexadecimal::operator+(Hexadecimal x)
{
	Hexadecimal result;
	Decimal pt1(this->HectoDec());
	Decimal pt2(x.HectoDec());
	Decimal kq(pt1 + pt2);
	result = kq.DectoHex(kq.getValue());
	return result;
}

string Hexadecimal::HectoDec()
{
	string mu; /// lưu phần có mũ... ví dụ 16^2
	string result; /// lưu kết quả số thập phân sau khi chuyển đổi
	string number; /// lưu số trong chuỗi hex
	string temp; // một biến tạm để lưu kết quả , ví dụ 7*16^0 = temp, để cộng với những kết quả khác, cuối cùng cho ra dec
	string str = value;
	for (int i = str.length() - 1; i >= 0; i--)
	{
		mu = "16";
		//// ------ Xử lý con số trong chuỗi, ví dụ A=10---------
		if ((str[i] - '0') >= 0 && (str[i] - '0') <= 9)
			number = str[i];
		else
			switch (str[i])
		{
			case 'A':
				number = "10";
				break;
			case 'B':
				number = "11";
				break;
			case 'C':
				number = "12";
				break;
			case 'D':
				number = "13";
				break;
			case 'E':
				number = "14";
				break;
			case 'F':
				number = "15";
				break;
		}

		//////// trường hợp mũ 0
		if (i == str.length() - 1)
		{
			mu = "1";
			result = multiply(number, mu);
			continue;
		}
		/////////// trường hợp mũ 1
		if (i == str.length() - 2)
		{
			temp = multiply(number, mu);
			result = add(result, temp);
			continue;
		}
		////////// trường hợp còn lại
		for (int j = i; j <= str.length() - 3; j++)
		{
			mu = multiply(mu, "16");
		}
		temp = multiply(number, mu);
		result = add(result, temp);
	}
	ChuanHoa(result); // xoá số 0 dư thừa phía trước ( nếu có)
	return result;
}

Hexadecimal& Hexadecimal::operator=(Hexadecimal& other)
{
	this->length = other.length;
	this->value = other.value;
	return *this;
}

Hexadecimal& Hexadecimal::operator=(string x)
{
	this->length = x.length();
	this->value = x;
	return *this;
}


string Hexadecimal::Dichtrai(int n) {
	auto tmp = new Binary(this->HectoBin());
	string s = tmp->Dichtrai(n);
	auto tmp1 = new Binary(s);
	auto result = new Hexadecimal(tmp1->BinToHex());
	return result->value;
}

void Hexadecimal::ChuanHoa(string &x)
{
	int i = 0;
	while (x[i] == '0' && x.length() > 1)
	{
		i++;

	}
	x.erase(0, i); // ( vi tri , so phan tu can xoa)
}

