// https://leetcode.com/contest/biweekly-contest-80/problems/strong-password-checker-ii/

// A password is said to be strong if it satisfies all the following criteria:

// It has at least 8 characters.
// It contains at least one lowercase letter.
// It contains at least one uppercase letter.
// It contains at least one digit.
// It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
// It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
// Given a string password, return true if it is a strong password. Otherwise, return false.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool strongPasswordCheckerII(string password)
    {
        if (password.length() < 8) return false ;
        string sc = "!@#$%^&*()-+";
        bool charCheck = false, digit = false, lowerCase = false, upperCase = false;
        for (int i = 0; i < password.size(); ++i)
        {
            if (i > 0 && password[i] == password[i - 1])
            {
                return false;
            }
            if (!charCheck)
            {
                if (sc.find(password[i]) != string::npos)
                    charCheck = true;
            }
            if (!digit)
            {
                if (password[i] >= '0' && password[i] <= '9')
                    digit = true;
            }
            if (!lowerCase)
            {
                if (password[i] >= 'a' && password[i] <= 'z')
                    lowerCase = true;
            }
            if (!upperCase)
            {
                if (password[i] >= 'A' && password[i] <= 'Z')
                    upperCase = true;
            }
        }
        return charCheck && digit && lowerCase && upperCase;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    return 0;
}