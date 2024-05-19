#include <stdio.h>
#include <stdlib.h>

int compare (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}

int main(void) {
	int n;
	scanf("%d", &n);
	int bus[n];
	for(int i=0; i<n; i++) {
		scanf("%d", bus+i);
	}
	qsort (bus, n, sizeof(int), compare);
	for(int i=0; i<n; i++) {
//		printf("processed\n");
		if(i==0)
			printf("%d", bus[i]);
		else 
			printf(" %d", bus[i]);
		if((bus[i+1]==bus[i]+1)&&(bus[i+2]==bus[i]+2)) {
			printf("-");
			for(int j=3; j<n; j++) {
//				printf("\ni=%d\n", i);
/*				if(j==n-1) {
					printf("%d\n", bus[n-1]);
					return 0;
				}*/
				if(bus[i+j]!=bus[i]+j) {
					printf("%d", bus[i+j-1]);
//					printf("\n%d %d\n", i, j);
					i = i+j-1;
//					printf("\n%d\n", i);
					break;
//					printf("%d\n", i);
				}
				else if(j==n-1) {
					printf("%d\n", bus[n-1]);
					return 0;
				}
/*				if(j==n) {
					printf("%d\n", bus[n-1]);
					return 0;
				}*/
			}
		}
//		if(i!=n)
//			printf(" ");
	}
	printf("\n");	

	return 0;
}
