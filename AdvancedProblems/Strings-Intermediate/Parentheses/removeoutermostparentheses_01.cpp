#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                if (balance > 0)
                    result += c;
                balance++;
            } else {
                balance--;
                if (balance > 0)
                    result += c;
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s = "(()())(())";
    cout << "Remove outermost parentheses: ";
    cout << sol.removeOuterParentheses(s) << endl;

    return 0;
}