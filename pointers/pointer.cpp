/*
 * pointer.cpp
 *
 *  Created on: Feb 5, 2016
 *      Author: Viral
 */
#include <iostream>
using namespace std;


int add(int *a)
{
	int res=0;
	for(int i=0;i<5;i++)
	{
		res=res+a[i];
	}

	return res;
}


int main()
{
	int res=0;
	int a[5]={1,2,3,4,5};
	//int *p =a;
	res=add(a);
	cout<<"output in main=";
	cout<<res;
	return 0;
}