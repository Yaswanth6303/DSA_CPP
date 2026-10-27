#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
    public:

    /**
     * Method 1: Brute Force
     * TC: O(length) + O(length - n)
     * SC: O(1)
     */
    Node* removeNthFromEndBrute(Node* head, int n) {
        Node* temp = head;

        int length = 0;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        int nodeToRemove = length - n + 1;

        if(nodeToRemove == 1) {
            Node* del = head;
            head = del -> next;
            delete del;
            return head;
        }

        temp = head;
        int count = 1;

        while (temp != nullptr && temp->next != nullptr) {
            count++;
            if(count == nodeToRemove) {
                Node* del = temp->next;
                temp->next = del->next;
                delete del;
                break;
            }

            temp = temp->next;
        }
        
        return head;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    Node* removeNthFromEndOptimal(Node* head, int n) {
        Node* fast = head;
        Node* slow = head;

        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        if(fast == nullptr) return slow->next;

        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        Node* del = slow->next;
        slow->next = del->next;
        delete del;
        return head;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5};
    int n = 2;

    // Method 1: Brute Force
    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    head1 = sol.removeNthFromEndBrute(head1, n);

    cout << "Brute Force: ";
    printList(head1);

    // Method 2: Optimal
    Node* head2 = createList(nums);

    head2 = sol.removeNthFromEndOptimal(head2, n);

    cout << "Optimal: ";
    printList(head2);

    return 0;
}
