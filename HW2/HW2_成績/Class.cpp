#include "Class.h"
Class::Class()
{
}
//Class::Class(ifstream &infile)
//{
//	char buf[50];
//	getline(infile, m_name, '\n');
//	infile.getline(buf, 50, '\n');
//	std::vector<Student *>::iterator iter;
//	for (iter=m_students.begin();
//		iter<m_students.end();
//		iter++){
//        m_students.push_back(new Student(infile)); 		
//	}
//}
void Class::menu()
{
	int choise;
	while(1){
		cout << "�п�ܤU�C�\��G\n"
			<< "1�G��J��Ʈw�ɮצW��\n"
			<< "2�G�����ާ@\n";
		cin >> choise;
		if(choise == 1)
		{		
			Class urclass(1);
		}
		else if(choise == 2)
			return;
		else
			cout << "�I�п�J���T���Ʀr�I\n";
	}
}
Class::Class(int x)
{
	int choise;
	total = 0; //�ǥ��`���k�s
	cout << "�п�J�ɮצW�١G";
	cin >> m_name;
	checkfile(m_name);
	while(1)
	{
		cout 
			<< "---\n"
			<< "<" << m_name 
			<< ">�п�ܤU�C�\��G\n"
			<< "1�G�W�[�@�s�ǥ�\n"
			<< "2�G��@�ǥͼW�[�@�s���Z\n"
			<< "3�G�d�ߤ@�ǥͤ��Ҧ����Z\n"
			<< "4�G���@�ǥͤ����Z\n"
			<< "5�G�R���Y�@�ǥ�\n"
			<< "6�G�C�L��ܩҦ���Ʈw�������\n"
			<< "7�G�s�ɨ����� "<< m_name << " �ɮ�\n"
			<< "8�G�����ާ@\n";
		cin >> choise;
		switch(choise)
		{
		case 1 :{addstudent();break;}
		case 2 :{addgrade();break;}
		case 3 :{find();break;}
		case 4 :{changegrade();break;}
		case 5 :{deletestudent();break;}
		case 6 :{print(cout);break;}
		case 7 :{save();return;}
		case 8 :{return;}
		}
	}
}
Class::~Class(void)
{
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
		delete *iter;
}
void Class::checkfile(string filename)
{
	ifstream infile(filename);
	if (!infile)
		return;	
	
}

void Class::deletestudent()
{
	string studentname;
	cout << "�п�J�ǥͩm�W�G";
	cin >> studentname;
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			m_students.erase(iter);
			return;
		}
	}
	if(iter == m_students.end())
	{
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
	}
}
void Class::changegrade()
{
	string studentname;
	cout << "�п�J�ǥͩm�W�G";
	cin >> studentname;
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			(*iter)->print(cout);
			(*iter)->changegrade();
			return;
		}
	}
	if(iter == m_students.end())
	{
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
	}
}

void Class::find()
{
	string studentname;
	cout << "�п�J�ǥͩm�W�G";
	cin >> studentname;
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			(*iter)->print(cout);
			return;
		}
	}
	if(iter == m_students.end())
	{
		cout << ">>��Ʈw���䤣�즹�ǥ�\n";
	}
}

void Class::addstudent()
{
	string temp;
	string studentname;
	if(total < 100){
	cout << "�п�J�ǥͩm�W�G";
	cin >> studentname;
	if(studentname.size() > 6)
	{
		cout << "���פ��i�W�L���Ӧr�I\n";
		return;
	}
	cout << "�п�J�ǥ;Ǹ��G";
	cin >> temp;
	if(temp.size() != 4)
	{
		cout << "�Ǹ��������|�Ӧr���I\n";
		return;
	}
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			cout << ">>��Ʈw���w�g�����@�ǥ�\n";
			break;
		}
	}
	if(iter == m_students.end())
	{
		total++;
		m_students.push_back(new Student(studentname,temp));
	}	
	}
	else
		cout <<"�ǥͼƤw�F�W���I\n";
}

void Class::addgrade()
{
	string studentname;
	cout << "�п�J�ǥͩm�W�G";
	cin >> studentname;
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			if((*iter)->returngradetotal() < 6)
				(*iter)->addgrade();
			else
				cout << "���Z�Ƥw�F�W���I\n";
		}
	}
}

void Class::save()
{
	ofstream filename(m_name);
	saveall(filename);
}

void Class::print(std::ostream &os)
{
	if(m_students.size() != 0){
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
		(*iter)->print(os);
	}
	else
		cout << ">>��Ʈw���S��������\n";
}

void Class::saveall(std::ostream &os)
{
	//os.write((char *)m_students[i]->getname(), sizeof(Student *)*total);
	os << m_name << std::endl;
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
		(*iter)->saveall(os);
}