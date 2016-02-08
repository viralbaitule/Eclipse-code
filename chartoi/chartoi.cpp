/*
 * chartoi.cpp
 *
 *  Created on: Oct 12, 2015
 *      Author: viral
 */

#include<iostream>
#include<string>
#include<cstdlib>

using namespace std;

int main()
{
	string a;
	int array[10];
	 int index=0;
	while(a[index]== 0)
	{
		cin>>a[index];
		index++;
	}
	cout<<index;
	for (int i=0;i<=index;i++)
	{

		array[i]=atoi(&a[i]);
		cout<<array[i];

	}

	return 0;
}


