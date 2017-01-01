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
	point(const int x, const int y); // 建構元
	point operator+(const point &rhs) const; // 計算兩個點的向量和
	bool isInside(const rec &rec) const; // 判斷點是否在傳入的矩形區間內
	void shaping();
	int X,Y;
};

