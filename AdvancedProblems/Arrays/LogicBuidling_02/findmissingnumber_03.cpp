#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumberBrute(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i <= n; i++) {
            bool flag = false;
            for(int j = 0; j < n; j++) {
                if(nums[j] == i) {
                    flag = true;
                    break;
                }
            }

            if(!flag) return i;
        }

        return -1;
    }

    int missingNumberBetter(vector<int>& nums) {
        int n = nums.size();

        vector<int> hash(n + 1, 0);

        for(int i = 0; i < n; i++) {
            hash[nums[i]]++;
        }

        for(int i = 0; i <= n; i++) {
            if(hash[i] == 0) {
                return i;
            }
        }

        return -1;
    }

    int missingNumberOptimal01(vector<int>& nums) {
        int n = nums.size();
        int totalSum = n * (n + 1) / 2;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        return totalSum - sum;
    }

    int missingNumberOptimal02(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor2 ^= (i + 1);
        }

        return xor1 ^ xor2;
    }
};

int main() {
    Solution obj;

    vector<int> nums = {3, 0, 1};

    cout << "Brute Force: "
         << obj.missingNumberBrute(nums) << endl;

    cout << "Better (Hashing): "
         << obj.missingNumberBetter(nums) << endl;

    cout << "Optimal (Sum Formula): "
         << obj.missingNumberOptimal01(nums) << endl;

    cout << "Optimal (XOR): "
         << obj.missingNumberOptimal02(nums) << endl;

    return 0;
}