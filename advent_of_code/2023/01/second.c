#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

const char WORDS[10][6] = {"zero", "one", "two",   "three", "four",
                           "five", "six", "seven", "eight", "nine"};

const char DIGITS[10][2] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

int main() {
  unsigned sum = 0;

  FILE *fp = fopen("input.txt", "r");

  char line[MAX];

  while (fgets(line, MAX, fp) != NULL) {
    int len = strlen(line);
    int first = 0;
    int last = 0;
    bool found_first = false;
    bool found_last = false;
    for (size_t i = 0; i < len; i++) {
      if (found_first) {
        break;
      }
      for (size_t j = 0; j < 10; j++) {
        if (strncmp(line + i, WORDS[j], strlen(WORDS[j])) == 0) {
          first = j;
          found_first = true;
          break;
        }
        if (strncmp(line + i, DIGITS[j], 1) == 0) {
          first = j;
          found_first = true;
          break;
        }
      }
    }
    for (size_t i = len - 1; i >= 0; i--) {
      if (found_last) {
        break;
      }
      for (size_t j = 0; j < 10; j++) {
        const size_t len = strlen(WORDS[j]);
        if (strncmp(line + i - len, WORDS[j], len) == 0) {
          last = j;
          found_last = true;
          break;
        }
        if (strncmp(line + i - 1, DIGITS[j], 1) == 0) {
          last = j;
          found_last = true;
          break;
        }
      }
    }
    sum += first * 10 + last;
  }

  printf("%d\n", sum);

  fclose(fp);

  return 0;
}