/*
 * getfun.cpp
 *
 *  Created on: Oct 9, 2015
 *      Author: viral
 */

#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;

int main()
{
	//char next;
	char net_symbol;
	ofstream out;

	do{
		out.open("test1.txt",ios::app);
		cin.get(net_symbol);
		cout<<net_symbol;
		out<<net_symbol;
		out.close();
	}while(net_symbol!='\n');


}


