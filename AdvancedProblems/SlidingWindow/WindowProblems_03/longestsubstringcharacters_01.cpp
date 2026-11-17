// Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * TC: O(n)
     * SC: O(26)
     */
    int longestNonRepeatingSubstring(string& s) {
        int n = s.size();
        vector<int> letters(26, 0);

        int longest = INT_MIN;
        int current = 0;
        int left = 0;

        for (int i = 0; i < n; i++) {
            if (letters[s[i] - 'a'] == 0) {
                letters[s[i] - 'a']++;
                current++;
                longest = max(longest, current);
            } else {
                while (letters[s[i] - 'a'] > 0) {
                    letters[s[left] - 'a']--;
                    left++;
                    current--;
                }

                letters[s[i] - 'a']++;
                current++;
                longest = max(longest, current);
            }
        }

        return n == 0 ? 0 : longest;
    }
};

int main() {
    Solution sol;

    string s = "abcabcbb";

    cout << "Longest Non-Repeating Substring: " << sol.longestNonRepeatingSubstring(s) << endl;

    return 0;
}
