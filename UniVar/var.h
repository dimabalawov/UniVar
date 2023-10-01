#pragma once
#include <iostream>
using namespace std;
class var
{
	int intgr;
	string str;
	double dbl;
	short mode;//1 - int,2 - string, 3 - double
public:
	var();
	var(int a);
	var(string a);
	var(double a);
	void Show();
	var operator+(var a);
	var operator-(var a);
	var operator*(var a);
	var operator/(var a);
	var& operator+=(var a);
	var& operator-=(var a);
	var& operator*=(var a);
	var& operator/=(var a);
	bool operator>(var a);
	bool operator<(var a);
	bool operator==(var a);
	bool operator>=(var a);
	bool operator<=(var a);
	bool operator!=(var a);

	friend int operator+(int a, var b);
	friend int operator-(int a, var b);
	friend int operator*(int a, var b);
	friend int operator/(int a, var b);
	friend int& operator+=(int& a, var b);
	friend int& operator-=(int& a, var b);
	friend int& operator*=(int& a, var b);
	friend int& operator/=(int& a, var b);
	friend bool operator>(int a, var b);
	friend bool operator<(int a, var b);
	friend bool operator==(int a, var b);
	friend bool operator!=(int a, var b);
	friend bool operator>=(int a, var b);
	friend bool operator<=(int a, var b);

	friend string operator+(string a, var b);
	friend string operator*(string a, var b);
	friend string operator/(string a, var b);
	friend string& operator+=(string& a, var b);
	friend string& operator*=(string& a, var b);
	friend string& operator/=(string& a, var b);
	friend bool operator>(string a, var b);
	friend bool operator<(string a, var b);
	friend bool operator==(string a, var b);
	friend bool operator!=(string a, var b);
	friend bool operator>=(string a, var b);
	friend bool operator<=(string a, var b);

	friend double operator+(double a, var b);
	friend double operator-(double a, var b);
	friend double operator*(double a, var b);
	friend double operator/(double a, var b);
	friend double& operator+=(double& a, var b);
	friend double& operator-=(double& a, var b);
	friend double& operator*=(double& a, var b);
	friend double& operator/=(double& a, var b);
	friend bool operator>(double a, var b);
	friend bool operator<(double a, var b);
	friend bool operator==(double a, var b);
	friend bool operator!=(double a, var b);
	friend bool operator>=(double a, var b);
	friend bool operator<=(double a, var b);
};