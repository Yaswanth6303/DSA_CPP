#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int linearSearch(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                return i;
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums = {2, 3, 4, 5, 3};
    int target = 3;

    Solution sol;
    int result = sol.linearSearch(nums, target);

    cout << result << '\n';
    return 0;
}
