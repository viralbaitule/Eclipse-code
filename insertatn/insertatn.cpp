/*
 * insertatn.cpp
 *
 *  Created on: Dec 24, 2015
 *      Author: viral
 */
#include "iostream"
using namespace std;

struct node
	{
		int data;
		node* next;
	};

struct node* head;

int insert(int x,int p)
{
	node *temp = new node();
	temp->data=x;
	temp->next=NULL;
	node *current=head;

	if (head==NULL||p==1)
	{
		temp->next=head;
		head=temp;
		return 0;
	}
	for(int i=0;i<p-2;i++)
	{
		current=current->next;
	}
	temp->next=current->next;
	current->next=temp;
	return 0;
}

int print()
{
	node * temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	return 0;
}

int main()
{
	head =NULL;
	int n,x,p;
	cout<<"enter the no. of nodes in list";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<endl<<"enter the no.";
		cin>>x;
		cout<<endl<<"enter the position";
		cin>>p;
		insert(x,p);
	}
	print();
	return 0;
}


