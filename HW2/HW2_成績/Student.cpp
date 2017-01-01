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
//	getline(infile, m_name, '\n'); // string m_name; 學院名稱
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
		cout << "請問要修改第幾筆成績：";
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
	os << "<< 姓名：" << m_name << std::endl;
	os << "<< 學號：" << studentnumber << endl;
	if(m_grades.size() != 0)
	{
		os << "<< 成績：";
		std::vector<Grade *>::iterator iter;
		for (iter=m_grades.begin();iter<m_grades.end();iter++)
		{
			(*iter)->print(os);
			sum += (*iter)->returngrade();
		}
		os << "\n";
		os << "平均：" << sum/gradetotal << endl;
	}
	else
		cout << ">>目前沒有記錄任何資料\n";
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
		os << "目前沒有記錄任何資料\n";
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