int rangeBitwiseAnd(int left, int right)
{
    int ans = 0;
    unsigned base = 1;
    while (1)
    {
        int rml = left & 1;
        int rmr = right & 1;
        if (rml == rmr)
        {
            if (rmr)
                ans += base * rmr;
        }
        else
        {
            ans = 0;
        }
        if (left == 0 && right == 0)
        {
            break;
        }
        left >>= 1;
        right >>= 1;
        base <<= 1;
    }
    return ans;
}