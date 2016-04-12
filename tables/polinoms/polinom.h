// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������

#include "monom.h"
#ifndef __POLINOM_H_
#define __POLINOM_H_

class PolinomNode
{
	public:
		Monom data;
		PolinomNode *next;
		
		PolinomNode ( const PolinomNode &p);
		PolinomNode(Monom m, PolinomNode* n);
		PolinomNode();
		~PolinomNode();
};

class PolinomList//�������� �� ������� , ����������
{
	public:
		PolinomNode *head;
		
		PolinomList();
		PolinomList ( const PolinomList &p);
		void InSert(Monom m); 
		~PolinomList();
		void Print();
		PolinomList& operator=(const PolinomList &p); 
		PolinomList operator +(const PolinomList &p);
		PolinomList operator -(const PolinomList &p);
		PolinomList operator *(const PolinomList &p);
		PolinomList  operator *( double  c);
		void Addition(const PolinomList& s1, const PolinomList& s2); //S = s1 + s2
		void Subtruction(const PolinomList& s1, const PolinomList& s2); // S = s1 - s2
		int Multiplication(const PolinomList& s1, const PolinomList& s2); // S = s1 * s2
		void Multiplication_on_scalar( double num); // S = num * s1
		void Manual_input();
		void Clean();
};

#endif