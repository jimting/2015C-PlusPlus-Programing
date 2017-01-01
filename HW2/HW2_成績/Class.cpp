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
		cout << "請選擇下列功能：\n"
			<< "1：輸入資料庫檔案名稱\n"
			<< "2：結束操作\n";
		cin >> choise;
		if(choise == 1)
		{		
			Class urclass(1);
		}
		else if(choise == 2)
			return;
		else
			cout << "！請輸入正確的數字！\n";
	}
}
Class::Class(int x)
{
	int choise;
	total = 0; //學生總數歸零
	cout << "請輸入檔案名稱：";
	cin >> m_name;
	checkfile(m_name);
	while(1)
	{
		cout 
			<< "---\n"
			<< "<" << m_name 
			<< ">請選擇下列功能：\n"
			<< "1：增加一新學生\n"
			<< "2：對一學生增加一新成績\n"
			<< "3：查詢一學生之所有成績\n"
			<< "4：更改一學生之成績\n"
			<< "5：刪除某一學生\n"
			<< "6：列印顯示所有資料庫中之資料\n"
			<< "7：存檔並關閉 "<< m_name << " 檔案\n"
			<< "8：結束操作\n";
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
	cout << "請輸入學生姓名：";
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
		cout << ">>資料庫內找不到此學生\n";
	}
}
void Class::changegrade()
{
	string studentname;
	cout << "請輸入學生姓名：";
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
		cout << ">>資料庫內找不到此學生\n";
	}
}

void Class::find()
{
	string studentname;
	cout << "請輸入學生姓名：";
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
		cout << ">>資料庫內找不到此學生\n";
	}
}

void Class::addstudent()
{
	string temp;
	string studentname;
	if(total < 100){
	cout << "請輸入學生姓名：";
	cin >> studentname;
	if(studentname.size() > 6)
	{
		cout << "長度不可超過六個字！\n";
		return;
	}
	cout << "請輸入學生學號：";
	cin >> temp;
	if(temp.size() != 4)
	{
		cout << "學號必須為四個字元！\n";
		return;
	}
	std::vector<Student *>::iterator iter;
	for (iter=m_students.begin();
		iter<m_students.end();
		iter++)
	{
		if((*iter)->checkname(studentname))
		{
			cout << ">>資料庫內已經有此一學生\n";
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
		cout <<"學生數已達上限！\n";
}

void Class::addgrade()
{
	string studentname;
	cout << "請輸入學生姓名：";
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
				cout << "成績數已達上限！\n";
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
		cout << ">>資料庫內沒有任何資料\n";
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