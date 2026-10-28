#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

#define REVERSE_LIBRARY
#include "../LogicBuilding_03/reverselinkedlist_05.cpp"

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(2n)
     * SC: O(n)
     */
    bool isPalindromeBrute(Node* head) {
        Node* temp = head;
        stack<int> st;

        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
        while(temp != nullptr) {
            if(temp->data != st.top()) {
                return false;
            }
            st.pop();
            temp = temp->next;
        }

        return true;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(2n)
     * SC: O(1)
     */
    bool isPalindromeOptimal(Node* head) {
        ReverseLinkedList sol;

        Node* reversed = sol.reverseListOptimalIterative(head);
        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data != reversed->data) {
                return false;
            }

            temp = temp->next;
            reversed = reversed->next;
        }

        return true;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 2, 1};

    // Method 1: Brute Force
    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    bool result1 = sol.isPalindromeBrute(head1);

    cout << "Brute Force: "
         << (result1 ? "Palindrome" : "Not a Palindrome")
         << endl;

    // Method 2: Optimal
    Node* head2 = createList(nums);

    bool result2 = sol.isPalindromeOptimal(head2);

    cout << "Optimal: "
         << (result2 ? "Palindrome" : "Not a Palindrome")
         << endl;

    return 0;
}
