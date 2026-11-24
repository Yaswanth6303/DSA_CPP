#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindowBrute(string& s, string& t) {
        int n = s.size();
        int m = t.size();

        int minLen = INT_MAX;
        int sIndex = -1;

        for (int i = 0; i < n; i++) {
            vector<int> hash(256, 0);
            for (char ch : t) {
                hash[ch]++;
            }

            int count = 0;
            for (int j = i; j < s.size(); ++j) {
                if (hash[s[j]] > 0) {
                    count++;
                }
                hash[s[j]]--;

                if (count == m) {
                    if (minLen > j - i + 1) {
                        minLen = j - i + 1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }

    string minWindowOptimal(string& s, string& t) {
        int n = s.size();
        int m = t.size();
        int minLen = INT_MAX;
        int sIndex = -1;

        vector<int> hash(256, 0);
        for (char ch : t) {
            hash[ch]++;
        }

        int count = 0;
        int l = 0;
        int r = 0;

        for (r = 0; r < n; r++) {
            if (hash[s[r]] > 0) {
                count++;
            }

            hash[s[r]]--;
            while (count == m) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    sIndex = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0) {
                    count--;
                }
                l++;
            }
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);
    }
};

int main() {
    Solution sol;

    string s = "ADOBECODEBANC";
    string t = "ABC";

    cout << "Brute Force: " << sol.minWindowBrute(s, t) << endl;
    cout << "Optimal: " << sol.minWindowOptimal(s, t) << endl;

    return 0;
}
