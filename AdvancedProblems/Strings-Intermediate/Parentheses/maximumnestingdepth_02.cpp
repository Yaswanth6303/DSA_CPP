#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int maxCount = 0;
        int count = 0;

        for(char c : s) {
            if(c == '(') {
                count++;
                maxCount = max(count, maxCount);
            } else if(c == ')') {
                count--;
            }
        }
        
        return maxCount;
    }
};

int main() {
    Solution sol;
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Max Depth: ";
    cout << sol.maxDepth(s) << endl;
}