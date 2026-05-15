#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void expand(string &s, int left, int right,
                int &start, int &maxLen) {

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            int len = right - left + 1;

            if (len > maxLen) {
                maxLen = len;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < s.size(); i++) {

            // Odd length
            expand(s, i, i, start, maxLen);

            // Even length
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};
