#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int partition(vector<int>& nums, int low, int high) {
        int n = nums.size();
        int pivot = nums[low];
        int i = low;
        int j = high;

        while (i < j) {
            while (nums[i] <= pivot && i < high)
                i++;
            while (nums[j] > pivot && i >= low)
                j--;

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[low], nums[j]);
        return j;
    }
    void quickSortHelper(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        int partitionIndex = partition(nums, low, high);
        quickSortHelper(nums, 0, partitionIndex - 1);
        quickSortHelper(nums, partitionIndex + 1, high);
    }
    vector<int> quickSort(vector<int>& nums) {
        int n = nums.size();
        quickSortHelper(nums, 0, n - 1);
        return nums;
    }
};

int main() {
    vector<int> nums = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = nums.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    Solution sol;

    vector<int> result = sol.quickSort(nums);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
