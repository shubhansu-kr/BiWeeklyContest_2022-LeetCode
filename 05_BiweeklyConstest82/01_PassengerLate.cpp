// https://leetcode.com/contest/biweekly-contest-82/problems/the-latest-time-to-catch-a-bus/

// You are given a 0-indexed integer array buses of length n, where buses[i]
// represents the departure time of the ith bus. You are also given a
// 0-indexed integer array passengers of length m, where passengers[j]
// represents the arrival time of the jth passenger. All bus departure
// times are unique. All passenger arrival times are unique.

// You are given an integer capacity, which represents the maximum number
// of passengers that can get on each bus.

// The passengers will get on the next available bus. You can get on a
// bus that will depart at x minutes if you arrive at y minutes where
// y <= x, and the bus is not full. Passengers with the earliest arrival
// times get on the bus first.

// Return the latest time you may arrive at the bus station to catch a
// bus. You cannot arrive at the same time as another passenger.

// Note: The arrays buses and passengers are not necessarily sorted.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());

        unordered_set<int> time(passengers.begin(), passengers.end());
        int seat, ipass = 0, ibus = 0, ans;
        while (ipass < passengers.size() && ibus <= buses.size())
        {
            seat = capacity;
            while (seat && passengers[ipass] <= buses[ibus] && ipass < passengers.size())
            {
                --seat;
                ++ipass;
            }
            ++ibus;
        }

        if (ibus == buses.size())
        {
            if (seat) ans = buses.back();
            else ans = passengers[ipass - 1];
        }
        else
        {
            ans = buses.back();
        }
        while (!time.count(ans)) --ans;
        return ans;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}