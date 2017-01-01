#pragma once
#include <fstream>
#include <iostream>
#include "Student.h"
#include <string>
using namespace std;
class Class
{
public:
	Class();
	void menu();
	Class(ifstream &infile);
	Class(int);
	~Class(void);
	void print(std::ostream &os);
	void unitTest();
	void addstudent();
	void addgrade();
	void find();
	void changegrade();
	void deletestudent();
	void save();
	void saveall(std::ostream &os);
	void checkfile(string);
private:
	string m_name;
	int total;
	vector<Student*> m_students;
};

