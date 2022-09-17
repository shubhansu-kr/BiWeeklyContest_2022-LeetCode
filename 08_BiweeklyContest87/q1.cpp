// https://leetcode.com/contest/biweekly-contest-87/problems/count-days-spent-together/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int aliceArrivalMon = stoi(arriveAlice.substr(0, 2));
        int aliceArrivalDay = stoi(arriveAlice.substr(3, 2));
        int aliceLeaveMon = stoi(leaveAlice.substr(0, 2));
        int aliceLeaveDay = stoi(leaveAlice.substr(3, 2));

        int bobArrivalMon = stoi(arriveBob.substr(0, 2));
        int bobArrivalDay = stoi(arriveBob.substr(3, 2));
        int bobLeaveMon = stoi(leaveBob.substr(0, 2));
        int bobLeaveDay = stoi(leaveBob.substr(3, 2));
        
        int monA, monD, dayA, dayD;
        if (aliceArrivalMon > bobArrivalMon) {
            monA = aliceArrivalMon;
            dayA = aliceArrivalDay;
        }
        else if (aliceArrivalMon == bobArrivalMon){
            monA = aliceArrivalMon;
            dayA = max(bobArrivalDay, aliceArrivalDay);
        }
        else {
            monA = bobArrivalMon;
            dayA = bobArrivalDay;
        }


        if (aliceLeaveMon < bobLeaveMon) {
            monD = aliceLeaveMon;
            dayD = aliceLeaveDay;
        }
        else if (aliceLeaveMon == bobLeaveMon) {
            monD = aliceLeaveMon;
            dayD = min(aliceLeaveDay, bobLeaveDay);
        }
        else {
            monD = bobLeaveMon;
            dayD = bobLeaveDay;
        }

        if (monD < monA || monA == monD && dayD < dayA) {
            return 0;
        }

        int ans = 0; 
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        if (monA == monD) {
            return dayD - dayA + 1;
        }

        for (int i = monA+1; i < monD; ++i)
        {
            ans += days[i-1];
        }
        ans += (days[monA-1] - dayA + 1);
        ans += dayD;
        return ans;
    }
};

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}