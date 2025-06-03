#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int main() {
  unsigned sum = 0;

  FILE *fp = fopen("input.txt", "r");

  char line[MAX];

  while (fgets(line, MAX, fp) != NULL) {
    int len = strlen(line);
    int first = 0;
    int last = 0;
    for (int i = 0; i < len; i++) {
      if (isdigit(line[i])) {
        first = line[i] - '0';
        break;
      }
    }
    for (int i = len - 1; i >= 0; i--) {
      if (isdigit(line[i])) {
        last = line[i] - '0';
        break;
      }
    }
    sum += first * 10 + last;
  }

  printf("%d\n", sum);

  fclose(fp);

  return 0;
}