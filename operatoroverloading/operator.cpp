/*
 * operator.cpp
 *
 *  Created on: Nov 17, 2015
 *      Author: viral
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class vect
{
	int sub1,sub2;
public:
	int t1,t2;
	void setdata()
	{
		sub1=t1;
		sub2=t2;
	}
	void getdata()
	{
		cout<<"enter 1st value=";
		//cin>>t1;
		t1=3; t2=5;
		cout<<endl<<"enter 2nd value=";
		//cin>>t2;

	}
	void display()
	{
		cout<<sub1<<"\n"<<sub2<<"\n";
	}

	friend vect operator +(vect& parameter1, vect& parameter2);

};

vect operator +(vect& parameter1,vect& parameter2)
	{
		vect temp;
		temp.t1=parameter1.t1+parameter2.t2;
		cout<<endl;
		cout<<temp.t1;
		return temp;
	}

int main()
{
	vect obj1,obj2;
	//int a,b;
	obj1.getdata();
	//cout<<a<<b;
	cout<<endl;
	obj1+obj2;
	obj1.setdata();
//	obj1.display();
//
	//++obj1;
	//obj1.display();
}

