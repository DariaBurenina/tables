#include "polinom.h"
#include <string.h>
#include <memory.h>
#include <iostream>

PolinomNode::PolinomNode():data(), next(NULL) {};

PolinomNode::PolinomNode(Monom m, PolinomNode* n): data(m), next(n) {};

PolinomNode::~PolinomNode() {};

PolinomList :: PolinomList () //конструктор по умолчанию
{
	head = new PolinomNode;
}

PolinomList :: PolinomList(const PolinomList &p) //  конструктор копирования
{
	PolinomNode *temp;
	PolinomNode *tempThis;
	
	head = new PolinomNode;
	tempThis = head;
	temp = p.head->next;
	while (temp != NULL)
	{
		tempThis->next = new PolinomNode (temp->data, NULL);
		temp = temp->next;
		tempThis = tempThis->next;
	}

}

PolinomList & PolinomList ::operator =(const PolinomList &p)//оператор присваивания
{
	if (this == &p)
		return *this;

	PolinomNode *temp;
	PolinomNode *tempThis;
	
	head = new PolinomNode;
	tempThis = head;
	temp = p.head->next;
	while (temp != NULL)
	{
		tempThis->next = new PolinomNode (temp->data, NULL);
		temp = temp->next;
		tempThis = tempThis->next;
	}
	return *this;
}

void PolinomList::Clean()
{
	PolinomNode *curr = head->next;
	while (curr)
	{
		PolinomNode * toDelete = curr;
		curr = curr->next;
		delete toDelete;
	}
	head->next = NULL;
}

PolinomList ::~PolinomList()
{
	PolinomNode *curr = head->next;
	while (curr)
	{
		PolinomNode * toDelete = curr;
		curr = curr->next;
		delete toDelete;
	}
	delete head;
}

void PolinomList::InSert (Monom m)
{
	PolinomNode *temp;
	temp = head;
	unsigned int p = 0;
	while ((temp->next != NULL) && (temp->next->data.Power <= m.Power))
	{
		temp = temp->next;
		p = temp->data.Power;

	}
	if( p == m.Power)
	{
		temp->data.Coeff = temp->data.Coeff + m.Coeff;
	}
	else
	{
		PolinomNode *tempNext = temp->next;
		temp->next = new PolinomNode(m, tempNext);
	}
}


void PolinomList  :: Print()
{
	PolinomNode *temp = head->next; 
	if (temp == NULL)
		cout << "Полином нулевой" << endl;
	while(temp != NULL)
	{
		cout << "(" << temp->data.Coeff << "; " << temp->data.Power << ")" << endl; 
		temp = temp->next;
	}
	cout << endl;
}

PolinomList PolinomList ::operator +(const PolinomList &p)
{
	PolinomList res;
	PolinomNode *temp1 = this->head->next;
	PolinomNode *temp2 = p.head->next;
	PolinomNode *temp3 = res.head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->data.Power == temp2->data.Power)
		{
			if (abs(temp1->data.Coeff + temp2->data.Coeff) > 0.0001)
			{
				Monom m(temp1->data.Coeff + temp2->data.Coeff, temp1->data.Power);
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(m, tempNext);
				temp3 = temp3->next;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
			
		}
		else if (temp1->data.Power < temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp1->data, tempNext);
				temp3 = temp3->next;
				temp1 = temp1->next;
			}
			else if (temp1->data.Power > temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp2->data, tempNext);
				temp3 = temp3->next;
				temp2 = temp2->next;
			}
	}
	while (temp1 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp1->data, tempNext);
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp2->data, tempNext);
		temp3 = temp3->next;
		temp2 = temp2->next;
	}
	return res;
}

