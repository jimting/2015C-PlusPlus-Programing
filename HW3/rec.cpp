#include "rec.h"
#include "obj.h"
#include "point.h"

rec::rec(void)
{
}


rec::~rec(void)
{
}

rec::rec(const int left, const int top, const int right, const int bottom)
{
	orgX = left;
	orgY = top;
	width = right;
	height = bottom;
} // 建構元

bool rec::contains(const point &pt) const
{
	if(pt.X <= orgX-1 || pt.Y <= orgY || pt.X > orgX+width-1 || pt.Y > orgY+height-2)
		return false;
	return true;
} // 判斷是否包含傳入的點

bool rec::contains(const obj &obj) const
{
	if(obj.isInside(*this))
	{
	return true;
	}
	return false;
} // 判斷是否包含傳入的整個物件

/*void rec::draw() const
{

} // 繪製矩形的邊界*/

void rec::drawBoundary()
{
    int i;
    gotoxy(orgX-1, orgY-1);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';

    for (i=0; i<height; i++)
    {
        gotoxy(orgX-1, orgY+i); cout << '|';
        gotoxy(orgX+width, orgY+i); cout << '|';
    }

    gotoxy(orgX-1, orgY+height);
    cout << '+';
    for (i=0; i<width; i++)
        cout << '-';
    cout << '+';
    gotoxy(1,23); // 把游標移動到視窗中固定的地方, 
}                 // 否則在畫面上會一直看到游標在不同地方閃啊閃的