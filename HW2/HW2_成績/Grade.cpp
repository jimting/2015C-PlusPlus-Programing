#include "Grade.h"

Grade::Grade()
{
	cout << "請輸入成績：";
	cin >> m_grade;
}
Grade::Grade(ifstream &infile)
{
	
}

Grade::~Grade(void)
{
}
int Grade::returngrade()
{
	return m_grade;
}
void Grade::changegrade()
{
	cout << "請輸入成績：";
	cin >> m_grade;
}

void Grade::print(std::ostream &os)
    {
        os << m_grade << " ";
    }
