#include "monom.h"
#include <string.h>
#include <memory.h>
#include <iostream>


Monom :: Monom(double C, int P)//����������� �������������
{
	if (( P < 0 ) || (P > 999))
		throw "Error";
	else
	{
		Coeff = C;
		Power = P;
	}
}

Monom :: Monom(const Monom &mon) //����������� �����������
{
	Coeff = mon.Coeff;
	Power = mon.Power;
}

Monom ::~Monom()//����������
{
}

Monom & Monom ::operator =(const Monom &m)//�������� ������������
{
	if (this == &m)
		return *this;
	Coeff = m.Coeff;
	Power = m.Power;
	return *this;
}

bool Monom::operator==(const Monom &m) const // ���������
{
	if((this->Coeff == m.Coeff) &&(this->Power == m.Power))
		return true;
	else 
		return false;

}
