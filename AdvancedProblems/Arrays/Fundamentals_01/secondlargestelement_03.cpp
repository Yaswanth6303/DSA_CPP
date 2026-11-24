#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int secondLargestElementBrute(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int largest = nums[n - 1];
        int secondLargest = -1;
        int i = n - 2;
        while (i >= 0) {
            if (nums[i] != largest) {
                secondLargest = nums[i];
                break;
            }
        }

        return secondLargest;
    }

    int secondLargestElementBetter(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return -1;

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < n; i++) {
            largest = max(largest, nums[i]);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > secondLargest && nums[i] != largest) {
                secondLargest = nums[i];
            }
        }
        return secondLargest == INT_MIN ? -1 : secondLargest;
    }

    int secondLargestElementOptimal(vector<int>& nums) {
        int n = nums.size();
        if (n < 2)
            return -1;

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (nums[i] > largest) {
                largest = nums[i];
                secondLargest = largest;
            } else if (nums[i] > secondLargest && nums[i] != largest) {
                secondLargest = nums[i];
            }
        }

        return secondLargest == INT_MIN ? -1 : secondLargest;
    }
};

int main() {
    vector<int> nums = {1, 2, 4, 6, 7, 5};

    Solution sol;

    int resultBrute = sol.secondLargestElementBrute(nums);
    int resultBetter = sol.secondLargestElementBetter(nums);
    int resultOptimal = sol.secondLargestElementOptimal(nums);

    cout << "Second Largest(Brute): " << resultBrute << endl;
    cout << "Second Largest(Better): " << resultBrute << endl;
    cout << "Second Largest(Optimal): " << resultBrute << endl;

    return 0;
}
