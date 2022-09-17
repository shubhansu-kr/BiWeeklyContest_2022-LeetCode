// https://leetcode.com/contest/biweekly-contest-87/problems/smallest-subarrays-with-maximum-bitwise-or/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size(), prev = 0, y = INT_MIN;
        vector<int> ans(n);
        vector<int> maxOR(n);
        for (int i = 0; i < n; ++i)
        {
            maxOR[i] = (maxOR[i] | prev);
            prev = maxOR[i];
            if (prev > y) {
                y = prev;
                ans[0] = i+1;
            }
        }
        
        for (int i = 1; i < n; ++i)
        {
            int x = maxOR[i-1], m = INT_MIN;
            for (int len = 1; len <= n - i; ++len)
            {
                int ma = (maxOR[i + len - 1] & x );
                if (ma > m) {
                    m = ma;
                    ans[i] = len;
                }
            }
        }
        return ans;
    }

    // vector<int> smallestSubarrays(vector<int>& nums) {
    //     int n = nums.size(), prev = 0;
    //     vector<int> ans(n);

    //     for (int i = 0; i < n; ++i)
    //     {
    //         vector<int> temp(nums.begin()+i, nums.end());
    //         ans[i] = findMaxOR(temp);
    //     }
    //     return ans;
    // }
    // int findMaxOR(vector<int> &nums) {
    //     int ans = 0, maxOR = INT_MIN, prev = 0, n = nums.size();
    //     vector<int> maxi(nums.size());
    //     for (int i = 0; i < nums.size(); ++i)
    //     {
    //         maxi[i] = (prev | nums[i]);
    //         prev = maxi[i];
    //     }

    //     for (int len = 1; len <= n; ++len)
    //     {
    //         int ma = maxi[len-1], mb;
    //         for (int j = len; j < n; ++j)
    //         {
    //             mb = (maxi[j] & maxi[j-len]);
    //             ma = max(mb, ma);
    //         }
    //         if (ma > maxOR) {
    //             maxOR = ma;
    //             ans = len;
    //         }
    //     }
    //     return ans;
    // }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}