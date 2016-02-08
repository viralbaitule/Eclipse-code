/*
 * reverse.cpp
 * reverse string and vector using pass by reference and using stack
 *  Created on: Feb 7, 2016
 *      Author: Viral
 */
#include "iostream"
#include "stack"
#include "string.h"
#include "vector"
using namespace std;

int reverse(vector<char> &k)
{

	//cout<<"to verifiy address"<<(void*)&k; //To verify address
	stack<char>s;
	int i;
	int l=k.size();
	for(i=0;i<l;i++)
	{

		s.push(k[i]);
	}
	for(i=0;i<l;i++)
	{
		k[i]=s.top();
		s.pop();
	}
return 0;
}

int main()
{
	 vector<char> k;
	// string k;
	 int len;
	// cin>>k;
	 cout<<"enter the length of string:";
	cin>>len;
	for(int i=0;i<len;i++)
	{
		char ch;
		cin>>ch;
		k.push_back(ch);
	}
	cout<<endl;
//	int l=k.size();
	cout<<"reverse string=";
	//cout<<(void*)&k;//To verify address
	reverse(k);
	for(int i=0;i<len;i++)
		{
			cout<<k[i];

		}
	//cout<<k;

	return 0;
}


