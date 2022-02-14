#include<iostream>
#include<cmath>

#define PI 3.14159265
using namespace std;

class ComplexNumber{				
	public:
		double real;
		double imag;
		ComplexNumber(double,double);
		ComplexNumber operator+(const ComplexNumber &);
		ComplexNumber operator-(const ComplexNumber &);
		ComplexNumber operator*(const ComplexNumber &);
		ComplexNumber operator/(const ComplexNumber &);
		bool operator==(const ComplexNumber &);
		double abs();
		double angle();
};

ComplexNumber::ComplexNumber(double x = 0,double y = 0){
	
	real = x; imag = y;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &c){
	return ComplexNumber(real+c.real,imag+c.imag);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &c){
	return ComplexNumber(real-c.real,imag-c.imag);
}
ComplexNumber ComplexNumber::operator*(const ComplexNumber &c){
	
	if (c.imag == 0)
	{
		return ComplexNumber(real*c.real,imag*c.real);
	}
	else
	{
		return ComplexNumber((real*c.real)-(imag*c.imag),(real*c.imag)+(imag*c.real));
	}
	
}
ComplexNumber ComplexNumber::operator/(const ComplexNumber &c){
	if (c.imag == 0 )
	{
		return ComplexNumber(real/c.real,imag/c.real);
	}
	else{
		
	return ComplexNumber(((real*c.real)+(imag*c.imag))/(pow(c.real,2)+pow(c.imag,2)),((imag*c.real)-(real*c.imag))/(pow(c.real,2)+pow(c.imag,2)));
	}
}

ComplexNumber operator+(double s, const ComplexNumber &c){
	return ComplexNumber(s+c.real,c.imag);
}

ComplexNumber operator-(double s, const ComplexNumber &c){
	return ComplexNumber(s-c.real,-c.imag);
}
ComplexNumber operator*(double s,const ComplexNumber &c){
	return ComplexNumber(s*c.real,s*c.imag);
}
ComplexNumber operator/(double s,const ComplexNumber &c){
	if (c.imag != 0)
	{
		return ComplexNumber((c.real*s)/(pow(c.real,2)+pow(c.imag,2)),-(s*c.imag)/(pow(c.real,2)+pow(c.imag,2)));
	}
	else
	{
	return ComplexNumber(s/c.real,s/c.imag);
	}
}

bool ComplexNumber::operator==(const ComplexNumber &c)
{
		if (real == c.real && imag == c.imag)
		{
			return true;
		}
		else
		{
			return false;
		}
}
ComplexNumber operator==(double s,const ComplexNumber &c){
	if (s == c.real && s == c.imag)
		{
			return true;
		}
		else
		{
			return false;
		}

}
ostream & operator<<(ostream &os, const ComplexNumber &c)
{
	if (c.imag == 0 && c.real == 0 )
	{
		return os <<"0";
	}
	
	if (c.imag < 0)		
	{
		if (c.real == 0)
		{
			return os << c.imag <<"i";
		}
		if (c.real > 0 || c.real < 0){
		return os << c.real << c.imag <<"i";
		}
	}
	else if(c.imag >= 0){
		 if (c.imag == 0)
		{
			return os << c.real;
		}
		if (c.real == 0)
		{
			return os << c.imag <<"i";
		}
		else if (c.real > 0 || c.real < 0)
		{
			return os << c.real << "+" << c.imag <<"i";
		}
	
	}
	return os;
}

//Write your code here
double ComplexNumber::abs()
{
	return sqrt(pow(real,2)+pow(imag,2));
}

double ComplexNumber::angle()
{
	if (real >= 0 && imag < 0)
	{
		return -acos(real/(sqrt(pow(real,2)+pow(imag,2))))* 180 / PI;
	}
	if (real < 0 && imag < 0)
	{
		return -acos(real/(sqrt(pow(real,2)+pow(imag,2))))* 180 / PI;
	}
	else{
	return acos(real/(sqrt(pow(real,2)+pow(imag,2))))* 180 / PI;
	}
}



int main(){
	ComplexNumber a(1.5,2),b(3.2,-2.5),c(-1,1.2);	
	cout << a << "\n";
cout << b << "\n";
cout << c << "\n";
cout << a+2.5 << "\n";
cout << 2.5+a << "\n";
cout << a-1.5 << "\n";
cout << 1.5-a << "\n";
cout << b+ComplexNumber(0,2.5) << "\n";
cout << c-c << "\n";
cout << "-----------------------------------\n";
	
	
	ComplexNumber d = (a+b)/c;
	ComplexNumber e = b/(a-c);
	cout << d << "\n";
	cout << "-----------------------------";
	cout << 1/c << "\n";
	

}
	
	






