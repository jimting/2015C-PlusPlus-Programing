#include <iostream>
#include <fstream>
#include <iomanip>
#include <assert.h>
#include "main.h"
using namespace std;

void readFile(int *slot,int *dataSize,struct line **data)
{	
	int i;
	int temp;
	char filename[100];
	struct line *s ;
	struct line *w ;
	cout << "Input the file name: ";
	cin >> filename;
	cout << "====================³o¬OÅªÀÉ==================\n";
	ifstream fp(filename);
	assert(fp != 0);
	fp >> *slot;
	cout << "Slot : " <<*slot <<"\n";	
	fp.ignore(80, '\n');
	fp >> *dataSize;
	cout << "Edge : " << *dataSize << "\n";
	fp.ignore(80, '\n');
	for (i=0; i<*dataSize; i++){		
		struct line *q = (struct line*)malloc(sizeof(line));
		q->next = NULL;
		struct line *k = (struct line*)malloc(sizeof(line));
		k->next = NULL;
		fp >> temp;
		fp >> q->to;
		k->to = temp;
		fp >> q->distance;
		k->distance = q->distance;
		fp.ignore(80, '\n');
		s = data[temp];
		w = data[q->to];
		if(s != NULL){
			while(s->next != NULL)
				s = s->next;
			s->next = q;
		}
		else
		{
			data[temp] = q ;
		}
		if(w != NULL){
			while(w->next != NULL)
				w = w->next;
			w->next = k;
		}
		else
		{
			data[q->to] = k ;
		}
		
	}
}

void printArray(line **data, int size)
{
	cout << "  L  R  D\n";
	//cout << setw(2) << data[2]->to << setw(2) << data[2]->next->to  << setw(2) << data[2]->next->next->to <<"\n";
	for (int i = 0; i < size; i++) 
	{
		struct line *t = data[i];
		if(t != NULL)
		{
			cout << setw(3) << i << setw(3) << t->to << setw(3) << t->distance <<"\n";
			t = t->next;
			while(t != NULL)
			{
				cout << setw(3) << i << setw(3) << t->to << setw(3) << t->distance <<"\n";
				t = t->next;
			}
		}
	}
	cout << "====================ÅªÀÉµ²§ô==================\n";
}
