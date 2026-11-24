
#include <bits/stdc++.h>
#include <utility>
using namespace std;

class Solution {
public:
    void moveZeroesBrute(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n);
        int index = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                result[index++] = nums[i];
            }
        }

        for (int i = index; i < n; i++) {
            result[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            nums[i] = result[i];
        }
    }

    void moveZeroesOptimal(vector<int>& nums) {
        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    vector<int> nums1 = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    vector<int> nums2 = nums1;

    Solution sol;

    // Brute Force
    sol.moveZeroesBrute(nums1);

    cout << "Brute Force: ";
    for (int num : nums1) {
        cout << num << " ";
    }

    cout << endl;

    // Optimal
    sol.moveZeroesOptimal(nums2);

    cout << "Optimal: ";
    for (int num : nums2) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
