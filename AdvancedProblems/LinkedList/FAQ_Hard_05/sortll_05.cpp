#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(n) + O(n log n) + O(n)
     * SC: O(n)
     */
    Node* sortListBrute(Node* head) {
        vector<int> nums;
        Node* temp = head;

        while (temp != nullptr) {
            nums.push_back(temp->data);
            temp = temp->next;
        }

        sort(nums.begin(), nums.end());

        temp = head;

        for (int i = 0; i < nums.size(); i++) {
            temp->data = nums[i];
            temp = temp->next;
        }

        return head;
    }

    /**
     * Find middle using slow and fast pointers
     * TC: O(n)
     * SC: O(1)
     */
    Node* findMiddle(Node* head) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    /**
     * Merge two sorted linked lists
     * TC: O(n)
     * SC: O(1)
     */
    Node* merge(Node* list1, Node* list2) {
        Node dummy(-1);
        Node* temp = &dummy;

        while (list1 != nullptr && list2 != nullptr) {

            if (list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }

            temp = temp->next;
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }

        return dummy.next;
    }

    /**
     * Method 2: Optimal Approach (Merge Sort)
     * TC: O(n log n)
     * SC: O(log n) recursion stack
     */
    Node* sortListOptimal(Node* head) {

        if (head == nullptr || head->next == nullptr)
            return head;

        // Find middle
        Node* middle = findMiddle(head);

        // Divide into two halves
        Node* rightHead = middle->next;
        middle->next = nullptr;

        // Recursively sort both halves
        Node* left = sortListOptimal(head);
        Node* right = sortListOptimal(rightHead);

        // Merge sorted halves
        return merge(left, right);
    }
};

int main() {
    vector<int> nums = {4, 2, 1, 3, 5};

    Node* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;

    // Brute Force
    Node* bruteHead = createList(nums);
    bruteHead = sol.sortListBrute(bruteHead);

    cout << "Brute Force: ";
    printList(bruteHead);

    // Optimal: Merge Sort
    Node* optimalHead = sol.sortListOptimal(head);

    cout << "Optimal (Merge Sort): ";
    printList(optimalHead);

    return 0;
}