// 6051. Count Prefixes of a Given String

// You are given a string array words and a string s,
// where words[i] and s comprise only of lowercase English letters.

// Return the number of strings in words that are a prefix of s.

// A prefix of a string is a substring that occurs at the
// beginning of the string. A substring is a contiguous sequence
// of characters within a string.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string a, string b)
    {
        if (a.length() >= b.length())
        {
            return a == b;
        }
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }
    int countPrefixes(vector<string> &words, string s)
    {
        int count = 0;
        for (auto it : words)
        {
            if (isValid(it, s))
            {
                ++count;
            }
        }
        return count;
    }
};

class Solution
{
    // Wrong solution -> count prefix , not substring
public:
    int countPrefixes(vector<string> &words, string s)
    {
        int count = 0;
        for (auto it : words)
        {
            if (s.find(it) != string::npos)
            {
                ++count;
            }
        }
        return count;
    }
};

int main()
{

    return 0;
}