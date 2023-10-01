#include "var.h"
#include <iostream>
#include <string>
using namespace std;


var::var()
{
	intgr = 0;
	str = ' ';
	dbl = 0;
	mode = 0;
}
var::var(int a)
{
	str = ' ';
	intgr = a;
	dbl = 0;
	mode = 1;
}
var::var(string a)
{
	intgr = 0;
	dbl = 0;
	str = a;
	mode = 2;
}
var::var(double a)
{
	str = ' ';
	intgr = 0;
	dbl = a;
	mode = 3;
}
void var::Show()
{
	if (mode == 1)
		cout << intgr;
	else if (mode == 2)
		cout << str;
	else if (mode == 3)
		cout << dbl;
	else
		return;

}
var var::operator+(var a)
{
	var temp(*this);
	if (mode == 1 && a.mode == 1)
		return temp.intgr + a.intgr;
	if (mode==1 && a.mode == 2)
		return temp.intgr += stoi(a.str);
	if(mode==1 && a.mode==3)
		return temp.intgr + a.dbl;
	if (mode == 2 && a.mode != 2)
		return temp.str += to_string(a.intgr);
	if (mode == 2 && a.mode == 2)
		return temp.str += a.str;
	if (mode == 2 && a.mode==3)
		return temp.str += to_string(a.dbl);
	if (mode == 3 && a.mode == 1)
		return temp.dbl += a.intgr;
	if (mode == 3 && a.mode == 2)
		return temp.dbl += stoi(a.str);
	if (mode == 3 && a.mode == 3)
		return temp.dbl += a.dbl;
}
var var::operator-(var a)
{
	var temp(*this);
	if (mode == 2)
		return temp;
	if (mode == 1 && a.mode == 1)
		return temp.intgr - a.intgr;
	if (mode == 1 && a.mode == 2)
		return temp.intgr -= stoi(a.str);
	if (mode == 1 && a.mode == 3)
		return temp.intgr - a.dbl;
	if (mode == 3 && a.mode == 1)
		return temp.dbl -= a.intgr;
	if (mode == 3 && a.mode == 2)
		return temp.dbl -= stoi(a.str);
	if (mode == 3 && a.mode == 3)
		return temp.dbl -= a.dbl;
}
var var::operator*(var a)
{
	var temp(*this);
	if (mode == 1 && a.mode == 1)
		return temp.intgr * a.intgr;
	if (mode == 1 && a.mode == 2)
		return temp.intgr *= stoi(a.str);
	if (mode == 1 && a.mode == 3)
		return temp.intgr * a.dbl;
	if (mode == 2 && a.mode!=2)
		return temp;
	if (mode == 2 && a.mode == 2)
	{
		string t;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (a.str.find(c) != string::npos)
				t += c;
		}
		temp.str = t;
		return temp;
	}
	if (mode == 2 && a.mode == 3)
		return temp;
	if (mode == 3 && a.mode == 1)
		return temp.dbl *= a.intgr;
	if (mode == 3 && a.mode == 2)
		return temp.dbl *= stoi(a.str);
	if (mode == 3 && a.mode == 3)
		return temp.dbl *= a.dbl;
}
var var::operator/(var a)
{
	var temp(*this);
	if (mode == 1 && a.mode == 1)
		return temp.intgr / a.intgr;
	if (mode == 1 && a.mode == 2)
		return temp.intgr /= stoi(a.str);
	if (mode == 1 && a.mode == 3)
		return temp.intgr / a.dbl;
	if (mode == 2 && a.mode!=2)
		return temp;
	if (mode == 2 && a.mode == 2)
	{
		string t;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (a.str.find(c) == string::npos)
				t += c;
		}
		temp.str = t;
		return temp;
	}
	if (mode == 2 && a.mode == 3)
		return temp;
	if (mode == 3 && a.mode == 1)
		return temp.dbl /= a.intgr;
	if (mode == 3 && a.mode == 2)
		return temp.dbl /= stoi(a.str);
	if (mode == 3 && a.mode == 3)
		return temp.dbl /= a.dbl;
}
var& var::operator+=(var a)
{
	if (mode == 1 && a.mode == 1)
	{
		intgr + a.intgr;
		return *this;
	}
	if (mode == 1 && a.mode == 2)
	{
		intgr += stoi(a.str);
		return *this;
	}
	if (mode == 1 && a.mode == 3)
	{
		intgr + a.dbl;
		return *this;
	}

	if (mode == 2 && a.mode != 2)
	{
		str += to_string(a.intgr);
		return *this;
	}
	if (mode == 2 && a.mode == 2)
	{
		str += a.str;
		return *this;
	}
	if (mode == 2 && a.mode == 3)
	{
		str += to_string(a.dbl);
		return *this;
	}
	if (mode == 3 && a.mode == 1)
	{
		dbl += a.intgr;
		return *this;
	}
	if (mode == 3 && a.mode == 2)
	{
		dbl += stoi(a.str);
		return *this;
	}
	if (mode == 3 && a.mode == 3)
	{
        dbl += a.dbl;
		return *this;
	}
}
var& var::operator-=(var a)
{
	if (mode == 2)
		return *this;
	if (mode == 1 && a.mode == 1)
	{
		intgr - a.intgr;
		return *this;
	}
	if (mode == 1 && a.mode == 2)
	{
		intgr -= stoi(a.str);
		return *this;
	}
	if (mode == 1 && a.mode == 3)
	{
		intgr - a.dbl;
		return *this;
	}
	if (mode == 3 && a.mode == 1)
	{
		dbl -= a.intgr;
		return *this;
	}
	if (mode == 3 && a.mode == 2)
	{
		dbl -= stoi(a.str);
		return *this;
	}
	if (mode == 3 && a.mode == 3)
	{
		dbl -= a.dbl;
		return *this;
	}
}
var& var::operator*=(var a)
{
	if (mode == 1 && a.mode == 1)
	{
		intgr* a.intgr;
		return *this;
	}
	if (mode == 1 && a.mode == 2)
	{
		intgr *= stoi(a.str);
		return *this;
	}
	if (mode == 1 && a.mode == 3)
	{
		intgr* a.dbl;
		return *this;
	}
	if (mode == 2 && a.mode != 2)
		return *this;
	if (mode == 2 && a.mode == 2)
	{
		string t;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (a.str.find(c) != string::npos)
				t += c;
		}
		str = t;
		return *this;
	}
	if (mode == 2 && a.mode == 3)
		return *this;
	if (mode == 3 && a.mode == 1)
	{
		dbl *= a.intgr;
		return *this;
	}
	if (mode == 3 && a.mode == 2)
	{
		dbl *= stoi(a.str);
		return *this;
	}
	if (mode == 3 && a.mode == 3)
	{
		dbl *= a.dbl;
		return *this;
	}
}
var& var::operator/=(var a)
{
	if (mode == 1 && a.mode == 1)
	{
		intgr / a.intgr;
		return *this;
	}
	if (mode == 1 && a.mode == 2)
	{
		intgr /= stoi(a.str);
		return *this;
	}
	if (mode == 1 && a.mode == 3)
	{
		intgr / a.dbl;
		return *this;
	}
	if (mode == 2 && a.mode != 2)
		return *this;
	if (mode == 2 && a.mode == 2)
	{
		string t;
		for (size_t i = 0; i < str.length(); i++)
		{
			char c = str[i];
			if (a.str.find(c) == string::npos)
				t += c;
		}
		str = t;
		return *this;
	}
	if (mode == 2 && a.mode == 3)
		return *this;
	if (mode == 3 && a.mode == 1)
	{
		dbl /= a.intgr;
		return *this;
	}
	if (mode == 3 && a.mode == 2)
	{
		dbl /= stoi(a.str);
		return *this;
	}
	if (mode == 3 && a.mode == 3)
	{
		dbl /= a.dbl;
		return *this;
	}
}
bool var::operator>(var a)
{ 
	if (mode == 1 && a.mode == 1)
		return (intgr > a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr > stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr > a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) > a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str > a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) > a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl > a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl > stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl > a.dbl);
}
bool var::operator<(var a)
{
	if (mode == 1 && a.mode == 1)
		return (intgr < a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr < stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr < a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) < a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str < a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) < a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl < a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl < stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl < a.dbl);
}
bool var::operator==(var a)
{
	if (mode == 1 && a.mode == 1)
		return (intgr == a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr == stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr == a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) == a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str == a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) == a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl == a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl == stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl == a.dbl);
}
bool var::operator>=(var a)
{
	if (mode == 1 && a.mode == 1)
		return (intgr >= a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr >= stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr >= a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) >= a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str >= a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) >= a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl >= a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl >= stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl >= a.dbl);
}
bool var::operator<=(var a)
{
	if (mode == 1 && a.mode == 1)
		return (intgr <= a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr <= stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr <= a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) <= a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str <= a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) <= a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl <= a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl <= stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl <= a.dbl);
}
bool var::operator!=(var a)
{
	if (mode == 1 && a.mode == 1)
		return (intgr != a.intgr);
	if (mode == 1 && a.mode == 2)
		return (intgr != stoi(a.str));
	if (mode == 1 && a.mode == 3)
		return (intgr != a.dbl);
	if (mode == 2 && a.mode == 1)
		return (stoi(str) != a.intgr);
	if (mode == 2 && a.mode == 2)
		return(str != a.str);
	if (mode == 2 && a.mode == 3)
		return (stoi(str) != a.dbl);
	if (mode == 3 && a.mode == 1)
		return (dbl != a.intgr);
	if (mode == 3 && a.mode == 2)
		return (dbl != stoi(a.str));
	if (mode == 3 && a.mode == 3)
		return (dbl != a.dbl);
}


