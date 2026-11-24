#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestElement(vector<int>& nums) {
        int n = nums.size();
        int largestElement = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > largestElement) {
                largestElement = nums[i];
            }
        }

        return largestElement;
    }
};

int main() {
    vector<int> nums = {3, 2, 1, 5, 2};

    Solution sol;
    int largest = sol.largestElement(nums);

    cout << largest << endl;
    return 0;
}
