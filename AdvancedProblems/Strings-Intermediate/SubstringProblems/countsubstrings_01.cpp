#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubstringsBrute(string s) {
        int n = s.size();
        long long total = 0;

        for (int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for (int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int oddCount = 0;

                for (int k = 0; k < 26; k++) {
                    if (freq[k] % 2 != 0) {
                        oddCount++;
                    }
                }

                if (oddCount <= 1) {
                    total++;
                }
            }
        }

        return total;
    }

    long long countSubstringsOptimal(string s) {
        int n = s.size();
        long long total = 0;

        unordered_map<int, long long> mp;

        int mask = 0;

        // Empty prefix
        mp[0] = 1;

        for (int i = 0; i < n; i++) {

            // Toggle the bit corresponding to current character
            int bit = s[i] - 'a';
            mask ^= (1 << bit);

            // Case 1: All characters have even frequency
            total += mp[mask];

            // Case 2: Exactly one character has odd frequency
            for (int j = 0; j < 26; j++) {
                int newMask = mask ^ (1 << j);
                total += mp[newMask];
            }

            // Store current prefix mask
            mp[mask]++;
        }

        return total;
    }
};

int main() {
    string s = "ababa";

    Solution sol;

    cout << "Brute Force: ";
    cout << sol.countSubstringsBrute(s) << endl;

    cout << "Optimal Approach: ";
    cout << sol.countSubstringsOptimal(s) << endl;

    return 0;
}
