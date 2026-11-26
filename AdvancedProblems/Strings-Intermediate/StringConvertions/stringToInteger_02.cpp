#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        } else if (i < n && s[i] == '+') {
            i++;
        }

        long long result = 0;

        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check
            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 &&
                 digit > (sign == 1 ? 7 : 8))) {
                return sign == 1 ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return static_cast<int>(result * sign);
    }
};

int main() {
    Solution sol;

    string s1 = "42";
    string s2 = "   -42";
    string s3 = "4193 with words";
    string s4 = "words and 987";
    string s5 = "-91283472332";

    cout << sol.myAtoi(s1) << endl; // 42
    cout << sol.myAtoi(s2) << endl; // -42
    cout << sol.myAtoi(s3) << endl; // 4193
    cout << sol.myAtoi(s4) << endl; // 0
    cout << sol.myAtoi(s5) << endl; // INT_MIN

    return 0;
}