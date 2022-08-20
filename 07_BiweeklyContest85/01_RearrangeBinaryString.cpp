// https://leetcode.com/contest/biweekly-contest-85/problems/time-needed-to-rearrange-a-binary-string/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // WA 
public:
    int secondsToRemoveOccurrences(string s)
    {
        int count = 0, ind = -1, jnd = -1, n = s.length();
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
            {
                ++count;
                if (ind == -1) ind = i;
            }
            else {
                if (ind != -1 && jnd == -1) jnd = i;
            }
        }
        if (!count || jnd == -1) return 0;
        int time = (jnd - ind - 1) + (n - count) - ind;
        return time;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}