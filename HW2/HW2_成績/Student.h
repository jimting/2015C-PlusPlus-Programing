#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "Grade.h"
#include <string>
using namespace std;

class Student
{
public:
	Student(string,string);
	Student(ifstream &infile);
	~Student(void);
	void addgrade();
	void print(std::ostream &os);
	bool checkname(string);
	void changegrade();
	void saveall(std::ostream &os);
	string getname();
	int returngradetotal();
private:
	string m_name;
	vector<Grade*> m_grades;
	string studentnumber;
	int gradetotal;
};

