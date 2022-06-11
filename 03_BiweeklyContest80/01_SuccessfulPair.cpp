// https://leetcode.com/contest/biweekly-contest-80/problems/successful-pairs-of-spells-and-potions/

// You are given two positive integer arrays spells and potions, of length n and m respectively, 
// where spells[i] represents the strength of the ith spell and potions[j] represents the 
// strength of the jth potion.

// You are also given an integer success. A spell and potion pair is considered successful 
// if the product of their strengths is at least success.

// Return an integer array pairs of length n where pairs[i] is the number of potions that 
// will form a successful pair with the ith spell.

#include <bits/stdc++.h>
using namespace std ;

// Line 11: Char 31: runtime error: signed integer overflow: 34914 * 61509 cannot be represented in 
// type 'int' (solution.cpp)
// SUMMARY: UndefinedBehaviorSanitizer: undefined-behavior prog_joined.cpp:20:31

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(), potions.end()) ; 
        for (int i = 0; i < spells.size(); ++i)
        {
            int flag = 1 ;
            for (int j = 0; j < potions.size(); ++j)
            {
                long long prod = spells[i] * potions[i] ;
                if (prod >= success) {
                    flag = 0;
                    ans.push_back(potions.size()-i);
                    break;
                }
            }
            if (flag) {
                ans.push_back(0);
            }
        }
        return ans; 
    }
};

int main () {
    vector<int> ans ;
    vector <int> spells = {23434, 3, 5}, potions = {423452, 53, 2};

    Solution obj1;
    ans = obj1.successfulPairs(spells, potions, 2341453134) ;
    
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}