/*
 * CTU Open Contest 2011
 *
 * Sample solution: result
 * Author: Jan Stoklasa
*/
 
#include <stdlib.h>
#include <climits>
 
#include <iostream>
#include <sstream>
#include <string>
 
using namespace std;
 
const int MAX_N=60;
int x[MAX_N];
char op[MAX_N-1];
long long int minimum[MAX_N][MAX_N];
long long int maximum[MAX_N][MAX_N];
 
long long int operation(long long int x, char op, long long int y)
{
	long long result;
	if (op=='+')
		result = x+y;
	else if (op=='*')
		result = x*y;
	else
	{
		cout << "Ambiguous result: error - invalid operation " << op << endl;
		exit(1);
	}
        return result;
}
 
int main(void)
{
	string s;
	while( (cin >> s) && (s!="END") )
	{
		istringstream str(s);
		int n=0;
		while (str >> x[n])
			str >> op[n++];
		for(int i=0;i<n;i++)
		{
			minimum[i][i] = maximum[i][i] = x[i];
		}
 
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
			{
				minimum[i][j] = LLONG_MAX;
				maximum[i][j] = LLONG_MIN;
			}
 
		for (int diag=1; diag<n; diag++)
			for (int row=0; row<n-diag; row++)
				for (int i=row; i<row+diag; i++)
				{
					minimum[row][row+diag]=min(minimum[row][row+diag],operation(minimum[row][i],op[i],minimum[i+1][row+diag]));
					maximum[row][row+diag]=max(maximum[row][row+diag],operation(maximum[row][i],op[i],maximum[i+1][row+diag]));
				}
		cout << minimum[0][n-1] << " " << maximum[0][n-1] << endl;
	}
	return 0;
}
