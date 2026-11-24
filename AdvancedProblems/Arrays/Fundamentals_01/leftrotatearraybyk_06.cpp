#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArrayBrute(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;

        k = k % n;

        vector<int> temp(k);

        for (int i = 0; i < k; i++) {
            temp[i] = nums[i];
        }

        for (int i = k; i < n; i++) {
            nums[i - k] = nums[i];
        }

        for (int i = n - k; i < n; i++) {
            nums[i] = temp[i - (n - k)];
        }
    }

    void rotateArrayOptimal(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0)
            return;

        k = k % n;

        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

void printArray(vector<int>& nums) {
    for (int val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    int k = 2;

    Solution sol;

    vector<int> brute = nums;
    vector<int> optimal = nums;

    sol.rotateArrayBrute(brute, k);
    sol.rotateArrayOptimal(optimal, k);

    cout << "Initial array: ";
    printArray(nums);

    cout << "Brute Force: ";
    printArray(brute);

    cout << "Optimal: ";
    printArray(optimal);

    return 0;
}
