// 6052. Minimum Average Difference

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        if (n < 2)
        {
            return 0;
        }
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int minD = INT_MAX, currentSum = 0, minIndex;
        for (int i = 0; i < n - 1; i++)
        {
            currentSum += nums[i];
            int temp = abs(currentSum / (i + 1) - (sum - currentSum) / (n - i - 1));
            if (temp < minD) {
                minD = temp;
                minIndex = i;
            }
        }
        if (minD > abs(sum/n)) {
            return n ;
        }
        return minIndex;
    }
};

class Solution
{
    // Wrong answer : return the min. index no the min val
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int sum = 0, n = nums.size();
        if (n < 2)
        {
            return nums[0];
        }
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        int minD = sum / n, currentSum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            currentSum += nums[i];
            minD = min(minD, abs(currentSum / (i + 1) - (sum - currentSum) / (n - i - 1)));
        }
        return minD;
    }
};

int main()
{

    return 0;
}