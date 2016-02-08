/*
 * postfixcalculator.cpp
 *
 *  Created on: Dec 2, 2015
 *      Author: viral
 */

#include <iostream>
#include <string>
#include <unistd.h>
#include <stack>
#include <stdlib.h>
using namespace std;

int main(int argc,char **argv)
{
	char c;
	string input;
	string ch;
	stack<int>mystack;
	long int len,numb,opr1=0,opr2=0,ans;
	while ((c = getopt (argc, argv, "e:")) != -1)
		{
		switch (c)
		{
		case 'e':
		{
			input=optarg;
			break;
		}
		case '?':
		{
			if (optopt == 'e')
                	{cerr<<"Requires an argument after -"<<char(optopt)<<endl;}
			else if(isprint (optopt))
        	        {cerr<< "Unknown option -"<<char(optopt)<<endl;}
			return -1;
		}
        default:
            abort ();
		}
		}
	len=input.size();
	for(int i=0;i<len;i++)
	{
		if(input[i]==',')
		{
			i=i+1;
		}
		if(input[i]==' ')
		{
			i=i+1;
		}
		if(!(input[i]=='+'||input[i]=='-'||input[i]=='*'||input[i]=='/'))
		{
			int k=0;
			for(int j=i;((input[j]!=','));j++)
			{
				ch[k]=input[j];
				k++;
			}
			if(k>0)
			{
				i=i+k-1;
			}
			numb=atol(ch.c_str());
			mystack.push(numb);
			ch='\0';
			k=0;

		}
		else if (input[i]=='+')
		{
			 opr1 = mystack.top();
			 mystack.pop();
			 opr2 = mystack.top();
			 mystack.pop();
			 ans=opr1+opr2;
			 mystack.push(ans);
		}
		else if (input[i]=='-')
		{
			 opr1 = mystack.top();
			 mystack.pop();
			 opr2 = mystack.top();
			 mystack.pop();
			 ans=opr2-opr1;
			 mystack.push(ans);
		}
		else if (input[i]=='*')
		{
			 opr1 = mystack.top();
			 mystack.pop();
			 opr2 = mystack.top();
			 mystack.pop();
			 ans=opr2*opr1;
			 mystack.push(ans);
		}
		else if (input[i]=='/')
		{
			 opr1 = mystack.top();
			 mystack.pop();
			 opr2 = mystack.top();
			 mystack.pop();
			 ans=opr2/opr1;
			 mystack.push(ans);
		}
	}
	cout<<ans;
	return 0;
}


