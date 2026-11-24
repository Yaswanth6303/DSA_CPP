#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruitsBrute(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> set;

            for (int j = i; j < n; j++) {
                set.insert(fruits[j]);
                if (set.size() <= 2)
                    maxFruits = max(maxFruits, j - i + 1);
                else
                    break;
            }
        }

        return maxFruits;
    }

    int totalFruitsBetter(vector<int>& fruits) {
        int n = fruits.size();
        int maxFruits = 0;

        unordered_map<int, int> mpp;
        int l = 0, r = 0;

        for (r = 0; r < n; r++) {
            mpp[fruits[r]]++;

            if (mpp.size() > 2) {
                while (mpp.size() > 2) {
                    mpp[fruits[l]]--;
                    if (mpp[fruits[l]] == 0) {
                        mpp.erase(fruits[l]);
                    }
                    l++;
                }
            }

            if (mpp.size() <= 2) {
                maxFruits = max(maxFruits, r - l + 1);
            }

            r++;
        }

        return maxFruits;
    }

    int totalFruitsOptimal(vector<int>& fruits) {
        int n = fruits.size();

        int l = 0;
        int r = 0;

        int maxFruits = 0;
        unordered_map<int, int> mpp;

        for (r = 0; r < n; r++) {
            mpp[fruits[r]]++;

            if (mpp.size() > 2) {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0) {
                    mpp.erase(fruits[l]);
                }
                l++;
            }

            if (mpp.size() <= 2) {
                maxFruits = max(maxFruits, r - l + 1);
            }
        }

        return maxFruits;
    }
};

int main() {
    Solution sol;

    vector<int> fruits = {1, 2, 3, 2, 2, 2, 1};

    cout << "Brute Force: " << sol.totalFruitsBrute(fruits) << endl;
    cout << "Better: " << sol.totalFruitsBetter(fruits) << endl;
    cout << "Optimal: " << sol.totalFruitsOptimal(fruits) << endl;

    return 0;
}
