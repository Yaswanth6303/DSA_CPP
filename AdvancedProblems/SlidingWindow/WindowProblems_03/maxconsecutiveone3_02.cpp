#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnesBrute(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            zeros = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeros++;
                }

                if (zeros <= k)
                    maxLen = max(maxLen, j - i + 1);
                else
                    break;
            }
        }

        return maxLen;
    }

    int longestOnesBetter(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int l = 0;
        int r = 0;
        int zeros = 0;

        for (r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeros++;
            }

            while (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }
                l++;
            }

            int len = r - l + 1;
            maxLen = max(len, maxLen);
        }

        return maxLen;
    }

    int longestOnesOptimal(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;

        int maxLength = 0;
        int zeros = 0;

        for (r = 0; r < n; r++) {
            if (nums[r] == 0) {
                zeros++;
            }

            if (zeros > k) {
                if (nums[l] == 0) {
                    zeros--;
                }

                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    int k = 2;

    cout << "Brute Force: " << sol.longestOnesBrute(nums, k) << endl;
    cout << "Better: " << sol.longestOnesBetter(nums, k) << endl;
    cout << "Optimal: " << sol.longestOnesOptimal(nums, k) << endl;

    return 0;
}
