#include "Grade.h"

Grade::Grade()
{
	cout << "�п�J���Z�G";
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
	cout << "�п�J���Z�G";
	cin >> m_grade;
}

void Grade::print(std::ostream &os)
    {
        os << m_grade << " ";
    }
