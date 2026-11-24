#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low;
        int right = mid + 1;

        vector<int> result;

        while (left <= mid && right <= high) {
            if (nums[left] <= nums[right]) {
                result.push_back(nums[left]);
                left++;
            } else {
                result.push_back(nums[right]);
                right++;
            }
        }

        while (left <= mid) {
            result.push_back(nums[left]);
            left++;
        }

        while (right <= high) {
            result.push_back(nums[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            nums[i] = result[i - low];
        }
    }
    void mergeSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int mid = low + (high - low) / 2;
        mergeSortHelper(nums, 0, mid);
        mergeSortHelper(nums, mid + 1, high);
        merge(nums, low, mid, high);
    }
    vector<int> mergeSort(vector<int>& nums) {
        int n = nums.size();
        mergeSortHelper(nums, 0, n - 1);
        return nums;
    }
};

int main() {
    vector<int> nums = {9, 4, 7, 6, 3, 1, 5};
    int n = nums.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    cout << endl;

    Solution sol;
    vector<int> sortedArr = sol.mergeSort(nums);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << sortedArr[i] << " ";
    cout << endl;

    return 0;
}
