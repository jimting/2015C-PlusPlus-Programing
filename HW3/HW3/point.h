#pragma once
#include "utilwin32.h"
#include <iostream>
using namespace std;

class obj;
class rec;
class point
{
public:
	point(void);
	~point(void);
	point(const int x, const int y); // �غc��
	point operator+(const point &rhs) const; // �p�����I���V�q�M
	bool isInside(const rec &rec) const; // �P�_�I�O�_�b�ǤJ���x�ΰ϶���
	void shaping();
	int X,Y;
};