int operator+(int a, var b)
{
	int temp=a;
	if (b.mode == 1)
		return temp += b.intgr;
	if (b.mode == 2)
		return temp += stoi(b.str);
	if (b.mode == 3)
		return temp += b.dbl;
}

int operator-(int a, var b)
{
	int temp = a;
	if (b.mode == 1)
		return temp -= b.intgr;
	if (b.mode == 2)
		return temp -= stoi(b.str);
	if (b.mode == 3)
		return temp -= b.dbl;
}

int operator*(int a, var b)
{
	int temp = a;
	if (b.mode == 1)
		return temp *= b.intgr;
	if (b.mode == 2)
		return temp *= stoi(b.str);
	if (b.mode == 3)
		return temp *= b.dbl;
}

int operator/(int a, var b)
{
	int temp = a;
	if (b.mode == 1)
		return temp /= b.intgr;
	if (b.mode == 2)
		return temp /= stoi(b.str);
	if (b.mode == 3)
		return temp /= b.dbl;
}

int& operator+=(int& a, var b)
{
	if (b.mode == 1)
		return a += b.intgr;
	if (b.mode == 2)
		return a += stoi(b.str);
	if (b.mode == 3)
		return a += b.dbl;
}
int& operator-=(int& a, var b)
{
	if (b.mode == 1)
		return a -= b.intgr;
	if (b.mode == 2)
		return a -= stoi(b.str);
	if (b.mode == 3)
		return a -= b.dbl;
}
int& operator*=(int& a, var b)
{
	if (b.mode == 1)
		return a *= b.intgr;
	if (b.mode == 2)
		return a *= stoi(b.str);
	if (b.mode == 3)
		return a *= b.dbl;
}
int& operator/=(int& a, var b)
{
	if (b.mode == 1)
		return a /= b.intgr;
	if (b.mode == 2)
		return a /= stoi(b.str);
	if (b.mode == 3)
		return a /= b.dbl;
}
bool operator>(int a, var b)
{
	if (b.mode == 1)
		return (a > b.intgr);
	if (b.mode == 2)
		return (a > stoi(b.str));
	if (b.mode == 3)
		return (a > b.dbl);
}
bool operator<(int a, var b)
{
	if (b.mode == 1)
		return (a < b.intgr);
	if (b.mode == 2)
		return (a < stoi(b.str));
	if (b.mode == 3)
		return (a < b.dbl);
}
bool operator==(int a, var b)
{
	if (b.mode == 1)
		return (a == b.intgr);
	if (b.mode == 2)
		return (a == stoi(b.str));
	if (b.mode == 3)
		return (a == b.dbl);
}
bool operator!=(int a, var b)
{
	if (b.mode == 1)
		return (a != b.intgr);
	if (b.mode == 2)
		return (a != stoi(b.str));
	if (b.mode == 3)
		return (a != b.dbl);
}
bool operator>=(int a, var b)
{
	if (b.mode == 1)
		return (a >= b.intgr);
	if (b.mode == 2)
		return (a >= stoi(b.str));
	if (b.mode == 3)
		return (a >= b.dbl);
}
bool operator<=(int a, var b)
{
	if (b.mode == 1)
		return (a <= b.intgr);
	if (b.mode == 2)
		return (a <= stoi(b.str));
	if (b.mode == 3)
		return (a <= b.dbl);
}

