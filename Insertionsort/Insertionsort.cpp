/*
 * Insertionsort.cpp
 *
 *  Created on: Jan 6, 2016
 *      Author: viral
 */
#include"iostream"
#include"vector"
using namespace std;

int insertionsort(vector<int>&a,int &n)
{
	for(int j=1;j<n;j++)
	{
		cout<<"here";
		int i=j;
		if (a[i]<a[i-1])
		{
			while(i)
			{
				int temp=a[i];
				a[i]=a[i-1];
				a[i-1]=temp;
				i--;
				cout<<a[i];
			}
		}
	}

	return 0;
}

int main()
{
	int i,n,num;
	vector<int>a;
	cout<<"enter the length of the list";
	cin>>n;
	cout<<endl;
	for(i=0;i<n;i++)
	{
		cout<<"enter the no.";
		cin>>num;
		a.push_back(num);
		cout<<endl;
	}
	cout<<"original list: ";
	for(i=0;i<n;i++)
	{
		cout<<a[i];
	}
	cout<<endl<<"list after insertion sort: ";
	insertionsort(a,n);
	for(i=0;i<n;i++)
	{
		cout<<a[i];
	}

}



