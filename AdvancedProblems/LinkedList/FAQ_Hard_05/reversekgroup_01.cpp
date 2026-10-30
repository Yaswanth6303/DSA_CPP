#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

#define REVERSE_LIBRARY
#include "../LogicBuilding_03/reverselinkedlist_05.cpp"

class Solution {
public:

    /**
     * TC: O(n)
     * SC: O(1)
     */
    Node* reverseKGroup(Node* head, int k) {
        ReverseLinkedList sol;
        if (head == nullptr || k == 1) return head;

        Node* temp = head;
        Node* prevGroup = nullptr;

        while (temp != nullptr) {
            Node* kthNode = temp;

            for (int i = 1; i < k && kthNode != nullptr; i++) {
                kthNode = kthNode->next;
            }

            if (kthNode == nullptr) break;

            Node* nextGroup = kthNode->next;
            kthNode->next = nullptr;

            Node* newGroupHead = sol.reverseListOptimalIterative(temp);

            if (prevGroup == nullptr) {
                head = newGroupHead;
            } else {
                prevGroup->next = newGroupHead;
            }

            temp->next = nextGroup;

            prevGroup = temp;
            temp = nextGroup;
        }

        return head;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Node* head = createList(nums);

    int k = 3;

    cout << "Original Linked List: ";
    printList(head);

    head = sol.reverseKGroup(head, k);

    cout << "Reversed Linked List in Groups of " << k << ": ";
    printList(head);

    return 0;
}