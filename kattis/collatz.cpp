#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#define LL long long 
#define M 10000
using namespace std;

LL* make_table(LL* p, LL n) {
	//LL* end;
	while(1) {
		if(n==1) {
			*p = 1;
			return p;
		}
		else {
			*p = n;
			if(n%2) n = n*3+1;
			else n /= 2;
			p++;
		}
		//cout << n << endl;
	}
}

int main(void) {
	//LL* p1, p2;
	//LL* t1, t2;
	while(1) {
		LL* t1 = (LL*) malloc(M*sizeof(LL));
		LL* t2 = (LL*) malloc(M*sizeof(LL));
		memset(t1, 0, M); 
		memset(t2, 0, M);
		LL n1, n2; 
		scanf("%lld%lld", &n1, &n2);
		//cout << n1 << " " << n2 << endl;
		if(!n1) break;
		LL* e1 = make_table(t1, n1);
		LL* e2 = make_table(t2, n2);
		//cout << e1 << " " << e2 << endl;
		while((e1>=t1)&&(e2>=t2)&&(*e1==*e2)) {
			//cout << *e1 << " " << *e2 << endl;
			e1--; e2--;
		}
		e1++;
		e2++;
		//cout << "here" << endl;
		//cout <<  << endl;
		//printf("%lld needs %lld steps, %lld needs %lld steps, they meet at %lld\n", n1, t1-e1, n2, t2-e2, *(e1++));
		cout << n1 << " needs " << e1-t1 << " steps, " << n2 << " needs " << e2-t2 << " steps, they meet at " << *e1 << "\n";
	}
	return 0;
}