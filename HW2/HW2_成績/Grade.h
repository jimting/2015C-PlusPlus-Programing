#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Grade
{
public:
	Grade();
	Grade(ifstream &infile);
	~Grade(void);
	void print(std::ostream &os);
	int returngrade();
	void changegrade();
private:
	int m_grade;
};

