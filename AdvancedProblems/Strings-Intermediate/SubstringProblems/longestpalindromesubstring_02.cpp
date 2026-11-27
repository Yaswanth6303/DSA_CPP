#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool palindrome(string& s) {
        int n = s.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                return false;
            }
        }

        return true;
    }

    string longestPalindromeBrute(string s) {
        int n = s.size();
        int maxLen = 0;
        string result = "";

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                string sub = s.substr(i, j - i + 1);

                if (palindrome(sub)) {
                    int len = j - i + 1;

                    if (len > maxLen) {
                        maxLen = len;
                        result = sub;
                    }
                }
            }
        }

        return result;
    }

    string longestPalindromeOptimal(string s) {
        int n = s.size();
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > maxLen) {
                    maxLen = r - l + 1;
                    start = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    string s = "babad";

    Solution sol;

    // Brute Force Approach
    cout << "Brute Force Approach: " << endl;

    string bruteResult = sol.longestPalindromeBrute(s);

    cout << "Input:  " << s << endl;
    cout << "Output: " << bruteResult << endl;

    // Optimal Approach
    cout << "Optimal Approach: " << endl;

    string optimalResult = sol.longestPalindromeOptimal(s);

    cout << "Input:  " << s << endl;
    cout << "Output: " << optimalResult << endl;

    return 0;
}
