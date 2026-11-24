#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void insertionSortHelper(vector<int>& nums, int n) {
        if (n <= 1)
            return;

        insertionSortHelper(nums, n - 1);

        int lastElement = nums[n - 1];
        int j = n - 2;

        while (j >= 0 && nums[j] > lastElement) {
            nums[j + 1] = nums[j];
            j--;
        }

        nums[j + 1] = lastElement;
    }

    vector<int> insertionSortRecursive(vector<int>& nums) {
        int n = nums.size();
        insertionSortHelper(nums, n);
        return nums;
    }
};

int main() {
    vector<int> nums = {5, 3, 4, 1, 2};

    Solution sol;

    vector<int> result = sol.insertionSortRecursive(nums);

    cout << "Sorted Array: ";
    for (int num : result) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
