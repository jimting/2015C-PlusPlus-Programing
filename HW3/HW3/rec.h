#pragma once
#include "utilwin32.h"
#include <iostream>
using namespace std;
class obj;
class point;
class rec
{
public:
	rec(void);
	~rec(void);
	rec(const int left, const int top, const int right, const int bottom); // �غc��
	bool contains(const point &pt) const; // �P�_�O�_�]�t�ǤJ���I
	bool contains(const obj &obj) const; // �P�_�O�_�]�t�ǤJ����Ӫ���
	//void draw() const; // ø�s�x�Ϊ����
	void drawBoundary();
	int orgX, orgY, width, height;
};

