// класс или структура Монома (double коэффициент, целая свернутая степень)
#ifndef __MONOM_H___
#define __MONOM_H___

#include <iostream>
#include <memory>
using namespace std;

class Monom
{
	public:

	double Coeff;  //коэффициент
	unsigned int Power;  //степень  

	//Monom();
	Monom(double C = 0.0, int P = 0);
	Monom(const Monom &m);
	~Monom();

	Monom & operator =(const Monom &m);
	bool operator==(const Monom &m) const;
};	
#endif
