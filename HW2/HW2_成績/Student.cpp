#include "Student.h"

Student::Student(string name,string number)
{
	m_name = name;
	studentnumber = number;
	gradetotal = 0;
}
//Student::Student(ifstream &infile)
//{
//	char buf[50];
//	
//	getline(infile, m_name, '\n'); // string m_name; �ǰ|�W��
//	getline();
//	int iDept;
//	for (iDept=0; iDept<numberOfDepartments; iDept++)
//		m_departments.push_back(new Department(infile)); 
//}

Student::~Student()
{
	std::vector<Grade *>::iterator iter;
	for (iter=m_grades.begin();
		iter<m_grades.end();
		iter++)
		delete *iter;
}
void Student::changegrade()
{
	int choise;
	if(gradetotal > 1)
	{
		cout << "�аݭn�ק�ĴX�����Z�G";
		cin >> choise;
		std::vector<Grade *>::iterator iter;
		iter = m_grades.begin()+choise-1;
		(*iter)->changegrade();
	}
}

void Student::addgrade()
{
	m_grades.push_back(new Grade());
	gradetotal++;
}
void Student::print(std::ostream &os)
{
	int sum = 0;
	os << "<< �m�W�G" << m_name << std::endl;
	os << "<< �Ǹ��G" << studentnumber << endl;
	if(m_grades.size() != 0)
	{
		os << "<< ���Z�G";
		std::vector<Grade *>::iterator iter;
		for (iter=m_grades.begin();iter<m_grades.end();iter++)
		{
			(*iter)->print(os);
			sum += (*iter)->returngrade();
		}
		os << "\n";
		os << "�����G" << sum/gradetotal << endl;
	}
	else
		cout << ">>�ثe�S���O��������\n";
}
void Student::saveall(std::ostream &os)
{
	int sum = 0;
	os << m_name << std::endl;
	os << "B" << setw(3) << setfill('0') << studentnumber << endl;
	if(m_grades.size() != 0)
	{
		std::vector<Grade *>::iterator iter;
		for (iter=m_grades.begin();iter<m_grades.end();iter++)
		{
			(*iter)->print(os);
			sum += (*iter)->returngrade();
		}
		os << "\n";
		os << sum/gradetotal << endl;
	}
	else
		os << "�ثe�S���O��������\n";
}
bool Student::checkname(string name)
{
	if(name == m_name)
		return true;
	return false;
}

string Student::getname()
{
	return m_name;
}

int Student::returngradetotal()
{
	return gradetotal;
}