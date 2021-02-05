#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;


class complex
{


private:
	double realpart;
	double imaginarypart;
	string sign;

public:
	//MEMBERS functions
	//default constructor
	complex(double real = 0.0, double imaginary = 0.0) { realpart = real; imaginarypart = imaginary; }
	//void assignNewValues(double, double);

	friend ostream& operator<<(ostream& out, const complex& num);
	friend istream& operator>>(istream&, const complex&);

	//hardcode the method to compare

	bool operator == (const complex&);

	//prototype for adding two complex numbers together

	complex operator + (const complex&);

	complex operator * (const complex&);

	complex operator - (const complex&);

	complex operator / (const complex&);


	void setRealNum(double r)
	{
		realpart = r;
	}

	void setImaginaryNum(double i)
	{
		imaginarypart = i;
	}

	void setSign(string s)
	{
		sign = s;
	}

};

//implementing fuctions






/*void complex::assignNewValues(double real, double imag)
{
realpart = real;
imaginarypart = imag;
}
*/

std::ostream& operator<<(ostream &out, const complex &num)
{

	char sign = '+';

	if (num.realpart == 0 && num.imaginarypart == 0) { cout << "0" << endl; }

	else if (num.imaginarypart == 0 && num.realpart != 0) { cout << num.realpart << endl; }

	else if ((num.imaginarypart < 0) && (num.realpart != 0 && num.imaginarypart != 0)) {
		sign = '-';

		cout << num.realpart << ' ' << sign << ' ' << abs(num.imaginarypart) << 'i' << endl;
	}

	else if ((num.imaginarypart > 0) && (num.realpart != 0 && num.imaginarypart != 0)) {
		sign = '+';

		cout << num.realpart << ' ' << sign << ' ' << abs(num.imaginarypart) << 'i' << endl;
	}
	else cout << num.realpart << ' ' << sign << ' ' << abs(num.imaginarypart) << 'i' << endl;

	return out;
}

std::istream& operator>>(istream &in, complex& num)
{

	string compNum1, compNumNeg, compNumTemp;
	getline(cin, compNum1);
	compNumNeg = " - ";
	compNum1.resize(compNum1.size() - 1);
	num.setRealNum(stod(compNum1.substr(0, (compNum1.find("+" || "-") - 1))));
	if (strstr(compNum1.c_str(),compNumNeg.c_str()))
	{
		num.setImaginaryNum((-1.0)*stod(compNum1.substr((compNum1.find(" - ")+3))));
	}
	else
		num.setImaginaryNum(stod(compNum1.substr((compNum1.find(" + ")+3))));
	return in;



}

bool complex::operator == (const complex& complex2)
{
	if (realpart == complex2.realpart && imaginarypart == complex2.imaginarypart)
	{
		return true;
	}
	else
		return false;
}

complex complex::operator+(const complex& complex2)
{
	complex temp;
	temp.realpart = realpart + complex2.realpart;
	temp.imaginarypart = imaginarypart + complex2.imaginarypart;
	return temp;
}

complex complex::operator*(const complex& complex2)
{
	complex temp;
	temp.realpart = ((realpart*complex2.realpart) - (imaginarypart*complex2.imaginarypart));
	temp.imaginarypart = ((realpart*complex2.imaginarypart) + (imaginarypart*complex2.realpart));
	return temp;


}

complex complex::operator-(const complex& complex2)
{
	complex temp;
	temp.realpart = realpart - complex2.realpart;
	temp.imaginarypart = imaginarypart - complex2.imaginarypart;
	return temp;


}

complex complex::operator/(const complex& complex2)
{
	complex temp;
	temp.realpart = ((realpart*complex2.realpart) + (imaginarypart*complex2.imaginarypart)) / ((complex2.realpart*complex2.realpart) + (complex2.imaginarypart*complex2.imaginarypart));
	temp.imaginarypart = ((imaginarypart*complex2.realpart) - (realpart*complex2.imaginarypart)) / ((complex2.realpart*complex2.realpart) + (complex2.imaginarypart*complex2.imaginarypart));
	return temp;
}





int main()
{



	complex a, b, sum, mult, sub, div;
	//b.assignNewValues(5.3, -8.4); //5.3 - 8.4i
	//a.showComplexValues();//0.0 + 0.0i
	//b.showComplexValues();
	//c.showComplexValues();
	cout << "Enter your complex numbers in the form of 'x + yi'" << endl;
	cin >> a;
	cin >> b;

	cout << "\n complex number a is: ";
	cout << a << endl;

	cout << "\n complex number b is: ";
	cout << b << endl;

	sum = a + b;
	cout << "\n the sum of a and b is: ";
	cout << sum << endl;

	mult = a * b;
	cout << "\n the product of a and b is: ";
	cout << mult << endl;

	sub = a - b;
	cout << "\n the difference of a and b is: ";
	cout << sub << endl;

	div = a / b;
	cout << "\n the quotient of a and b is: ";

	cout << div << endl;

	cout << endl;

	string line = "DONE!\n";
	cout << line;



	system("pause");
	return 0;
}