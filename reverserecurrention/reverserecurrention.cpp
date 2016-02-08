/*
 * reverserecurrention.cpp
 *
 *  Created on: Dec 25, 2015
 *      Author: viral
 */

#include "iostream"
using namespace std;


struct node
{
	int data;
	node * next;
};
struct node* head;

int insert(int x)
{
	node * mynode=new node();
	mynode->data=x;
	mynode->next=head;
	head=mynode;
	return 0;
}

int reverse(node* temp)
{
	if(temp->next==NULL)
	{
		head=temp;
		return 0;
	}
	reverse(temp->next);
	node * temp1=temp->next;
	temp1->next=temp;
	temp->next=NULL;
	return 0;
}

int print()
{
	node* temp2= head;
	while(temp2!=NULL)
	{
		cout<<temp2->data;
		temp2=temp2->next;
	}
	return 0;
}

int main()
{
	int n,x;
	cout<<"enter the no. in list=";
	cin>>n;
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"enter the number=";
		cin>>x;
		insert(x);
		cout<<endl;
	}
	cout<<"Linklist in order=";
	print();
	cout<<endl;
	node * temp=head;
	reverse(temp);
	cout<<"Linked list in reverse order";
	print();
	return 0;
}
