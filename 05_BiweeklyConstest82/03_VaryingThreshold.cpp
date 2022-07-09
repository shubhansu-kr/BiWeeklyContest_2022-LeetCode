// https://leetcode.com/contest/biweekly-contest-82/problems/subarray-with-elements-greater-than-varying-threshold/

// You are given an integer array nums and an integer threshold.
// Find any subarray of nums of length k such that every element in the subarray 
// is greater than threshold / k.
// Return the size of any such subarray. If there is no such subarray, return -1.
// A subarray is a contiguous non-empty sequence of elements within an array.
 

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {   
        for (int len = 1; len <= nums.size(); ++len)
        {
            for (int ind = 0; ind <= nums.size()-len; ++ind)
            {
                int flag = 1;
                for (int i = ind; i < len; ++i)
                {
                    if (nums[i] <= threshold/len) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    return len;
                }
            }
        }
        return -1;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}