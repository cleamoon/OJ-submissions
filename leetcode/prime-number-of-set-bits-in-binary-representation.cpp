class Solution {
  public:
  
      int countPrimeSetBits(int left, int right) {
          int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
  
          int ans = 0;
          for (auto curr = left; curr <= right; curr++) {
              int dig = 0;
              for (auto i = 0; i < 30; i++) {
                  auto val = curr & (1 << i);
                  if (val > 0) {
                      dig++;
                  }
              }
              for (auto i = 0; i < 8; i++) {
                  if (primes[i] == dig) {
                      ans ++;
                      break;
                  } else if (primes[i] > dig) {
                      break;
                  }
              }
          }
          return ans;
      }
  };