#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
	long long numerator;
	long long denominator;
	void simplify();
public:
	Fraction(long long num, long long denom);
	Fraction();

	Fraction operator+(const Fraction &f);
	Fraction operator+(const long long &f);
	Fraction operator-(const Fraction &f);
	Fraction operator-(const long long &f);
	Fraction operator*(const Fraction &f);
	Fraction operator*(const long long &f);
	Fraction operator/(const Fraction &f);
	Fraction operator/(const long long &f);
	void operator+=(const Fraction &f);
	void operator+=(const long long &f);
	void operator-=(const Fraction &f);
	void operator-=(const long long &f);
	void operator*=(const Fraction &f);
	void operator/=(const Fraction &f);
	void operator*=(const long long &f);
	void operator/=(const long long &f);
	bool operator==(const Fraction &f);
	bool operator!=(const Fraction &f);
	bool operator<(const Fraction &f);
	bool operator<=(const Fraction &f);
	bool operator>(const Fraction &f);
	bool operator>=(const Fraction &f);
		
	long long getNumerator();
	long long getDenominator();
	void setNumerator(long long n);
	void setDenominator(long long n);
	
	static long long gcd(long long a, long long b);	
	static long long lcm(long long a, long long b);
	
};

#endif