/* Baitule, Viral
SID- 010710960*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <sstream>
#include <bitset>
#include <algorithm>
using namespace std;

class shift
{
	public:
	int shift_left(vector<char>& ,int&, int&);
	int shift_right(vector<char>& ,int&,int&);
	int resize_vector(vector<char>& , int& ,int& ,int& );
	int addit(vector<char>&,vector<char>&,vector<char>&);
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


int shift::resize_vector(vector<char>& ini_vect, int& sflag,int& numb,int& vacant)
{
	if(sflag==1)
	{
		if (numb > ini_vect.size())
		{
			int difference= numb - ini_vect.size();
			if (vacant==1)
			{
				ini_vect.insert(ini_vect.begin(), difference, '1');
			}
			else
			{
				ini_vect.insert(ini_vect.begin(), difference, '0');
			}
		}
		else
		{
			ini_vect.resize(numb);
		}
	}
	return 0;
}

int shift::addit(vector<char>&ini,vector<char>&ini2,vector<char>&result)
{
	vector<char>temp;
	vector<char>temp2;
	int size1=ini.size();
	int size2=ini2.size();
	int j;
	int vacant=0;
	int sflag1=1;
	int pflag1=1;
	if (size1>size2){
		temp=ini;
		temp2=ini2;
		j=size1;}
	else{
		temp=ini;
		temp2=ini2;
		j=size2;}

	resize_vector(temp,sflag1,j,vacant);
	resize_vector(temp2,sflag1,j,vacant);
	int carry=0;
	for(int i=(j-1);i>=0;i--)
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
			resize_vector(result,sflag1,j,vacant);
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
	}
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
	int sizei,sizeI;
	char c;
	int negbit=0,negbit1=0,Dflag1,Dflag;
	int rpos1,lpos1,rpos2,lpos2;
	shift sh;
	 opterr = 0;
	 string bin1;
	 	 char holder1=' ';
	 	 string bin;
	 	 char holder=' ';
if(argc<2){
cout<<"More arguments are required"<<endl;
return -1;
}
else{
	while ((c = getopt (argc, argv, "i:s:l:r:v:I:R:L:o:pdh")) != -1)
	{
        switch (c)
        	{
		case 'i':{
			initialvalue1=optarg;//object creation
			numb1=atoi(optarg);
			if(numb1<0)
				negbit=1;
			sizei=initialvalue1.size()-1;
			if(initialvalue1[sizei]=='D'){
				Dflag=1;
				if(numb1<15 && numb1>-15){
				bin = bitset<4>(numb1).to_string();}
				else if((numb1>15 && numb1<256) || (numb1<-15&&numb1>-255)){
				bin = bitset<8>(numb1).to_string();}
				else if((numb1>255 && numb1<65536) || (numb1<-255&&numb1>-65536)){
				bin = bitset<16>(numb1).to_string();}
				else if((numb1>65536 && numb1<4294967296) || (numb1<-65536&&numb1>-4294967296)){
				bin = bitset<32>(numb1).to_string();}
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
			if(numb2<0)
				negbit=1;
			sizeI=initialvalue2.size()-1;
			if(initialvalue2[sizeI]=='D'){
				Dflag1=1;
				if(numb2<15 && numb2>-15){
				bin1 = bitset<4>(numb2).to_string();}
				else if((numb2>15 && numb2<256) || (numb2<-15&&numb2>-255)){
				bin1 = bitset<8>(numb2).to_string();}
				else if((numb2>255 && numb2<65536) || (numb2<-255&&numb2>-65536)){
				bin1 = bitset<16>(numb2).to_string();}
				else if((numb2>65536 && numb2<4294967296) || (numb2<-65536&&numb2>-4294967296)){
				bin1 = bitset<32>(numb2).to_string();}
			}
			else
				bin1=initialvalue2;
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
			if (optopt == 'i'|| optopt == 's'||optopt == 'r'|| optopt == 'l'||optopt == 'v'||optopt == 'I'||optopt == 'R'|| optopt == 'L'||optopt=='p')
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

	numb4=numb3*2;
	vector<char>ini_vect1(bin.begin(),bin.end());
	vector<char>ini_vect2(bin1.begin(),bin1.end());
	if(negbit==0&&Dflag==1)
	{
		ini_vect1.insert(ini_vect1.begin(),'0');
	}
	if(negbit1==0&&numb3>4&&Dflag1==1)
	{
		ini_vect2.insert(ini_vect2.begin(),'0');
	}
	if(ini_vect1[0]=='1')
	{
		int vacant1=1;
		sh.resize_vector(ini_vect1,sflag1,numb4,vacant1);
	}
	else
	{
		sh.resize_vector(ini_vect1,sflag1,numb4,vacant);
	}
	if(ini_vect2[0]=='1')
	{
		int vacant1=1;
		sh.resize_vector(ini_vect2,sflag1,numb3,vacant1);
	}
	else
	{
		sh.resize_vector(ini_vect2,sflag1,numb3,vacant);
	}

//	sh.Print(ini_vect1,pflag1);
//	cout<<endl;
//	sh.Print(ini_vect2,pflag1);
//	cout<<endl;

		vector<char>result(0);
		sh.resize_vector(result,sflag1,numb4,vacant);
		if(operator_sign=="x")
				{
					if(operator_sign=="x")
					{
						int shift=1;
						for( int j=ini_vect2.size()-1;j>=0;j-- )
						{
							int i=ini_vect2.size()-1;
						    if(ini_vect2[i]=='1')
						    {
						    	sh.addit(result,ini_vect1,result);
						    }
						    sh.shift_left(ini_vect1,shift,vacant);
						    sh.shift_right(ini_vect2,shift,vacant);
						}
					}
				}


  string str(result.begin(), result.end());
  int i2 = strtoull (str.c_str (),NULL,2);
  if(pflag1==1)
  {
	  if (dflag==1)
	  {
		sh.Print(result,pflag1);
	  	cout<<"("<<i2<<")"<<endl;
	  }
	  else if(hflag==1)
	  {	  sh.Print(result,pflag1);
		  cout<<"(0x"<<hex<<i2<<")"<<endl;
	  }
	  else{
		  sh.Print(result,pflag1);
		cout<<endl;}
  }
	return 0;
}
}

