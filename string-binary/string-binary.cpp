#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <bitset>
#include <algorithm>
#include <math.h>
using namespace std;

class shift
{
	public:
	int shift_left(vector<char>& ,int&, int&);
	int shift_right(vector<char>& ,int&,int&);
	int resize_vector(vector<char>& , int& ,int& );
	int addit(vector<char>&,vector<char>&,vector<char>&);
	int twoscomplement(vector<char>&,vector<char>&);
	//int shift_call(vector<char>& ,int&,int&,int&,int&,int&,int&,int&);
	int Print(vector<char>& ,int&);
	~shift();
};

int shift::shift_left(vector<char>&ini_vect, int &left, int &vacant)
{
	int value;
	value=ini_vect.size()-left;
	ini_vect.erase(ini_vect.begin(),ini_vect.begin()+left);
	if(vacant==1)
	{
		ini_vect.insert(ini_vect.begin()+value,left,'1');
	}
	else
	{
		ini_vect.insert(ini_vect.begin()+value,left,'0');
	}
	return 0;
}
int shift::shift_right(vector<char>&ini_vect, int &right,int &vacant)
{
	int size;
	size=ini_vect.size()-right;
	ini_vect.erase(ini_vect.begin()+size,ini_vect.end());
	if(vacant==1)
	{
		ini_vect.insert(ini_vect.begin(),right,'1');
	}
	else
	{
		ini_vect.insert(ini_vect.begin(),right,'0');
	}
	return 0;
}


int shift::resize_vector(vector<char>& ini_vect, int& sflag,int& numb)
{
	if(sflag==1)
	{
		if (numb > ini_vect.size())
		{
			int difference= numb - ini_vect.size();
			ini_vect.insert(ini_vect.begin(), difference, '0');
		}
		else
		{
			ini_vect.resize(numb);
		}
	}
	return 0;
}

int shift::addit(vector<char>&ini_vect1,vector<char>&ini_vect3,vector<char>&result)
{
	vector<char>temp;
	vector<char>temp2;
	int size1=ini_vect1.size();
	int size2=ini_vect3.size();
	//cout<<size1<<endl<<size2;
	int j;
	int sflag1=1;
	int pflag1=1;
	if (size1>size2){
		temp=ini_vect3;
		temp2=ini_vect1;
		j=size1;}
	else{
	//	cout<<"i am";
		temp=ini_vect1;
		temp2=ini_vect3;
		j=size2;}

	resize_vector(temp,sflag1,j);
	resize_vector(temp2,sflag1,j);
	Print(temp,pflag1);
	Print(temp2,pflag1);
	cout<<endl;
	int carry=0;
	for(int i=j;i>=0;i--)
		{
			int l= (temp2[i]+temp[i]+carry);
			if (l==96)
	    	{
	    		carry=0;
	    		result.push_back('0');
	    	}
	    	if (l==97)
	    	{
	    		carry=0;
	    		result.push_back('1');
	    	}
	    	if (l==98)
	    	{
	    		carry=1;
	    		result.push_back('0');
	    	}
	    	if (l>98)
	    	{
	    		carry=1;
	    		result.push_back('1');
	    	}
	   }
			reverse(result.begin(),result.end());
			//Print(result,pflag1);
				//cout<<endl;
		return 0;
}
int shift::twoscomplement(vector<char>&ini_vect2,vector<char>&ini_vect3)
{
			int sflag1=1;
			vector<char>ini_vect4(0);
			int k=ini_vect2.size();
			//cout<<"temp1";
			resize_vector(ini_vect4,sflag1,k);
			ini_vect4.pop_back();
			ini_vect4.insert(ini_vect4.end(),'1');
			//sh.Print(ini_vect4,pflag1);
			int carry=0;
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

		//	for(int m=0;m<ini_vect3.size();m++)
					//{
						//cout<<ini_vect3[m];
				//	}//cout<<endl;
return 0;
}

