#pragma once
#include "utilwin32.h"
#include "point.h"
#include <iostream>
#include <vector>
using namespace std;
class point;
class rec;
class obj
{
public:
	obj(void);
	~obj(void);
	obj(const char face, const point position, const point data[][4],const int); // �غc��
	bool move(const point &offset,rec &boundary); // ���� offset �첾
	bool isInside(const rec &rect) const; // �ˬd����O�_�b�x�ΰϰ� rect ��
	void draw(bool show=true) const; // ø�s (true), �M�� (false)
	void obj::swap();
	bool checkdraw(const int check[25][16],point &);
	void checkkb(int,point&,point&,rec&,int check[25][16]);
	bool turnright(point&,rec&);
	bool turnleft(point&,rec&);
	bool checkleft(const rec &rect,const int check[25][16]);
	bool checkright(const rec &rect,const int check[25][16]);
	void godown(rec &boundary,const int check[25][16]);
	void check(int check[25][16],const int,const int);
	void drawcheck(int check[25][16],const int,const int,const int,const int);
	int checkline(int check[25][16],int);
	bool checkdown(const rec &rect,const int check[25][16]);
	bool checklose(int check[25][16]);
	void pause(int);
	char Face;
	point Pos;
	point Data[4];
};

