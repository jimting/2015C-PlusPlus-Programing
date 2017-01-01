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
} // �غc��

bool rec::contains(const point &pt) const
{
	if(pt.X <= orgX-1 || pt.Y <= orgY || pt.X > orgX+width-1 || pt.Y > orgY+height-2)
		return false;
	return true;
} // �P�_�O�_�]�t�ǤJ���I

bool rec::contains(const obj &obj) const
{
	if(obj.isInside(*this))
	{
	return true;
	}
	return false;
} // �P�_�O�_�]�t�ǤJ����Ӫ���

/*void rec::draw() const
{

} // ø�s�x�Ϊ����*/

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
    gotoxy(1,23); // ���в��ʨ�������T�w���a��, 
}                 // �_�h�b�e���W�|�@���ݨ��Цb���P�a��{�ڰ{��