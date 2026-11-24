#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kDistinctCharBrute(string& s, int k) {
        int n = s.size();
        int maxLen = 0;

        unordered_map<char, int> mpp;

        for (int i = 0; i < n; i++) {
            mpp.clear();
            for (int j = i; j < n; j++) {
                mpp[s[j]]++;

                if (mpp.size() > k)
                    break;
                maxLen = max(maxLen, j - i + 1);
            }
        }

        return maxLen;
    }

    int kDistinctCharBetter(string& s, int k) {
        int n = s.size();
        int maxLen = 0;

        unordered_map<char, int> mpp;

        int l = 0, r = 0;

        for (r = 0; r < n; r++) {
            mpp[s[r]]++;

            while (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(mpp[s[l]]);
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }

    int kDistinctCharOptimal(string& s, int k) {
        int n = s.size();
        int maxLen = 0;

        unordered_map<char, int> mpp;

        int l = 0, r = 0;

        for (r = 0; r < n; r++) {
            mpp[s[r]]++;

            if (mpp.size() > k) {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                    mpp.erase(mpp[s[l]]);
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string s = "aaabbccd";
    int k = 2;

    cout << "Brute Force: " << sol.kDistinctCharBrute(s, k) << endl;

    cout << "Better: " << sol.kDistinctCharBetter(s, k) << endl;

    cout << "Optimal: " << sol.kDistinctCharOptimal(s, k) << endl;

    return 0;
}