void PolinomList  :: Addition(const PolinomList& s1, const PolinomList& s2)
{
	PolinomNode *temp1 = s1.head->next;
	PolinomNode *temp2 = s2.head->next;
	PolinomNode *temp3 = this->head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->data.Power == temp2->data.Power)
		{
			if (abs(temp1->data.Coeff - temp2->data.Coeff) > 1e-12)
			{
				Monom m(temp1->data.Coeff + temp2->data.Coeff, temp1->data.Power);
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(m, tempNext);
				temp3 = temp3->next;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
			
		}
		else if (temp1->data.Power < temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp1->data, tempNext);
				temp3 = temp3->next;
				temp1 = temp1->next;
			}
			else if (temp1->data.Power > temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp2->data, tempNext);
				temp3 = temp3->next;
				temp2 = temp2->next;
			}
	}
	while (temp1 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp1->data, tempNext);
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp2->data, tempNext);
		temp3 = temp3->next;
		temp2 = temp2->next;
	}
}

PolinomList PolinomList ::operator -(const PolinomList &p)
{
	PolinomList res;
	PolinomNode *temp1 = this->head->next;
	PolinomNode *temp2 = p.head->next;
	PolinomNode *temp3 = res.head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->data.Power == temp2->data.Power)
		{
			if( abs(temp1->data.Coeff - temp2->data.Coeff) > 1e-12 )
			{
				Monom m(temp1->data.Coeff - temp2->data.Coeff, temp1->data.Power);
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(m, tempNext);
				temp3=temp3->next;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1->data.Power < temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp1->data, tempNext);
				temp3 = temp3->next;
				temp1 = temp1->next;
			}
			else if (temp1->data.Power > temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				Monom m(-temp2->data.Coeff,temp2->data.Power);
				temp3->next = new PolinomNode(m, tempNext);
				temp3 = temp3->next;
				temp2 = temp2->next;
			}
	}	
	while (temp1 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp1->data, tempNext);
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		Monom m(-temp2->data.Coeff,temp2->data.Power);
		temp3->next = new PolinomNode(m, tempNext);
		temp3 = temp3->next;
		temp2 = temp2->next;
	}
	return res;
}

