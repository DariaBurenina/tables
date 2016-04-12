#include "monom.h"
#include <string.h>
#include <memory.h>
#include <iostream>


Monom :: Monom(double C, int P)//конструктор инициализатор
{
	if (( P < 0 ) || (P > 999))
		throw "Error";
	else
	{
		Coeff = C;
		Power = P;
	}
}

Monom :: Monom(const Monom &mon) //конструктор копирования
{
	Coeff = mon.Coeff;
	Power = mon.Power;
}

Monom ::~Monom()//деструктор
{
}

Monom & Monom ::operator =(const Monom &m)//оператор присваивания
{
	if (this == &m)
		return *this;
	Coeff = m.Coeff;
	Power = m.Power;
	return *this;
}

bool Monom::operator==(const Monom &m) const // сравнение
{
	if((this->Coeff == m.Coeff) &&(this->Power == m.Power))
		return true;
	else 
		return false;

}
