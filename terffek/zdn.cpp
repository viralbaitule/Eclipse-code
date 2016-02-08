/*
 * Name: Sourabh Ketkale
 * SUID: 010470785
 * Assignment no #2
 * Assignment Name:: Shift Register.
 *
 * **/
#include<unistd.h>
#include<iostream>
#include <vector>
#include<sstream>
#include<stdlib.h>
#include <string>
#include <bitset>
#include<cstring>
#include<iterator>
#include<algorithm>

using namespace std;

class shiftreg {

public:

	shiftreg();
	void shiftright(vector<char> &playerInfoVector, int &noofbits_reg,
			int &inject_value, int &leftshift_value, int &print_value);
	void shiftleft(vector<char> &playerInfoVector, int &noofbits_reg,
			int &inject_value, int &leftshift_value, int &print_value);
	void displayregister(vector<char> &playerInfoVector, int &pflag, int &sflag,int &Sflag, int &noofbits_reg,int &noofbits_reg1);
	vector<char> addition(vector<char> &playerInfoVector,vector<char> &playerInfoVector1);
	vector<char> subtraction(vector<char> &playerInfoVector,vector<char> &playerInfoVector1);
//	vector<int> vecstr_to_vecint(vector<char> vs);

};

shiftreg::shiftreg() {
}

