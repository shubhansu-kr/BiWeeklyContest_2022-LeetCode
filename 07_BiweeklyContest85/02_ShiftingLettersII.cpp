// https://leetcode.com/contest/biweekly-contest-85/problems/shifting-letters-ii/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
    // TLE
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> m;
        for (int i = 0; i < shifts.size(); ++i)
        {
            for (int j = shifts[i][0]; j <= shifts[i][1]; ++j)
            {
                if (shifts[i][2]) {m[j]++;}
                else {m[j]--;}
            }            
        }
        for (int i = 0; i < s.length(); ++i)
        {
            m[i] %= 26;
            if (m[i] > 0) {
                s[i] = ((s[i]-'a'+m[i])%26)+'a';
            }
            else if (m[i] < 0) {
                int x = (s[i]-'a'+m[i]);
                if (x >= 0) {
                    s[i] = x+'a';
                }
                else {
                    s[i] = 'z' + x + 1;
                }
            }
        }
        return s;        
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}