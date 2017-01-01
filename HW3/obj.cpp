#include "obj.h"
#include "point.h"
#include "rec.h"
#include <conio.h>

obj::obj(void)
{
}
obj::~obj(void)
{
}
obj::obj(const char face, const point position, const point data[][4],const int number)
{
	Face = face;
	Pos.X = position.X;
	Pos.Y = position.Y;
	for(int i = 0; i < 4; i++)
	{ 
		Data[i].X = data[number][i].X;
		Data[i].Y = data[number][i].Y;
	}
} // 建構元
bool obj::move(const point &offset, rec &boundary)
{
	draw(false);
	//boundary.drawBoundary();
	Pos = Pos.operator+(offset);
	if(!isInside(boundary))
	{
		//Pos = Pos.operator+(point(0,-1));
		return false;
	}
	draw();
	return true;
} // 移動 offset 位移
bool obj::isInside(const rec &rect) const
{
	for(int i = 0 ; i < 4; i++)
	{
		point temp = Pos.operator+(Data[i]);		
		if(!rect.contains(temp))
			return false;
	}
	return true;
} // 檢查物件是否在矩形區域 rect 中 並且檢查下&&左&&右有沒有觸碰到別的方塊
bool obj::checkdraw(const int check[25][16],point &checkplace)
{
	point temp1 = Pos.operator+(checkplace);
	for(int i = 0; i < 4;i++)
	{
		point temp = temp1.operator+(Data[i]);
		if(check[temp.X-9][temp.Y-4] == 1)
			return false;
	}
	return true;
}
bool obj::checkleft(const rec &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		point temp = Pos.operator+(Data[i]);
		temp = temp.operator+(point(-1,0));
		if(!checkdraw(check,point(-1,0)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
bool obj::checkright(const rec &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		point temp = Pos.operator+(Data[i]);
		temp = temp.operator+(point(1,0));
		if(!checkdraw(check,point(1,0)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
bool obj::checkdown(const rec &rect,const int check[25][16])
{
	for(int i = 0 ; i < 4; i++)
	{
		point temp = Pos.operator+(Data[i]);
		temp = temp.operator+(point(0,1));
		if(!checkdraw(check,point(0,1)))
			return false;
		if(!rect.contains(temp))
			return false;
	}
	return true;
}
void obj::draw(bool choise) const
{
	if(choise)
	{
		for(int i =0; i < 4; i++)
		{
			point temp = Pos.operator+(Data[i]);
			gotoxy(temp.X,temp.Y);
			cout << Face;
		}
	}
	else
	{
		for(int i =0; i < 4; i++)
		{
			point temp = Pos.operator+(Data[i]);
			gotoxy(temp.X,temp.Y);
			cout << " ";
		}
	}
} // 繪製 (true), 清除 (false)
void obj::swap() //轉方向囉方塊們
{
	for(int i = 0; i < 4; i++)
	{
		Data[i].shaping();
	}
}
bool obj::turnright(point &right,rec &boundary)
{
	draw(false);
	//boundary.drawBoundary();
	Pos = Pos.operator+(right);
	if(!isInside(boundary))
		return false;
	draw();
	return true;
}
bool obj::turnleft(point &left,rec &boundary)
{
	draw(false);
	//boundary.drawBoundary();
	Pos = Pos.operator+(left);
	if(!isInside(boundary))
		return false;
	draw();
	return true;
}
void obj::godown(rec &boundary,const int check[25][16])
{
	while(true)
	{
		if(!checkdraw(check,point(0,1)))
			break;
		if(!checkdown(boundary,check))
			break;
		if(!move(point(0,1), boundary))
			break;
	}
}
void obj::checkkb(int kb,point &left,point &right,rec &boundary,int check[25][16])
{
	while(kbhit())
	{
		kb = getch();
		if(kb == 72) //up key
		{
			if(checkleft(boundary,check))
				if(checkright(boundary,check))
				{
					draw(false);
					swap();
					draw();
				}
				gotoxy(1,26);
				cout << "你按了上鍵\n";
		}
		else if(kb == 75) //left key
		{
			if(checkleft(boundary,check))
				turnleft(left,boundary);
			gotoxy(1,26);
			cout << "你按了左鍵\n";
		}
		else if(kb == 77) // right key
		{
			if(checkright(boundary,check))
				turnright(right,boundary);
			gotoxy(1,26);
			cout << "你按了右鍵\n";
		}
		else if(kb == 80) //down key
		{
			godown(boundary,check);
			gotoxy(1,26);
			cout << "你按了下鍵\n";
		}
		else if(kb == 'p' || kb == 'P')
		{

			gotoxy(60,8);
			cout << "=暫停中=";
			gotoxy(1,26);
			cout << "你按了P或p鍵\n";
			pause(kb);
		}
	}
}
void obj::check(int check[25][16],const int orgX,const int orgY)
{
	for(int i =0; i < 4; i++)
	{
		point temp = Pos.operator+(Data[i]);
		check[temp.X-orgX+1][temp.Y-orgY+1] = 1;
	}
}
void obj::drawcheck(int check[25][16],const int width,const int height,const int orgX,const int orgY)
{
	for(int i = 0; i < width;i++)
		for(int j = 0; j < height;j++)
		{
			if(check[i][j] == 1)
			{
				gotoxy(i+9,j+4);
				cout << Face;
			}
		}
}
void obj::pause(int kb)
{
	while(true)
	{
		if(kbhit())
		{
			kb = getch();
			if(kb == 'p' || kb == 'P')
			{
				gotoxy(60,8);
				cout << "           ";
				break;
			}
		}
	}
}
int obj::checkline(int check[25][16],int points)
{
	int i = 16;
	while(i >= 0 )
	{
		if(check[1][i] == 1 && check[2][i] == 1 && check[3][i] == 1 && check[4][i] == 1 && check[5][i] == 1 && check[6][i] == 1 && check[7][i] == 1 && check[8][i] == 1 && check[9][i] == 1 && check[10][i] == 1 && check[11][i] == 1  && check[12][i] == 1 && check[13][i] == 1 &&check[14][i] == 1 && check[15][i] == 1 && check[16][i] == 1 && check[17][i] == 1 && check[18][i] == 1 && check[19][i] == 1 && check[20][i] == 1 && check[21][i] == 1 && check[22][i] == 1 && check[23][i] == 1 && check[24][i] == 1)
		{
			for(int k = i;k >= 0;k--){
				for(int j = 0;j<25;j++)
				{
					if(i != 0)
						check[j][k] = check[j][k-1] ;
					else
						check[k][j] = 0;
				}
			}
			points++;
		}
		else
			i--;
	}
	return points;
}
bool obj::checklose(int check[25][16])
{
	for(int i = 0; i < 25; i++)
	{
		if(check[i][1] == 1)
			return false;
	}
	return true;
}