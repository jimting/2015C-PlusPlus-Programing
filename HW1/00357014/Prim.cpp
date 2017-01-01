#include <iostream>
#include <iomanip>
#include "main.h"
using namespace std;

void Prim(int slot,int edge,line **data){
	struct h{
		int check;
		int distance;
		int parent;
	}h[30];
	int MST[30] = {NULL};
	int x = 0,i = 0,g;
	int distancesum = 0;
	cout << "�аݷQ�q���I�}�l�G\n";
	cin >> x;
	cout << "�q" << setw(2) << x << "�}�l\n";
	for(int t = 0; t < slot; t++){
		h[t].check = 0;
		h[t].distance = 999;
	}
	h[x].check = 1;
	h[x].distance = 0;
	h[x].parent = 0;
	for(int k = 0; k < slot; k ++){
		int temp1=999,temp2,temp3;
		struct line* p = data[x];
		while(p != NULL){
			if(h[p->to].distance > p->distance && h[p->to].check == 0){
				cout << p->to <<"���ק�\n";
				cout << "�쥻distance " << h[p->to].distance <<" �ܦ�" <<  p->distance << "\n";
				h[p->to].distance = p->distance;
				cout << "�쥻parent " << h[p->to].parent  <<" �ܦ�" <<  x << "\n";
				h[p->to].parent = x;
			}
			p = p->next;
		}
		free(p);
		for(g = 0; g < slot; g++){
			if(h[g].check == 0)
				if(temp1 > h[g].distance){
					temp1 = h[g].distance;
					temp2 = h[g].parent;
					temp3 = g;
				}
		}
		h[temp3].check = 1;
		if(h[x].distance != 0){
		cout << "���̵u���|���U�G\n";
		cout << "  V  M  P\n";
		cout << setw(3) << x << setw(3) << h[x].distance << setw(3) << h[x].parent <<"\n";
		}
		distancesum += h[x].distance;
		MST[k] = x;
		x = temp3;
	}
	cout << "MST�G";
	for(int i = 0 ; i < slot ; i++)
		cout << setw(3) << MST[i];
	cout << "\n";
	cout << "�`���סG" << distancesum <<"\n" ;
}