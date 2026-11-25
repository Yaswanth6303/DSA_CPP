#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicatesBrute(vector<int>& nums) {
        set<int> st;

        for (int num : nums) {
            st.insert(num);
        }

        int k = st.size();

        int j = 0;
        for (int num : st) {
            nums[j++] = num;
        }

        return k;
    }

    int removeDuplicatesOptimal(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int j = 0;
        
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[j]) {
                j++;
                nums[j] = nums[i];
            }
        }

        return j + 1;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 1, 2, 2, 2, 3, 3, 4};
    vector<int> nums2 = nums1;

    cout << "Brute Force Approach:" << endl;
    int k1 = obj.removeDuplicatesBrute(nums1);

    cout << "Unique count = " << k1 << endl;
    cout << "Array: ";
    for (int i = 0; i < k1; i++) {
        cout << nums1[i] << " ";
    }
    cout << endl << endl;

    cout << "Optimal Two Pointer Approach:" << endl;
    int k2 = obj.removeDuplicatesOptimal(nums2);

    cout << "Unique count = " << k2 << endl;
    cout << "Array: ";
    for (int i = 0; i < k2; i++) {
        cout << nums2[i] << " ";
    }
    cout << endl;

    return 0;
}