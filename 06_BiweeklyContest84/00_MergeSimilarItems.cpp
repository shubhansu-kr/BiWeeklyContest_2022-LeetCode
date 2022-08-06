// https://leetcode.com/contest/biweekly-contest-84/problems/merge-similar-items/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        map<int, int> m;
        for(auto &it: items1) m[it[0]] += it[1];
        for(auto &it: items2) m[it[0]] += it[1];

        vector<vector<int>> ret;
        for(auto &it: m) ret.push_back({it.first, it.second});

        return ret;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}