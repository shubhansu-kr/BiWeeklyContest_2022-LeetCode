// https://leetcode.com/contest/biweekly-contest-79/problems/check-if-number-has-equal-digit-count-and-digit-value/

// You are given a 0-indexed string num of length n consisting of digits.

// Return true if for every index i in the range 0 <= i < n,
// the digit i occurs num[i] times in num, otherwise return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool digitCount(string num)
    {
        vector<int> freq(10, 0);
        for (char s : num)
        {
            freq[s-48]++;
        }
        for (int i = 0; i < num.length(); ++i)
        {
            if (num[i]-48 != freq[i])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}