string operator+(string a, var b)
{
	string temp = a;
	if (b.mode == 1)
		return temp += to_string(b.intgr);
	if (b.mode == 2)
		return temp += b.str;
	if (b.mode == 3)
		return temp += to_string(b.dbl);
}
string operator*(string a, var b)
{
	string temp = a;
	if (b.mode == 1)
		return temp;
	if (b.mode == 2)
	{
		string t;
		for (size_t i = 0; i < temp.length(); i++)
		{
			char c = temp[i];
			if (b.str.find(c) != string::npos)
				t += c;
		}
		temp = t;
		return temp;
	}
	if (b.mode == 3)
		return temp;
}
string operator/(string a, var b)
{
	string temp = a;
	if (b.mode == 1)
		return temp;
	if (b.mode == 2)
	{
		string t;
		for (size_t i = 0; i < temp.length(); i++)
		{
			char c = temp[i];
			if (b.str.find(c) == string::npos)
				t += c;
		}
		temp = t;
		return temp;
	}
	if (b.mode == 3)
		return temp;
}
string& operator+=(string& a, var b)
{
	if (b.mode == 1)
		return a += to_string(b.intgr);
	if (b.mode == 2)
		return a += b.str;
	if (b.mode == 3)
		return a += to_string(b.dbl);
}
string& operator*=(string& a, var b)
{
	if (b.mode == 1)
		return a;
	if (b.mode == 2)
	{
		string t;
		for (size_t i = 0; i < a.length(); i++)
		{
			char c = a[i];
			if (b.str.find(c) != string::npos)
				t += c;
		}
		a = t;
		return a;
	}
	if (b.mode == 3)
		return a;
}
string& operator/=(string& a, var b)
{
	if (b.mode == 1)
		return a;
	if (b.mode == 2)
	{
		string t;
		for (size_t i = 0; i < a.length(); i++)
		{
			char c = a[i];
			if (b.str.find(c) == string::npos)
				t += c;
		}
		a = t;
		return a;
	}
	if (b.mode == 3)
		return a;
}
bool operator>(string a, var b)
{
	if (b.mode != 2)
		return 0;
	return (a > b.str);
}
bool operator<(string a, var b)
{
	if (b.mode != 2)
		return 0;
	return (a < b.str);
}
bool operator==(string a, var b)
{
	if (b.mode != 2)
		return 0;
	return (a == b.str);
}
bool operator!=(string a, var b)
{
	if (b.mode != 2)
		return 1;
	return (a != b.str);
}
bool operator>=(string a, var b)
{
	if (b.mode != 2)
		return 0;
	return (a >= b.str);
}
bool operator<=(string a, var b)
{
	if (b.mode != 2)
		return 0;
	return (a <= b.str);
}


