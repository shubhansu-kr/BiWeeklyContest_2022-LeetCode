// https://leetcode.com/contest/biweekly-contest-80/problems/count-subarrays-with-score-less-than-k/

// The score of an array is defined as the product of its sum and its length.

// For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
// Given a positive integer array nums and an integer k, return the number of 
// non-empty subarrays of nums whose score is strictly less than k.

// A subarray is a contiguous sequence of elements within an array.

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long count = 0 ;
        sort(nums.begin(), nums.end());
        for (int len = 1; len < nums.size(); ++len)
        {
            int sum = 0;
            for (int ind = len; ind < nums.size(); ++ind)
            {
                if (ind < len) {
                    sum += nums[ind] ;
                }
            }
            
        }
        
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}