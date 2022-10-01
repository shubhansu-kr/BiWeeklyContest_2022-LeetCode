// https://leetcode.com/contest/biweekly-contest-88/problems/remove-letter-to-equalize-frequency/

#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    bool equalFrequency(string word) {
        unordered_map<char, int> freq;
        for(auto a: word) freq[a]++;
        int ref = 0, single = 0, pack = 1;
        for(auto it: freq){
            cout << it.second << " " << ref << endl;
            if (ref){
                if (it.second != ref) {
                    if (abs(it.second - ref) != 1) return false;
                    else {
                        if (pack) {
                            pack = 0;
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
            else {
                ref = it.second;
            }
            if (it.second == 1) single = 1;
        }
        if (pack) {
            return single;
        }
        return true;
    }
};

class Solution1 {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (int i = 0; i < word.size(); ++i)
        {
            freq[word[i]-'a']++;
        }
        sort(freq.begin(), freq.end());
        int ref = 0, single = 0, pack = 1;
        for (int i = 0; i < 26; ++i)
        {
            if (freq[i] == 0) continue;
            if (ref){
                if (freq[i] != ref) {
                    if (abs(freq[i] - ref) != 1) return false;
                    else {
                        if (pack) {
                            pack = 0;
                            continue;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
            else {
                ref = freq[i];
            }
            if (freq[i] == 1) single = 1;
        }
        if (pack) {
            return single;
        }
        return true;
    }
};

int main () {

    Solution Obj;
    cout << Obj.equalFrequency("abcc");

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}