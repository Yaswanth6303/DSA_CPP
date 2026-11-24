#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> bubbleSortBrute(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < n - i; j++) {
                if (nums[j - 1] > nums[j]) {
                    swap(nums[j - 1], nums[j]);
                }
            }
        }

        return nums;
    }

    vector<int> bubbleSortOptimal(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            bool isSwapped = false;
            for (int j = 1; j < n - i; j++) {
                if (nums[j - 1] > nums[j]) {
                    isSwapped = true;
                    swap(nums[j - 1], nums[j]);
                }
            }

            if (!isSwapped)
                break;
        }

        return nums;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5, 1, 4, 3, 2};

    // Brute Bubble Sort
    vector<int> brute = nums;
    vector<int> resultBrute = sol.bubbleSortBrute(brute);

    cout << "Sorted Array Brute: ";
    for (int num : resultBrute) {
        cout << num << " ";
    }
    cout << endl;

    // Optimal Bubble Sort
    vector<int> optimal = nums;
    vector<int> resultOptimal = sol.bubbleSortOptimal(optimal);

    cout << "Sorted Array Optimal: ";
    for (int num : resultOptimal) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
