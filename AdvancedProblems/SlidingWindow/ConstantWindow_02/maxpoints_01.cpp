#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCardScore(vector<int>& cardScore, int k) {
        int n = cardScore.size();

        int leftSum = 0;
        int rightSum = 0;
        int maxScore = INT_MIN;

        for (int i = 0; i < k; i++) {
            leftSum += cardScore[i];
        }

        maxScore = max(leftSum, maxScore);

        int right = n - 1;

        for (int i = k - 1; i >= 0; i--) {
            leftSum -= cardScore[i];
            rightSum += cardScore[right];
            right--;

            maxScore = max(maxScore, leftSum + rightSum);
        }

        return maxScore;
    }
};

int main() {
    Solution sol;

    vector<int> cardScore = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    cout << "Maximum Card Score: " << sol.maxCardScore(cardScore, k) << endl;

    return 0;
}
