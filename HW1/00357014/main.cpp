//Prim 第一次的作業

#include <iostream>
#include <iomanip>
#include "io.h"
#include "main.h"
#include "Prim.h"
using namespace std;


int main()
{	
	struct line **data = new line*[100];
	for(int x = 0; x < 100 ; x++)
		data[x] = NULL;
	int slot;
	int edge;
	readFile(&slot,&edge,data);
	printArray(data,edge);
	int matrix[30];
	Prim(slot,edge,data);	
	return 0;
}
