#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define TEST(a) if((input[i]==a)&&(input[i+1]=='p')&&(input[i+2]==a)) {cout << a; i+=2; continue;}
using namespace std;

int main(void) {
	string input;

	getline(cin, input);
	for(int i=0; i<(int)input.size(); i++) {
		TEST('a');
		TEST('e');
		TEST('i');
		TEST('o');
		TEST('u');
		cout << input[i];
	}
		//		cout << " ";
	cout << endl;
	return 0;
}
