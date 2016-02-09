/*
 * BinarySearchTree.cpp
 *
 *  Created on: Feb 8, 2016
 *      Author: Viral
 */
#include "iostream"
#include "string"
using namespace std;

struct node
{
	int data;
	node *left;
	node *right;
};

node* insert(node* root,int num)
{
	if (root==NULL)
	{
		node* leaf= new node();
		leaf->data=num;
		leaf->left=NULL;
		leaf->right=NULL;
		root=leaf;
	}
	else if(num<=root->data)
	{
		root->left=insert(root->left,num);
	}
	else
	{
		root->right=insert(root->right,num);
	}
	return root;
}

node* search(node* root,int n)
{
	if (root==NULL)
	{
		cout<<"no. not found "<<endl;
	}
	else if (root->data==n)
	{
		cout<<"number found at address"<<root<<endl;
		return root;
	}
	else if(n<=root->data)
	{
		return search(root->left,n);
	}
	else
	{
		return search(root->right,n);
	}
	return root;
}

int findmin(node *root)
{
	node* current=root;
	if(root==NULL)
	{
		cout<<"error: tree is empty";
		return -1;
	}
	while(current->left!=NULL)
	{
		current=current->left;
	}
	cout<<"min no in list="<<current->data<<endl;
	return 0;
}
int findmax(node *root)
{
	node* current=root;
	if(root==NULL)
		{
			cout<<"error: tree is empty";
			return -1;
		}
	while(current->right!=NULL)
		{
			current=current->right;
		}
		cout<<"max no in list="<<current->data<<endl;
	return 0;
}

void preorder(node *root)
{
	if(root==NULL)
		return ;
	cout<<root->data;
	preorder(root->left);
	preorder(root->right);
}

void postorder(node *root)
{
	if (root==NULL)
		return ;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data;
}

void inorder(node *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	cout<<root->data;
	inorder(root->right);
}


int main()
{
	struct node *root=NULL;
	int choice;
	int num;
	int n;
	while(1)
	{
		cout<<"enter the no. for the required operation"<<endl;
		cout<<"1:insert a no.:"<<endl<<"2:Search a No."<<endl<<"3:find minimum no.";
		cout<<endl<<"4:find maximum no."<<endl<<"5:Pre-order traversal";
		cout<<endl<<"6:post-order traversal"<<endl<<"7:In-order traversal"<<endl;
		cout<<"8:Delete the no."<<endl<<"9:exit"<<endl;
		cin>>choice;

		switch(choice)
		{
		case 1:
		{
			cout<<"enter the no.";
			cin>>num;
			root=insert(root,num);
			break;
		}
		case 2:
		{
			cout<<"enter the no. to be search:";
			cin>>n;
			search(root,n);
			break;
		}
		case 3:
		{
			findmin(root);
			break;
		}
		case 4:
		{
			findmax(root);
			break;
		}
		case 5:
		{
			preorder(root);
			break;
		}
		case 6:
		{
			postorder(root);
			break;
		}
		case 7:
		{
			inorder(root);
			break;
		}
		case 8:
		{
			break;
		}
		case 9:
		{
			return 0;
		}
		default:
			cout<<"invalid input no.";
			break;
		}
	}

	return 0;

}


