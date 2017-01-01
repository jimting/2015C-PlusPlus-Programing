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
	rec(const int left, const int top, const int right, const int bottom); // 建構元
	bool contains(const point &pt) const; // 判斷是否包含傳入的點
	bool contains(const obj &obj) const; // 判斷是否包含傳入的整個物件
	//void draw() const; // 繪製矩形的邊界
	void drawBoundary();
	int orgX, orgY, width, height;
};

