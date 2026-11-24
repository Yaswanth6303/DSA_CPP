#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotateArrayByOne(vector<int>& nums) {
        int n = nums.size();
        int temp = nums[0];

        for (int i = 0; i < n - 1; i++) {
            nums[i] = nums[i + 1];
        }
        nums[n - 1] = temp;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 3, 4, 5};

    solution.rotateArrayByOne(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
