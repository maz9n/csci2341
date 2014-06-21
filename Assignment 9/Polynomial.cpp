/**
@file    Polynomial.cpp
@author  Almozaini:Mazen:A00323488:csc34118
@version 1.0
@date    2014-06-09
*   Assignment #9 
*   due 2014-06-10
@brief
Polynomial calculator using linked lists
*/

/*
program is finished
*/

// includes
#include <iostream>
#include <sstream>
#include <math.h>
#include <string>
#include <iomanip>
#include "Polynomial.h"
using namespace std;

//----------- PolyNode struct -----------------
struct PolyNode
{
     double coef;
     int power;
     PolyNode* next;
};

//------------- relative functions identifiers------------
void addNode (PolyNode*& head, double c, int p);

void removeNode (PolyNode*& head, int p);

void changeNode (PolyNode*& head, int p, double c);

//-------------functions defenetions------------
int Polynomial::degree() const
{

    if (head == nullptr)
        return 0;
    else
        return head->power;
    
}

double Polynomial::getCoefficient(double pwr) const
{   
    PolyNode* powr = head;
    while (powr!= nullptr)
    {
        if (powr->power == pwr)
        {
            return powr->coef;
        }
        else
            powr = powr->next;
    }
    return 0;
}

double Polynomial::evaluateAt(double x) const
{ 
    PolyNode* curr = head;
    double value = 0;
    while (curr!=nullptr)
    {
        value = value + curr->coef*pow(x, curr->power);
        curr = curr->next;
    }
    return value;
}

void Polynomial::setCoefficient(double newCoefficient, int power)
{
    if(newCoefficient== 0)
    {
        removeNode(head,power);  
    }
    else
        changeNode(head,power,newCoefficient);
}

void Polynomial::print() const
{    
    PolyNode* Tnode = head;
    while(Tnode != nullptr)
    {
        if(Tnode->power > 1)
        {
            cout << Tnode->coef << "x^" << Tnode->power << " + ";
        }
        else if(Tnode->power ==1)
        {
            cout << Tnode->coef << "x" << " + ";
        }
        else if(Tnode->power==0)
        {
            cout << Tnode->coef;
        }
        Tnode = Tnode->next;
    }
}



void addNode(PolyNode*& cur, double c, int p)
{
    PolyNode *temp = new PolyNode;
    temp ->coef = c;
    temp ->power = p;
    temp -> next  = cur;
    cur = temp;
}

void removeNode(PolyNode*& cur, int p)
{
    if (cur == nullptr) return;
        
    if (cur->power == p)
    { 
        PolyNode* temp = cur;
        cur = cur->next;
        delete temp;
    }
    else
        removeNode(cur->next, p);
}

void changeNode(PolyNode*& cur, int p, double c)
{
    if (cur == nullptr || cur->power < p)
    {
        PolyNode* temp = new PolyNode;
        temp->power = p;
        temp->coef = c;
        temp->next = cur;
        cur = temp;
        changeNode(cur, p , c);
    }
    else if(cur->power == p)
    {
        cur->coef = c;
    }
    else
        changeNode(cur->next, p, c);
}

Polynomial::Polynomial()
{
    head = nullptr;
}

Polynomial::~Polynomial()
{
    PolyNode* temp;
	while (this->head != NULL)
	{
		temp = head->next;
		delete head;
		head = temp;
	}
}

ostream& operator<<(ostream& out, const Polynomial& list)
{
   PolyNode* curr;
	if (list.head == NULL) return out;
	else
	{
		curr = list.head;
		while (curr)
		{
			if (curr->coef != 1)
			out << curr->coef;
			if (curr->power > 0)
			{
				out << "x";
				if (curr->power != 1)
					out << "^" << curr->power;
			}
			if (curr->next != NULL)
				out << " + ";
			curr = curr->next;
		}
	}
	return out;
}
Polynomial::Polynomial(const Polynomial& src)
{
    PolyNode* copy = src.head;
	if (&src != this)	
	{
		head = nullptr;
		while (copy != nullptr)
		{
			this->setCoefficient(copy->coef, copy->power);
			copy = copy->next;
		}
	}
 }

Polynomial&Polynomial:: operator=(Polynomial src)
{
    PolyNode* op = src.head;
	if (&src != this)
	{
		head = nullptr;
		while (op != nullptr)
		{
			this->setCoefficient(op->coef, op->power);
			op = op->next;
		}
	}
	return *this;
}


void Polynomial::swap(Polynomial& other) 
{
    std::swap(other.head,head);
}
