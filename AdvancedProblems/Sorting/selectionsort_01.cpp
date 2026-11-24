#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> selectionSortv1(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;

            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[minIndex]) {
                    minIndex = j;
                }
            }

            if (minIndex != i) {
                swap(nums[i], nums[minIndex]);
            }
        }

        return nums;
    }

    vector<int> selectionSortv2(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            int minElement = nums[i];

            for (int j = i + 1; j < n; j++) {
                if (nums[j] < minElement) {
                    minElement = nums[j];
                }
            }

            if (minElement != nums[i]) {
                auto it = find(nums.begin() + i + 1, nums.end(), minElement);
                swap(nums[i], *it);
            }
        }

        return nums;
    }
};

int main() {
    vector<int> nums = {7, 5, 9, 2, 8};

    Solution sol;

    vector<int> resultv1 = sol.selectionSortv1(nums);
    vector<int> resultv2 = sol.selectionSortv2(nums);

    cout << "Sorted array v1: ";

    for (int num : resultv1) {
        cout << num << " ";
    }

    cout << endl;

    cout << "Sorted array v2: ";

    for (int num : resultv2) {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}
