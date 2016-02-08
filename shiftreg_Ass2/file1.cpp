#include <iostream>
#include <string>
using namespace std;

int main ()
{
  string s1={001010};
  string s2;
  for (int i=0;i<s1.size();i++)
  {
	  if(s1[i]=='0')
		 s2[i]= 0;
	  else if (s1[i]=='1')
		  s2[i]=1;
  }

  std::cout << s2 << '\n';

  return 0;
}