int main(int argc, char **argv) {
	int iflag = 0, Iflag = 0, sflag = 0, Sflag = 0, lflag = 0, Lflag = 0,
			vflag = 0, rflag = 0, Rflag = 0, pflag = 0, dflag = 0, Oflag = 2,
			lpos, Lpos, rpos, Rpos,dflap,hflag;
	int rightshift_value, rightshift_value1, leftshift_value, leftshift_value1,
			noofbits_reg = 0, noofbits_reg1 = 0, inject_value, print_value,
			decimal_convert;
	shiftreg sr;
	string init, init1, oper;
	int test, test1;
	string token;
	int c;

	while ((c = getopt(argc, argv, "i:I:r:R:s:S:l:L:d:v:o:pdh")) != -1)
		switch (c) {
		case 'i': {
			iflag = 1;
			test1 = atoi(optarg);
			init = bitset<8>(test1).to_string();
			cout<<init<<endl;
			//cout << "\n" << init;
		}
			break;
		case 'I': {
			iflag = 1;
			test = atoi(optarg);
			init1 = bitset<8>(test).to_string();
			//cout<<"\n"<<init1;
			break;
		}
		case 's': {

			sflag = 1;
			noofbits_reg = atoi(optarg);
			//cout << "\nNumber of bits in the regsiter 1::" << noofbits_reg;
			break;
		}
		case 'S': {

			Sflag = 1;
			noofbits_reg1 = atoi(optarg);
			//cout << "\nNumber of bits in the regsiter 2::" << noofbits_reg1;
			break;
		}
		case 'r':
			rflag = 1;
			rpos = optind;
			rightshift_value = atoi(optarg);
			//cout << "\nShift right by ::" << rightshift_value;
			break;
		case 'R':
			Rflag = 1;
			Rpos = optind;
			rightshift_value1 = atoi(optarg);
			//cout << "\nShift right by ::" << rightshift_value1;
			break;
		case 'l':
			lpos = optind;
			lflag = 1;
			leftshift_value = atoi(optarg);
			//cout << "\nShift Left by 2::" << leftshift_value;
			break;
		case 'L':
			Lpos = optind;
			Lflag = 1;
			leftshift_value1 = atoi(optarg);
			//cout << "\nShift Left by::" << leftshift_value1;
			break;
		case 'v':
			vflag = 1;
			inject_value = atoi(optarg);
			//cout << "\nValue to be padded::" << inject_value;
			break;
//		case 'd':
//			dflag = 1;
//			decimal_convert = atoi(optarg);
//			cout << "\nconvert to decimal::" << decimal_convert;
//			break;
		case 'p':
			pflag = 1;
			break;
		case 'd':
					dflag = 1;
			break;
		case 'h':
					hflag = 1;
			break;
		case 'o':
			oper = string(optarg);
			Oflag = 1;
			//cout << "\noperration:: " << oper;

			break;
		case '?':
			if (optopt == 'i' || optopt == 's' || optopt == 'l' || optopt == 'r'
					|| optopt == 'v' || optopt == 'p'|| optopt == 'd') {

				cout << "\n Error !! The argument" << optopt
						<< "requires a non option argument!!";
				return -1;

			}
			cout << "Please enter a valid argument !!";
			break;
		default:
			abort();
			return -1;

		}
	if (argc < 2) {

		cout << " Error !! Please enter the more arguments!!";
		return -1;
		abort();
	}

	if (iflag != 1) {
		cout << "\n Enter the minimum required arguments";
		return -1;
		exit(0);
	}


	vector<char> playerInfoVector(init.begin(), init.end());
	vector<char> playerInfoVector1(init1.begin(), init1.end());
	vector<char> finalresult;
	//***********************For first vector********************************************

	int difference = noofbits_reg - playerInfoVector.size();
	if (noofbits_reg > playerInfoVector.size()) {

		playerInfoVector.insert(playerInfoVector.begin(), difference, '0');
	}
	if (lflag == 1 && rflag == 1) {
		if (lpos > rpos) {
			sr.shiftleft(playerInfoVector, noofbits_reg, inject_value,
					leftshift_value, print_value);
			sr.shiftright(playerInfoVector, noofbits_reg, inject_value,
					rightshift_value, print_value);
		} else {
			sr.shiftright(playerInfoVector, noofbits_reg, inject_value,
					rightshift_value, print_value);
			sr.shiftleft(playerInfoVector, noofbits_reg, inject_value,
					leftshift_value, print_value);
		}
	}
	if (lflag == 0 && rflag == 1) {
		sr.shiftright(playerInfoVector, noofbits_reg, inject_value,
				rightshift_value, print_value);
	} else if (lflag == 1 && rflag == 0) {
		sr.shiftleft(playerInfoVector, noofbits_reg, inject_value,
				leftshift_value, print_value);
	}

	sr.displayregister(playerInfoVector, pflag,sflag,Sflag,noofbits_reg,noofbits_reg1);
	cout<<endl;

	//***********************For second vector********************************************
	int difference1 = noofbits_reg1 - playerInfoVector1.size();
	if (noofbits_reg1 > playerInfoVector1.size()) {

		playerInfoVector1.insert(playerInfoVector1.begin(), difference1, '0');
	}
	if (Lflag == 1 && Rflag == 1) {
		if (Lpos > Rpos) {
			sr.shiftleft(playerInfoVector1, noofbits_reg1, inject_value,
					leftshift_value1, print_value);
			sr.shiftright(playerInfoVector1, noofbits_reg1, inject_value,
					rightshift_value1, print_value);
		} else {
			sr.shiftright(playerInfoVector1, noofbits_reg1, inject_value,
					rightshift_value1, print_value);
			sr.shiftleft(playerInfoVector1, noofbits_reg1, inject_value,
					leftshift_value1, print_value);
		}
	}
	if (Lflag == 0 && Rflag == 1) {
		sr.shiftright(playerInfoVector1, noofbits_reg1, inject_value,
				rightshift_value1, print_value);
	} else if (Lflag == 1 && Rflag == 0) {
		sr.shiftleft(playerInfoVector1, noofbits_reg1, inject_value,
				leftshift_value1, print_value);
	}

	sr.displayregister(playerInfoVector1, pflag, sflag, Sflag,noofbits_reg,noofbits_reg1);
	cout<<endl;

	//*************addition****************
	if (oper == "+") {
		finalresult=sr.addition(playerInfoVector, playerInfoVector1);
		//cout<<"\n Addition Result:";
		sr.displayregister(finalresult,pflag, sflag, Sflag,noofbits_reg,noofbits_reg1);
	}

	else if (oper == "-") {

		finalresult=sr.subtraction(playerInfoVector, playerInfoVector1);
		//cout<<"\n Subtraction Result:";
		sr.displayregister(finalresult,pflag, sflag, Sflag,noofbits_reg,noofbits_reg1);
	}
	if(pflag==1){
		string stringfinal(finalresult.begin(), finalresult.end());
		int finalint= strtoull(stringfinal.c_str(),NULL,2);
		if(dflag==1){
			cout<<"(0x"<<hex<<finalint<<")";
		}
		if(hflag==1){
			cout<<"("<<finalint<<")";
		}

	}
	cout<<endl;

	return 0;
}

