#pragma once
#include <iostream>

using namespace std;
class Vetor
{
private:
	int Size;
	int* ptr;
public:
	Vetor(int = 10);
	Vetor(const Vetor&);//construtor por cópia
	virtual ~Vetor();
	int getSize();

	const Vetor& operator = (const Vetor&);
	bool operator ==(const Vetor&);
	bool operator !=(const Vetor&);
	int &operator[](int); //operador subscrito no vetor
	Vetor operator+(const Vetor&) const;
	Vetor operator-(const Vetor&) const;
	double operator*(const Vetor&) const;
	//friend
	friend ostream& operator<<(ostream&, const Vetor&);
	friend istream& operator>>(istream&, const Vetor&);


};