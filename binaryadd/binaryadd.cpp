/*
 * binaryadd.cpp
 *
 *  Created on: Oct 30, 2015
 *      Author: viral
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	string s="0100";
	std::string bits("10101011110");
	//std::vector<bool> myVec;
	int i = -5; // or whatever
	unsigned int j;
	j=i;
	cout<<j;


	for(int h=0;h<=ini_vect2.size();h++)
				{
					if(ini_vect2[h]=='0')
						ini_vect3[h]='1';
					else if(ini_vect2[h]=='1')
						ini_vect3[h]='0';
				}
				for(int i=k;i>=0;i--)
				{
				   	int l= (ini_vect3[i]+ini_vect4[i]+carry);
				   	if (l==96)
				   	{
				   		ini_vect3[i]='0';
			    		carry=0;
			    	}
			    	if (l==97)
			    	{
			    		ini_vect3[i]='1';
			    		carry=0;
			    	}
			    	if (l==98)
			    	{
			    		ini_vect3[i]='0';
			    		carry=1;
			    	}
			    	if (l>98)
			    	{
			    		ini_vect3[i]='1';
			    		carry=1;
			    	}
				}
			}
			for(int m=0;m<ini_vect3.size();m++)
					{
						//cout<<ini_vect3[m];
					}//cout<<endl;
	return 0;
}



