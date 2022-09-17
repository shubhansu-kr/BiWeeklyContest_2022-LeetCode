// https://leetcode.com/contest/biweekly-contest-87/problems/maximum-matching-of-players-with-trainers/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end(), greater<int>());
        sort(trainers.begin(), trainers.end(), greater<int>());
    
        int i = 0, j = 0, ans = 0;
        while(i < players.size() && j < trainers.size()) {
            if (trainers[j] < players[i]) {
                ++i;
            }
            else {
                ++i, ++j, ++ans;
            }
        }
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}