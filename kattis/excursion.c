#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 1100000
int main(void) {
    char in[MAX];
    long long times=0;
    scanf("%s", in);
    long long l=strlen(in);
    long long *nOf2 = (long long*) malloc (l*sizeof(long long));
    long long *nOf1 = (long long*) malloc (l*sizeof(long long));
    for(long long i=1; i<l; i++) {
        switch(in[i-1]) {
            case '1': 
                nOf1[i] += (nOf1[i-1]+1);
                nOf2[i] = nOf2[i-1];
                break;
            case '2':
                nOf2[i] += (nOf2[i-1]+1);
                nOf1[i] = nOf1[i-1];
                break;
            default:
                nOf1[i] = nOf1[i-1];
                nOf2[i] = nOf2[i-1];
                break;
        }
    }
    for(long long i=l-1; i>-1; i--) {
        switch(in[i]) {
            case '2':
                continue;
            case '1':
                times += nOf2[i];
                break;
            case '0':
                times += (nOf1[i] + nOf2[i]);
                break;
        }
    }
    printf("%lld\n", times);
    return 0;
}
