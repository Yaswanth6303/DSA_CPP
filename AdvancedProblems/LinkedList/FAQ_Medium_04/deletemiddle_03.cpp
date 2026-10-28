#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(3n/2)
     * SC: O(1)
     */
    Node* deleteMiddleBrute(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        Node* temp = head;
        int count = 0;

        while (temp != nullptr) {
            count += 1;
            temp = temp->next;
        }

        int middleIndex = count / 2;
        temp = head;
        for(int i = 1; i < middleIndex; i++) {
            temp = temp->next;
        }

        if(temp->next != nullptr) {
            Node* middle = temp->next; 
            temp->next = temp->next->next;
            delete middle;
        }
        
        return head;
    }

    /**
     * Method 2: Optimal Approach 1
     * TC: O(n/2)
     * SC: O(1)
     */
    Node* deleteMiddleOptimal1(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev = nullptr;

        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next;
        delete slow;

        return head;
    }

    /**
     * Method 1: Optimal Approach 2
     * TC: O(n/2)
     * SC: O(1)
     */
    Node* deleteMiddleOptimal2(Node* head) {
        if (head == nullptr || head->next == nullptr) {
            delete head;
            return nullptr;
        }

        Node* slow = head;
        Node* fast = head;

        fast = fast->next->next;
        while (fast != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Method 1: Brute Force
    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    head1 = sol.deleteMiddleBrute(head1);

    cout << "Brute Force: ";
    printList(head1);

    // Method 2: Optimal Approach 1
    Node* head2 = createList(nums);

    head2 = sol.deleteMiddleOptimal1(head2);

    cout << "Optimal Approach 1: ";
    printList(head2);

    // Method 3: Optimal Approach 2
    Node* head3 = createList(nums);

    head3 = sol.deleteMiddleOptimal2(head3);

    cout << "Optimal Approach 2: ";
    printList(head3);

    return 0;
}