void shiftreg::shiftright(vector<char> &playerInfoVector, int &noofbits_reg,
		int &inject_value, int &rightshift_value, int &print_value) {

	int size = playerInfoVector.size() - rightshift_value;
	int index = rightshift_value;

	playerInfoVector.erase(playerInfoVector.begin() + size,
			playerInfoVector.end());
	if (inject_value == 1)
		playerInfoVector.insert(playerInfoVector.begin(), rightshift_value,
				'1');
	else
		playerInfoVector.insert(playerInfoVector.begin(), rightshift_value,
				'0');

}

vector<char> shiftreg::addition(vector<char> &playerInfoVector,
		vector<char> &playerInfoVector1) {

	int carry = 0, check;
	shiftreg sr;

	vector<char> result;
	for (int i = 7; i >= 0; i--) {
		check = playerInfoVector[i] + playerInfoVector1[i] + carry;
		if (check == 96) {

			result.push_back('0');
			carry = 0;
		}
		if (check == 97) {
			result.push_back('1');
			carry = 0;
		}
		if (check == 98) {
			result.push_back('0');
			carry = 1;
		}
		if (check > 98) {
			result.push_back('1');
			carry = 1;
		}
	}
	reverse(result.begin(), result.end());

//	cout << "\n";
	for (unsigned int j = 0; j <= result.size(); j++) {
//		cout << result[j];

	}
//	cout << endl;
	return result;

}

vector<char> shiftreg::subtraction(vector<char> &playerInfoVector,
		vector<char> &playerInfoVector1) {

	vector<char> result, onevec, twocompres, finaladd, temp, temp1, temp2;
	shiftreg sr;
	int pflag = 1;
	temp = playerInfoVector1;
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('0');
	onevec.push_back('1');

	for (int i = 0; i < temp.size(); i++) {

		if (temp[i] == '0') {

			temp[i] = '1';
		} else if (temp[i] == '1') {
			temp[i] = '0';

		}
	}

	int carry = 0, check;

	for (int i = 7; i >= 0; i--) {
		check = temp[i] + onevec[i] + carry;
		if (check == 96) {

			temp1.push_back('0');
			carry = 0;
		}
		if (check == 97) {
			temp1.push_back('1');
			carry = 0;
		}
		if (check == 98) {
			temp1.push_back('0');
			carry = 1;
		}
		if (check > 98) {
			temp1.push_back('1');
			carry = 1;
		}
	}
	reverse(temp1.begin(), temp1.end());

	result = sr.addition(playerInfoVector, temp1);
	//cout << "\nSubtraction::";
	for (unsigned int i = 0; i < result.size(); i++) {
//
//		cout << result[i];

	}

	return result;

}

void shiftreg::shiftleft(vector<char> &playerInfoVector, int &noofbits_reg,
		int &inject_value, int &leftshift_value, int &print_value) {

	int size = playerInfoVector.size() - leftshift_value;
	int index = leftshift_value;
	int difference = noofbits_reg - playerInfoVector.size();

	playerInfoVector.erase(playerInfoVector.begin(),
			playerInfoVector.begin() + leftshift_value);
	if (inject_value == 1) {

		playerInfoVector.insert(playerInfoVector.begin() + size,
				leftshift_value, '1');

	} else
		playerInfoVector.insert(playerInfoVector.begin() + size,
				leftshift_value, '0');

}

void shiftreg::displayregister(vector<char> &playerInfoVector, int &pflag,int &sflag, int &Sflag, int &noofbits_reg,int &noofbits_reg1 ) {

	if (pflag) {
		//cout << "\n";
		int size,size1=playerInfoVector.size();
		if (noofbits_reg>noofbits_reg1)
		{ size=size1-noofbits_reg;}
		else{
			size=size1-noofbits_reg1;}
		for (int m = size; m < playerInfoVector.size(); m++) {

			cout << playerInfoVector[m];
		}

	}

}

