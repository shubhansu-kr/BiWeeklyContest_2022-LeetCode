// https://leetcode.com/contest/biweekly-contest-85/problems/minimum-recolors-to-get-k-consecutive-black-blocks/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // Sliding Window 
public:
    int minimumRecolors(string blocks, int k)
    {
        int cMin = INT_MAX, count = 0;
        for (int i = 0; i < k; ++i)
        {
            if (blocks[i] == 'W') ++count;
        }
        cMin = min(count, cMin);
        int i = 0, j = k;
        while (j < blocks.size()) {
            if (blocks[i] == 'W') --count;
            if (blocks[j] == 'W') ++count;

            cMin = min(count, cMin);
            ++i, ++j;
        }
        return cMin;        
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}