double operator+(double a, var b)
{
	double temp = a;
	if (b.mode == 1)
		return temp += b.intgr;
	if (b.mode == 2)
		return temp += stoi(b.str);
	if (b.mode == 3)
		return temp += b.dbl;
}

double operator-(double a, var b)
{
	double temp = a;
	if (b.mode == 1)
		return temp -= b.intgr;
	if (b.mode == 2)
		return temp -= stoi(b.str);
	if (b.mode == 3)
		return temp -= b.dbl;
}

double operator*(double a, var b)
{
	double temp = a;
	if (b.mode == 1)
		return temp *= b.intgr;
	if (b.mode == 2)
		return temp *= stoi(b.str);
	if (b.mode == 3)
		return temp *= b.dbl;
}

double operator/(double a, var b)
{
	double temp = a;
	if (b.mode == 1)
		return temp /= b.intgr;
	if (b.mode == 2)
		return temp /= stoi(b.str);
	if (b.mode == 3)
		return temp /= b.dbl;
}

double& operator+=(double& a, var b)
{
	if (b.mode == 1)
		return a += b.intgr;
	if (b.mode == 2)
		return a += stoi(b.str);
	if (b.mode == 3)
		return a += b.dbl;
}
double& operator-=(double& a, var b)
{
	if (b.mode == 1)
		return a -= b.intgr;
	if (b.mode == 2)
		return a -= stoi(b.str);
	if (b.mode == 3)
		return a -= b.dbl;
}
double& operator*=(double& a, var b)
{
	if (b.mode == 1)
		return a *= b.intgr;
	if (b.mode == 2)
		return a *= stoi(b.str);
	if (b.mode == 3)
		return a *= b.dbl;
}
double& operator/=(double& a, var b)
{
	if (b.mode == 1)
		return a /= b.intgr;
	if (b.mode == 2)
		return a /= stoi(b.str);
	if (b.mode == 3)
		return a /= b.dbl;
}
bool operator>(double a, var b)
{
	if (b.mode == 1)
		return (a > b.intgr);
	if (b.mode == 2)
		return (a > stoi(b.str));
	if (b.mode == 3)
		return (a > b.dbl);
}
bool operator<(double a, var b)
{
	if (b.mode == 1)
		return (a < b.intgr);
	if (b.mode == 2)
		return (a < stoi(b.str));
	if (b.mode == 3)
		return (a < b.dbl);
}
bool operator==(double a, var b)
{
	if (b.mode == 1)
		return (a == b.intgr);
	if (b.mode == 2)
		return (a == stoi(b.str));
	if (b.mode == 3)
		return (a == b.dbl);
}
bool operator!=(double a, var b)
{
	if (b.mode == 1)
		return (a != b.intgr);
	if (b.mode == 2)
		return (a != stoi(b.str));
	if (b.mode == 3)
		return (a != b.dbl);
}
bool operator>=(double a, var b)
{
	if (b.mode == 1)
		return (a >= b.intgr);
	if (b.mode == 2)
		return (a >= stoi(b.str));
	if (b.mode == 3)
		return (a >= b.dbl);
}
bool operator<=(double a, var b)
{
	if (b.mode == 1)
		return (a <= b.intgr);
	if (b.mode == 2)
		return (a <= stoi(b.str));
	if (b.mode == 3)
		return (a <= b.dbl);
}