/*
 * lreverse.cpp
 *
 *  Created on: Dec 21, 2015
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
int insert(int x)
{
	node * temp =new node();
	temp->data=x;
	temp->next=NULL;
	temp->next=head;
	head=temp;
	return 0;
}

int reverse()
{
	node * current=head;
	node * prev= NULL;
	node * next;
	while(current != NULL)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
	}
	head=prev;
	return 0;
}

int print()
{
	node *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	return 0;
}


int main()
{
	int x,n;
	head=NULL;
	cout<<"enter the no. of nodes";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the value";
		cin>>x;
		insert(x);
	}
	cout<<"original list=";
	print();
	reverse();
	cout<<endl;
	cout<<"reverse list=";
	print();

}

