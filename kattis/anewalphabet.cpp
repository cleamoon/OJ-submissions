#include <bits/stdc++.h>
#define RP(A,B) case A: return B;
using namespace std;

string getstr(char ch) {
	switch(ch) {
		RP('a',"@");
		RP('b',"8");
		RP('c',"(");
		RP('d',"|)");
		RP('e',"3");
		RP('f',"#");
		RP('g',"6");
		RP('h',"[-]");
		RP('i',"|");
		RP('j',"_|");
		RP('k',"|<");
		RP('l',"1");
		RP('m',"[]\\/[]");
		RP('n',"[]\\[]");
		RP('o',"0");
		RP('p',"|D");
		RP('q',"(,)");
		RP('r',"|Z");
		RP('s',"$");
		RP('t',"\'][\'");
		RP('u',"|_|");
		RP('v',"\\/");
		RP('w',"\\/\\/");
		RP('x',"}{");
		RP('y', "`/");
		RP('z', "2");
		default: return string(1,ch);
	}
}

int main(void) {
	string in;
	getline(cin, in);
	for(unsigned i=0; i<in.length(); i++) {
		char ch = in[i];
		if((ch >= 'A') && (ch<='Z')) ch = ch-'A'+'a';
		cout << getstr(ch);
	}
	cout << endl;
	return 0;
}