/*
 * deletenlinkedlist.cpp
 *
 *  Created on: Dec 26, 2015
 *      Author: viral
 */
#include"iostream"
using namespace std;

struct node
{
	int data;
	node* next;
};
node * head;
int insert(int x)
{
	node * mynode= new node();
	mynode->data=x;
	mynode->next=head;
	head=mynode;
	return 0;
}

int deleten(int p)
{
	node * temp=head;
	if(p==1)
	{
		head=temp->next;
		delete(temp);
		return 0;
	}
	for (int i=0;i<p-2;i++)
	{
		temp=temp->next;
	}
	node * temp2=temp->next;
	temp->next=temp2->next;
	delete(temp2);
	delete(temp);
	return 0;
}

int print()
{
	node * temp= head;
	while(temp!=NULL)
	{
		cout<<temp->data;
		temp=temp->next;
	}
	return 0;
}

int main()
{
	int n,x,p,choice;
	head=NULL;
	cout<<"enter the no. of elements in linked list";
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cout<<"enter the no.";
		cin>>x;
		insert(x);
	}
	cout<<"linkedlist= ";
	print();
	cout<<endl<<"enter '1' to delete another no. or enter '0' to exit "<<endl;
	cin>>choice;
	while(choice==1)
	{
		cout<<"enter the position of element to delete";
		cin>>p;
		deleten(p);
		cout<<"linked list after deleting the element at postion "<<p<<" = ";
		print();
		cout<<endl<<"enter '1' to delete another no. or enter '0' to exit ";
		cin>>choice;
	}
	return 0;
}