void PolinomList  :: Subtruction(const PolinomList& s1, const PolinomList& s2)
{
	PolinomNode *temp1 = s1.head->next;
	PolinomNode *temp2 = s2.head->next;
	PolinomNode *temp3 = this->head;

	while ((temp1 != NULL) && (temp2 != NULL))
	{
		if (temp1->data.Power == temp2->data.Power)
		{
			if( abs(temp1->data.Coeff - temp2->data.Coeff) > 1e-12 )
			{
				Monom m(temp1->data.Coeff - temp2->data.Coeff, temp1->data.Power);
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(m, tempNext);
				temp3=temp3->next;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if (temp1->data.Power < temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				temp3->next = new PolinomNode(temp1->data, tempNext);
				temp3 = temp3->next;
				temp1 = temp1->next;
			}
			else if (temp1->data.Power > temp2->data.Power) 
			{
				PolinomNode *tempNext = temp3->next;
				Monom m(-temp2->data.Coeff,temp2->data.Power);
				temp3->next = new PolinomNode(m, tempNext);
				temp3 = temp3->next;
				temp2 = temp2->next;
			}
	}	
	while (temp1 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		temp3->next = new PolinomNode(temp1->data, tempNext);
		temp3 = temp3->next;
		temp1 = temp1->next;
	}
	while (temp2 != NULL)
	{
		PolinomNode *tempNext = temp3->next;
		Monom m(-temp2->data.Coeff,temp2->data.Power);
		temp3->next = new PolinomNode(m, tempNext);
		temp3 = temp3->next;
		temp2 = temp2->next;
	}
}

PolinomList PolinomList ::operator *(const PolinomList &p)
{
	PolinomList res;
	PolinomNode *temp1 = this->head->next;
	if((this->head->next == NULL)||(p.head->next == NULL))
	{
		return res;
	}
	while (temp1 != NULL)
	{
		PolinomNode *temp2 = p.head->next;
		while (temp2 != NULL)
		{
			unsigned int s1_100 =temp1->data.Power/100; 
			unsigned int s2_100 =temp2->data.Power/100; 
			unsigned int s1_10 =temp1->data.Power/10 - 10*s1_100; 
			unsigned int s2_10 =temp2->data.Power/10 - 10*s2_100; 
			unsigned int s1_1 =temp1->data.Power - 100*s1_100 -10*s1_10; 
			unsigned int s2_1 =temp2->data.Power - 100*s2_100 -10*s2_10; 
			if (( (s1_100 + s2_100) <= 9) && ( (s1_10 + s2_10) <= 9) && ( (s1_1 + s2_1) <= 9))
			{
				Monom m( temp1->data.Coeff * temp2->data.Coeff, temp1->data.Power + temp2->data.Power);
				res.InSert(m);
				temp2 = temp2->next;
			}
			else
			{
				cout << "Превышена допустимая степень. Результат не будет содержать в себе моном: " << endl;
				cout << "("<<temp1->data.Coeff <<";"<<temp1->data.Power<<") * ("<<temp2->data.Coeff <<";"<<temp2->data.Power<<")"<<endl;
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}	
	return res;
}

int PolinomList :: Multiplication(const PolinomList& s1, const PolinomList& s2)
{
	int err = 0;
	PolinomNode *temp1 = s1.head->next;
	if((s1.head->next == NULL)||(s2.head->next == NULL))
	{
		this->Clean();
		return err;
	}
	while (temp1 != NULL)
	{
		PolinomNode *temp2 = s2.head->next;
		while (temp2 != NULL)
		{
			unsigned int s1_100 =temp1->data.Power/100; 
			unsigned int s2_100 =temp2->data.Power/100; 
			unsigned int s1_10 =temp1->data.Power/10 - 10*s1_100; 
			unsigned int s2_10 =temp2->data.Power/10 - 10*s2_100; 
			unsigned int s1_1 =temp1->data.Power - 100*s1_100 -10*s1_10; 
			unsigned int s2_1 =temp1->data.Power - 100*s1_100 -10*s1_10; 
			if (( (s1_100 + s2_100) <= 9) && ( (s1_10 + s2_10) <= 9) && ( (s1_1 + s2_1) <= 9))
			{
				Monom m( temp1->data.Coeff * temp2->data.Coeff, temp1->data.Power + temp2->data.Power);
				this->InSert(m);
				temp2 = temp2->next;
			}
			else
			{
				err = 1;
				temp2 = temp2->next;
			}
		}
		temp1 = temp1->next;
	}	
	
	return err;
}

PolinomList  PolinomList  ::operator *(double c)
{
	PolinomNode *temp = head->next; 
	while(temp != NULL)
	{
		temp -> data.Coeff = temp->data.Coeff * c;
		temp = temp->next;
	}
	return *this;	
}

void PolinomList  :: Multiplication_on_scalar( double num)
{
	PolinomNode *temp = head->next; 
	while(temp != NULL)
	{
		temp -> data.Coeff = temp->data.Coeff * num;
		temp = temp->next;
	}
}


void PolinomList :: Manual_input()
{
	double coef;
	int p;
	cout<<"Введите коэффициент слагаемого"<<endl;
	cin>>coef;
	while(coef == 0.0) 
	{
		cout<<"Вы ввели некорректное значение коэффициента. Введите коэффициент слагаемого повторно. "<<endl;
		cin>>coef;
		cout << endl << endl;
	}
	cout<<"Введите степень слагаемого. Предупреждение: степень может принимать значения:[0;999]"<<endl;
	cin>>p;
	cout << endl << endl;
	while((p < 0) || (p > 999)) 
	{
		cout<<"Вы ввели некорректное значение степени. Введите степень слагаемого повторно. Предупреждение: степень может принимать значения:[0;999]"<<endl;
		cin>>p;
		cout << endl << endl;
	}
	unsigned int power = static_cast<unsigned int>(p);
	Monom m(coef, power);
	this->InSert(m);
}