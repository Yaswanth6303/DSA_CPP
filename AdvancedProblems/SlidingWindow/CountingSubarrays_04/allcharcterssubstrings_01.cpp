#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstringsBrute(string& s) {
        int n = s.size();
        int countSubstrings = 0;

        for (int i = 0; i < n; i++) {
            int hash[3] = {0};
            for (int j = i; j < n; j++) {
                hash[s[j] - 'a'] = 1;

                if (hash[0] + hash[1] + hash[2] == 3) {
                    countSubstrings++;
                }
            }
        }

        return countSubstrings;
    }

    int numberOfSubstringsOptimal(string& s) {
        int n = s.size();
        int countSubstrings = 0;
        int lastSeen[3] = {-1, -1, -1};

        for (int i = 1; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                countSubstrings += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
            }
        }

        return countSubstrings;
    }
};

int main() {
    Solution sol;

    string s = "abcabc";

    cout << "Brute Force: " << sol.numberOfSubstringsBrute(s) << endl;

    cout << "Optimal: " << sol.numberOfSubstringsOptimal(s) << endl;

    return 0;
}
