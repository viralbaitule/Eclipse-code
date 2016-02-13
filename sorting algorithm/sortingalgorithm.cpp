/*
 * sortingalgorithm.cpp
 *
 *  Created on: Feb 10, 2016
 *      Author: Viral
 */
#include "iostream"
#include "vector"
#include "string"
#include "stdlib.h"
using namespace std;



int insertionsort(string &a,int &n)
{
	int hole;
	int value;
	for(int i=1;i<n;i++)
	{
		hole=i;
		value=a[i];
		while(hole>0&&value<a[hole-1])
		{
			a[hole]=a[hole-1];
			hole=hole-1;
		}
		a[hole]=value;
	}
	return 0;
}

int selectionsort(string &a,int &n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j]<a[min])
			{
				int temp;
				temp=a[j];
				a[j]=a[min];
				a[min]=temp;
			}
		}
	}
	return 0;
}

int bubblesort(string &a,int &n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				int temp;
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}

	return 0;
}

int main()
{
	int i,n,num;
	int choice;
	string a="4312";
//	cout<<"enter the string";
	//cin>>a;
	cout<<endl;
	cout<<"original list: "<<a<<endl;
	n=a.length();
	cout<<"n="<<n<<endl;

	while(1)
	{
		cout<<"1:insertion sort"<<endl<<"2:selection sort"<<endl;
		cout<<"3:Bubble sort"<<endl;
		cout<<"8:print"<<endl<<"9:exit"<<endl;
		cout<<"enter the choice of algorithm"<<endl;
		cin>>choice;
	switch(choice)
	{
	case 1:
	{
		insertionsort(a,n);
		break;
	}
	case 2:
	{
		selectionsort(a,n);
		break;
	}
	case 3:
	{
		bubblesort(a,n);
		break;
	}
	case 8:
	{
		for(i=0;i<n;i++)
			{
				cout<<a[i];
			}
		cout<<endl;
		break;
	}
	case 9:
		return 0;
		break;

	default:
		cout<<"invalid choice"<<endl;

	}
	}

	cout<<"a="<<a;

	return 0;
}
