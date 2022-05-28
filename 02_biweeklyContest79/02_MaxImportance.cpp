// https://leetcode.com/contest/biweekly-contest-79/problems/maximum-total-importance-of-roads/

// You are given an integer n denoting the number of cities in a country.
// The cities are numbered from 0 to n - 1.

// You are also given a 2D integer array roads where roads[i] = [ai, bi]
// denotes that there exists a bidirectional road connecting cities ai and bi.

// You need to assign each city with an integer value from 1 to n, where each
// value can only be used once. The importance of a road is then defined as
// the sum of the values of the two cities it connects.

// Return the maximum total importance of all roads possible after assigning
// the values optimally.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        // Calculate the frequency first
        // vector<int> freq(n, 0);
        unordered_map<int, int> freq;
        for (int i = 0; i < roads.size(); ++i)
        {
            ++freq[roads[i][0]];
            ++freq[roads[i][1]];
        }
        multimap<int, int> m;
        for (auto &a : freq)
        {
            m.insert({a.second, a.first});
        }
        int j = 1;
        for (auto &a : m)
        {
            freq[a.second] = j;
            ++j;
        }
        long long imp = 0;
        for (int i = 0; i < roads.size(); ++i)
        {
            imp += (freq[roads[i][0]] + freq[roads[i][1]]);
        }
        return imp;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}