#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacementBrute(string& s, int k) {
        int n = s.size();

        int maxLen = 0;
        vector<int> letters(26, 0);

        for (int i = 0; i < n; i++) {
            fill(letters.begin(), letters.end(), 0);

            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                letters[s[j] - 'A']++;

                maxFreq = max(maxFreq, letters[s[j] - 'A']);

                // From index i till j
                int currIndexLength = j - i + 1;
                int changes = currIndexLength - maxFreq;

                if (changes <= k) {
                    maxLen = max(maxLen, currIndexLength);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }

    int characterReplacementBetter(string& s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;
        int maxLen = 0;
        int maxFreq = 0;

        vector<int> letters(26, 0);

        for (r = 0; r < n; r++) {
            letters[s[r] - 'A']++;
            maxFreq = max(maxFreq, letters[s[r] - 'A']);

            while ((r - l + 1) - maxFreq > k) {
                letters[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }

    int characterReplacementOptimal(string& s, int k) {
        int n = s.size();

        int l = 0;
        int r = 0;

        int maxLen = 0;
        int maxFreq = 0;

        vector<int> letters(26, 0);

        for (r = 0; r < n; r++) {
            letters[s[r] - 'A']++;
            maxFreq = max(maxFreq, letters[s[r] - 'A']);

            int currIndexLength = r - l + 1;
            int changes = currIndexLength - maxFreq;

            if (changes > k) {
                letters[s[l] - 'A']--;
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s = "AABABBA";
    int k = 1;

    cout << "Maximum Length(Brute Force): " << sol.characterReplacementBrute(s, k) << endl;
    cout << "Maximum Length(Better): " << sol.characterReplacementBetter(s, k) << endl;
    cout << "Maximum Length(Optimal): " << sol.characterReplacementOptimal(s, k) << endl;

    return 0;
}
