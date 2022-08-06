// https://leetcode.com/contest/biweekly-contest-84/problems/count-number-of-bad-pairs/

#include <bits/stdc++.h>
using namespace std ;

class Solution1 {
    // BruteForce 
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0 ;
        vector<int> track(nums.size(), 1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[i-1]) track[i] = 1;
            else if (nums[i] < nums[i-1]) track[i] = -1;
            else track[i] = 0;
        }
        
    }
};

class Solution {
    // BruteForce: TLE 
public:
    long long countBadPairs(vector<int>& nums) {
        long long count = 0 ;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i+1; j < nums.size(); ++j)
            {
                if (j - i != nums[j] - nums[i]) ++count; 
            } 
        }
        return count;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}