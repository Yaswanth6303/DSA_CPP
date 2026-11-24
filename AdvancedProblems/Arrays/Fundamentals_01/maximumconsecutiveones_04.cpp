#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxZeros = INT_MIN;
        int zeros = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                zeros++;
                maxZeros = max(zeros, maxZeros);
            } else {
                zeros = 0;
            }
        }

        return maxZeros;
    }
};

int main() {
    vector nums = {1, 1, 0, 1, 1, 1};
    Solution sol;

    int result = sol.findMaxConsecutiveOnes(nums);

    cout << "The maximum consecutive 1's are " << result << endl;
    return 0;
}
