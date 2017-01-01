#include "point.h"
#include "rec.h"
#include "obj.h"
const int change[4] = {0,-1,1,0};

point::point(void)
{
}


point::~point(void)
{
}

point::point(const int x, const int y)
{
	X =x;
	Y=y;
}
point point::operator+(const point &rhs) const
{
	point temp(X+rhs.X,Y+rhs.Y);
	return temp;
}
bool point::isInside(const rec &rec) const
{
	if(X <= rec.orgX || Y <= rec.orgY || X >= rec.orgX + rec.width || Y >= rec.orgY + rec.height)
		return false;
	return true;
}

void point::shaping()
{
	int temp1 = X*change[0] + Y*change[1];
	int temp2 = X*change[2] + Y*change[3];
	X = temp1;
	Y = temp2;
}