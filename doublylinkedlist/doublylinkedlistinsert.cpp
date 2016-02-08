/*
 * doublylinkedlistinsert.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: viral
 */
#include "iostream"
using namespace std;

struct node
{
	int data;
	node * prev;
	node * next;
};
struct node* head;
int insert(int x)
{
	node * mynode=new node();
	mynode->data=x;
	mynode->prev=NULL;
	mynode->next=head;
	head=mynode;
	return 0;
}

int print()
{
	node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	return 0;
}

int main()
{
	int n,x;
	head=NULL;
	cout<<"how many numbers";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the number";
		cin>>x;
		insert(x);
		print();
	}
	return 0;
}
