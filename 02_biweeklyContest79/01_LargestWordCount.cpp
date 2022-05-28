// https://leetcode.com/contest/biweekly-contest-79/problems/sender-with-largest-word-count/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        map<string, int> freq;
        for (int i = 0; i < messages.size(); ++i)
        {
            freq[senders[i]] += wordCount(messages[i]);
        }
        string ans;
        int max = -1;
        for (auto a : freq)
        {
            if (max <= a.second)
            {
                max = a.second;
                ans = a.first;
            }
        }
        return ans;
    }
    int wordCount(string s)
    {
        int count = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if (s[i] == 32)
            {
                ++count;
            }
        }
        return count + 1;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}