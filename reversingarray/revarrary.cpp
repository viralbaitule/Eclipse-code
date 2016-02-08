/*
 * revarrary.cpp
 *
 *  Created on: Oct 10, 2015
 *      Author: viral
 */
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	char a[10];
	int i;
	while(a[i]!='\n'){
		for (i=0;i<=10;i++)
		{
			cin>>a[i];
		}
	}
	for (i=11;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}



