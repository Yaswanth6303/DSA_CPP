#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bubbleSortHelper(vector<int>& nums, int n) {
        if (n == 1)
            return;

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                swap(nums[i - 1], nums[i]);
            }
        }

        bubbleSortHelper(nums, n - 1);
    }
    vector<int> bubbleSortRecursive(vector<int>& nums) {
        int n = nums.size();
        bubbleSortHelper(nums, n);
        return nums;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {5, 2, 9, 1, 5, 6};

    vector<int> sortedArray = sol.bubbleSortRecursive(nums);
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
