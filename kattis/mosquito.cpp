#include <cstdio>
#include <cstdlib>
#define ULL unsigned
using namespace std;

ULL m, p, l, e, r, s, n, tmp;

int main(void) {
  //  printf ("a: %u\n", 13/3);
  while(scanf("%u%u%u%u%u%u%u", &m ,&p, &l, &e, &r, &s, &n)==7) {
    //    printf("%u %u %u %u %u %u %u\n", m, p, l, e, r, s, n);
    for(ULL i=0; i<n; i++) {
      tmp = m;
      m = p/s;
      p = l/r;
      l = tmp*e;
      //      printf("%u %u %u \n", l, p, m);
    }
    printf ("%u\n", m);
  }
  return 0;
}
  
