#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * TC: O(n) + O(n - (k % n))
     * SC: O(1)
     */
    Node* rotateRight(Node* head, int k) {
        if(head == nullptr || head->next == nullptr) return head;

        Node* tail = head;
        int length = 1;

        while (tail->next != nullptr) {
            tail = tail->next;
            length++;
        }

        k = k % length;
        if (k == 0) return head;

        tail->next = head;

        int steps = length - k;
        Node* temp = head;

        for (int i = 1; i < steps; i++) {
            temp = temp->next;
        }
        Node* newHead = temp->next;
        temp->next = nullptr;

        return newHead;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int k = 2;

    // Create linked list
    Node* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    // Rotate linked list
    Solution sol;
    head = sol.rotateRight(head, k);

    cout << "Rotated List: ";
    printList(head);

    return 0;
}