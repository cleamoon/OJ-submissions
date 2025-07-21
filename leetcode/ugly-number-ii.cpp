class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> lst(1, 1);
            int max = 1;
            int p2 = 0, p3 = 0, p5 = 0;
            while (lst.size() < n) {
                while(lst[p2] * 2 <= max) p2++;
                while(lst[p3] * 3 <= max) p3++;
                while(lst[p5] * 5 <= max) p5++;
                int v2 = lst[p2] * 2, v3 = lst[p3] * 3, v5 = lst[p5] * 5;
                if (v2 <= v3 && v2 <= v5) {
                    max = v2;
                } else if (v3 <= v2 && v3 <= v5) {
                    max = v3;
                } else if (v5 <= v2 && v5 <= v3) {
                    max = v5;
                }
    
                lst.push_back(max);
            }
            return lst[n - 1];
        }
    };