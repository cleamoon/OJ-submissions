#include <bits/stdc++.h>
#define eps 1e-8
#define pi 3.1415926535897
using namespace std;

typedef long long ll;

int main(void) {
	int r, c;
	cin >> r >> c;
	getchar();
	char karta[r][c];
	bool visited[r][c];
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			scanf("%c", &karta[i][j]);
			//cout << karta[i][j];
			visited[i][j] = false;
			//cout << karta[r][c] << visited[r][c] << endl;
		}
		getchar();
	}
	int rr=0, cc=0;
	int move=0;
	while(1) {
		move++;
		//cout << karta[rr][cc] << endl;
		if(visited[rr][cc]) {
			cout << "Lost\n";
			return 0;
		}
		else {
			visited[rr][cc]=1;
		}
		switch(karta[rr][cc]) {
			case 'N': rr--;	break;
			case 'S': rr++; break;
			case 'W': cc--; break;
			case 'E': cc++; break;
			case 'T': cout << move-1 << endl; return 0;
		}
		if(rr>=r || cc>=c || rr<0 || cc<0) {
			cout << "Out" << endl;
			return 0;
		}
		//cout << rr << " " << cc << endl;
	}
	return 0;
}