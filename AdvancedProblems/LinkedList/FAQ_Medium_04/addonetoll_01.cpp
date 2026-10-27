#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

#define REVERSE_LIBRARY
#include "../LogicBuilding_03/reverselinkedlist_05.cpp"

class Solution {
public:

    /**
     * Method 1: Iterative Approach
     * TC: O(3n)
     * SC: O(1)
     */
    Node* addOneIterative(Node* head) {
        ReverseLinkedList sol;
        head = sol.reverseListOptimalIterative(head);

        Node* temp = head;
        int carry = 1;

        while (temp != nullptr && carry != 0) {
            int sum = temp->data + carry;

            temp->data = sum % 10;
            carry = sum / 10;

            if (temp->next == nullptr && carry != 0) {
                temp->next = new Node(carry);
                carry = 0;
            }

            temp = temp->next;
        }

        head = sol.reverseListOptimalIterative(head);

        return head;
    }

    /**
     * Method 2: Recursive Approach
     * TC: O(n)
     * SC: O(n)
     */
    Node* addOneRecursive(Node* head) {
        if (head == nullptr) {
            return new Node(1);
        }

        int carry = addOneHelper(head);

        if (carry != 0) {
            Node* newHead = new Node(carry);
            newHead->next = head;
            return newHead;
        }

        return head;
    }

private:
    int addOneHelper(Node* head) {
        if (head == nullptr) {
            return 1;
        }

        int carry = addOneHelper(head->next);

        if (carry == 0) {
            return 0;
        }

        int sum = head->data + carry;
        head->data = sum % 10;

        return sum / 10;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 9};

    Node* head1 = createList(nums);
    cout << "Original List: ";
    printList(head1);

    head1 = sol.addOneIterative(head1);
    cout << "Iterative: ";
    printList(head1);

    vector<int> nums2 = {9, 9, 9};

    Node* head2 = createList(nums2);
    head2 = sol.addOneRecursive(head2);

    cout << "Recursive: ";
    printList(head2);

    return 0;
}