int shift::Print(vector<char>&ini_vect, int &pflag)
{
	if(pflag==1)
	{
		for(int m=0;m<ini_vect.size();m++)
		{
			cout<<ini_vect[m];
		}
	}cout<<endl;
	return 0;
}

shift::~shift() {
}

int main (int argc, char **argv)
{
	int numb1=0,right1,left1,vacant=0,numb2=0,right2,left2,numb3=0,numb4=0;
	int lflag1,rflag1,sflag1,pflag1=0,lflag2,rflag2,sflag2,dflag=0,hflag=0,oflag=0;
	string initialvalue1,binary_string1,initialvalue2,binary_string2,operator_sign;
	int index,temp;
	int sizei;
	int numb11=0;
	char found;
	char c;
	int rpos1,lpos1,rpos2,lpos2;
	 opterr = 0;
	 string bin1;
	 	 char holder1=' ';
	 	 string bin;
	 	 char holder=' ';
if(argc<1){
cout<<"More arguments are required"<<endl;
return -1;
}
else{
	while ((c = getopt (argc, argv, "i:s:l:r:v:I:S:R:L:o:pdh")) != -1)
	{
        switch (c)
        	{
		case 'i':{
			initialvalue1=optarg;//object creation
			numb1=atoi(optarg);
			//numb1=abs(numb1);
			sizei=initialvalue1.size();
			cout<<numb1<<endl;
			cout<<"sizei="<<numb11<<endl;
			if(initialvalue1[(sizei-1)]=='D'){
			//cout<<"numb1="<<found<<endl;

			while(numb1!=0)
			{
			   holder=numb1%2+'0';
			   bin=holder+bin;
			   numb1/=2;
			}
			}
			else
				bin=initialvalue1;
			break;}
		case 's':{
			sflag1=1;
			numb3=atoi(optarg);
			break;}
		case 'r':{
			rflag1=1;
			rpos1=optind;
			rpos1=rpos1-1;
			right1=atoi(optarg);
			break;}
		case 'l':{
			lflag1=1;
			lpos1=optind;
			lpos1=lpos1-1;
			left1=atoi(optarg);
			break;}
		case 'I':{
			initialvalue2=optarg;//object creation
			numb2=atoi(optarg);
			if(initialvalue2.find('D')==1){
			while(numb2!=0)
			{
			    holder1=numb2%2+'0';
			    bin1=holder1+bin1;
			    numb2/=2;
			}
			}
			else
				bin1=initialvalue2;
			//			cout<<"string1="<<bin1<<endl;
			//binary_string2=bitset<4>(numb2).to_string();
			//cout<<"binary_string2="<<binary_string2<<endl;
			break;}
		case 'S':{
			sflag2=1;
			numb4=atoi(optarg);
			break;}
		case 'R':{
			rflag2=1;
			rpos2=optind;
			rpos2=rpos2-1;
			right2=atoi(optarg);
			break;}
		case 'L':{
			lflag2=1;
			lpos2=optind;
			lpos2=lpos2-1;
			left2=atoi(optarg);
			break;}
		case 'v':{
			temp=atoi(optarg);
			if (temp==1)
			vacant=1;
			else
			vacant=0;
			break;}
		case 'o':{
			oflag=1;
			operator_sign=optarg;
			//cout<<operator_sign<<endl;
			break;}
		case 'p':{
			pflag1=1;
			break;}
		case 'd':{
			dflag=1;
			break;}
		case 'h':{
			hflag=1;
			break;}
		case '?':{
			if (optopt == 'i'|| optopt == 's'||optopt == 'r'|| optopt == 'l'||optopt == 'v'||optopt=='p')
                	{cerr<<"Requires an argument after -"<<char(optopt)<<endl;}
			else if(isprint (optopt))
        	        {cerr<< "Unknown option -"<<char(optopt)<<endl;}
			return -1;}
        	default:
            	abort ();
		}
	}

	for (index = optind; index < argc; index++)
	{
		cout<<"Invalid argument "<< argv[index]<<endl;
		return -1;
	}
	shift sh;

	vector<char>ini_vect1(bin.begin(),bin.end());
	vector<char>ini_vect2(bin1.begin(),bin1.end());

	sh.resize_vector(ini_vect1,sflag1,numb3);
	sh.resize_vector(ini_vect2,sflag2,numb4);

	if (lpos1<rpos1)
			{
				if(lflag1==1)
					sh.shift_left(ini_vect1,left1,vacant);
				if(rflag1==1)
					sh.shift_right(ini_vect1,right1,vacant);
			}
			else if(rpos1<lpos1)
			{
				if(rflag1==1)
		        	sh.shift_right(ini_vect1,right1,vacant);
				if(lflag1==1)
	       			sh.shift_left(ini_vect1,left1,vacant);
			}
	if (lpos2<rpos2)
			{
				if(lflag2==1)
					sh.shift_left(ini_vect2,left2,vacant);
				if(rflag2==1)
					sh.shift_right(ini_vect2,right2,vacant);
			}
			else if(rpos2<lpos2)
			{
				if(rflag2==1)
		        	sh.shift_right(ini_vect2,right2,vacant);
				if(lflag2==1)
	       			sh.shift_left(ini_vect2,left2,vacant);
			}
		//string res;
		vector<char>ini_vect3;
		vector<char>result;
		//string ini_vect41="0001";
		//vector<char>ini_vect4(ini_vect41.begin(),ini_vect41.end());
//		vector<char>ini_vect4(0);
//		int k=ini_vect2.size();
//		//cout<<"temp1";
//		sh.resize_vector(ini_vect4,sflag1,k);
//		ini_vect4.pop_back();
//		ini_vect4.insert(ini_vect4.end(),'1');
//		//sh.Print(ini_vect4,pflag1);
//		int carry=0;
		//ini_vect3=ini_vect2;
		ini_vect3=ini_vect2;
		if(oflag==1)
		{
		if(operator_sign=="-")
		{
			sh.twoscomplement(ini_vect2,ini_vect3);
//			for(int h=0;h<=ini_vect2.size();h++)
//			{
//				if(ini_vect2[h]=='0')
//					ini_vect3[h]='1';
//				else if(ini_vect2[h]=='1')
//					ini_vect3[h]='0';
//			}
//			for(int i=k;i>=0;i--)
//			{
//			   	int l= (ini_vect3[i]+ini_vect4[i]+carry);
//			   	if (l==96)
//			   	{
//			   		ini_vect3[i]='0';
//		    		carry=0;
//		    	}
//		    	if (l==97)
//		    	{
//		    		ini_vect3[i]='1';
//		    		carry=0;
//		    	}
//		    	if (l==98)
//		    	{
//		    		ini_vect3[i]='0';
//		    		carry=1;
//		    	}
//		    	if (l>98)
//		    	{
//		    		ini_vect3[i]='1';
//		    		carry=1;
//		    	}
//			}
	}
//		for(int m=0;m<ini_vect3.size();m++)
//				{
//					//cout<<ini_vect3[m];
//				}//cout<<endl;
		sh.addit(ini_vect1,ini_vect3,result);
		}
  sh.Print(ini_vect1,pflag1);
  sh.Print(ini_vect2,pflag1);

  string str(result.begin(), result.end());
  int i2 = strtoull (str.c_str (),NULL,2);
  if(pflag1==1)
  {
	  if (dflag==1)
	  {
		  cout<<"Result in decimal="<<i2<<endl;
	  }
	  else if(hflag==1)
	  {
		  cout<<"Result in hexadecimal= 0x"<<hex<<i2<<endl;
	  }
	  else
		  cout<<"result=";
		  sh.Print(result,pflag1);
  }
	return 0;
}
}

