#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        map<char, int> mpp;
        mpp.insert({{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}});

        int integer = 0;
        for (int i = 0; i < n; i++) {
            // If the current value is less than the next value, subtract it (e.g., IV = 4)
            if (i + 1 < n && mpp[s[i]] < mpp[s[i + 1]]) {
                integer -= mpp[s[i]];
            } else {
                integer += mpp[s[i]];
            }
        }
        return integer;
    }
};

int main() {
    Solution sol;
    cout << "Roman to Integer: ";
    cout << sol.romanToInt("MCMXCIV");
}