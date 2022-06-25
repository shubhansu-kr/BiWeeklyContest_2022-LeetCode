// https://leetcode.com/contest/biweekly-contest-81/problems/count-asterisks/

// You are given a string s, where every two consecutive vertical bars '|'
// are grouped into a pair. In other words, the 1st and 2nd '|' make a pair,
// the 3rd and 4th '|' make a pair, and so forth.

// Return the number of '*' in s, excluding the '*' between each pair of '|'.

// Note that each '|' will belong to exactly one pair.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countAsterisks(string s)
    {
        int flag = 1, count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (flag)
            {
                if (s[i] == '*')
                {
                    ++count;
                }
                else if (s[i] == '|') {
                    flag = 0 ;
                }
            }
            else {
                if (s[i] == '|') {
                    flag = 1; 
                }
            }
        }
        return count ;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}