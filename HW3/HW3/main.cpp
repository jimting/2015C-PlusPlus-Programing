#include "utilwin32.h"
#include <conio.h>
#include <iostream>
#include "point.h"
#include "rec.h"
#include "obj.h"
#include <assert.h>
#include <time.h>
using namespace std;

int main()
{
	point right(1,0);
	point left(-1,0);
	int kb = -1;
	int count = 0;
	int points = 0;
	const int orgX = 10, orgY = 5, width = 25, height = 16;
	int check[width][height];
	for(int i = 0;i<width;i++)
		for(int j=0;j<height;j++)
			check[i][j] = 0;
	rec canvas(orgX, orgY, width-1, height-1);
	clrscr();
	canvas.drawBoundary();
	const point shape[7][4] = {{ point(-1,0),point(0,0)	,point(0,1)	,point(0,2)	},{ point(0,0)	,point(1,0)	,point(0,1)	,point(0,2)	},{ point(0,0)	,point(0,1)	,point(0,2)	,point(0,3)	},{ point(0,0)	,point(0,1)	,point(0,2)	,point(1,1)	},{ point(0,0)	,point(1,0)	,point(0,1)	,point(1,1)	},{ point(0,1)	,point(0,0)	,point(1,1)	,point(1,2)	},{ point(0,1)	,point(0,2)	,point(1,1)	,point(1,0)	}};	
	while(true){
		srand( (unsigned)time(NULL) );
		int shapenumber = rand()%7;
		obj obj('*', point(orgX+width/2-1,orgY), shape,shapenumber);
		points = obj.checkline(check,points); //確認有沒有消排得分
		clrscr();
		canvas.drawBoundary();
		gotoxy(60,3);
		cout << "按上來旋轉方塊";
		gotoxy(60,4);
		cout << "按下來降到最下面";
		gotoxy(60,5);
		cout << "按左右來移動";
		gotoxy(60,6);
		cout << "按p來暫停";
		gotoxy(60,10);
		cout << "目前得分：" << points;
		gotoxy(60,10);
		cout << "目前得分：" << points;
		obj.drawcheck(check,width,height,orgX,orgY); //印出已經觸碰到邊界的方塊們
		obj.draw();
		while (true)
		{
			if(count++ % 6 == 0)
			{
				if(!obj.checkdraw(check,point(0,1)))
					break;
				if(!obj.move(point(0,1), canvas))
					break;
			}
			delay(80);
			obj.checkkb(kb,left,right,canvas,check);
			if(!obj.checkdraw(check,point(0,1)))
				break;
		}
		obj.check(check,orgX,orgY);
		if(!obj.checklose(check))
			break;
	}
	gotoxy(1,26); 
	cout << "哇！結束了！\n";
	system("pause");
}