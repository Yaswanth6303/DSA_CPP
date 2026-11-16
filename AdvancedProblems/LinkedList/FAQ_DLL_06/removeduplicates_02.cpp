#include <bits/stdc++.h>
#include "../DoublyNode.h"
using namespace std;

class Solution {
public:
    DoublyNode* removeDuplicates(DoublyNode* head) {
        DoublyNode* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            DoublyNode* nextNode = temp->next;

            while (nextNode != nullptr && nextNode->data == temp->data) {
                DoublyNode* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }

            temp->next = nextNode;

            if (nextNode != nullptr) {
                nextNode->prev = temp;
            }

            temp = nextNode;
        }

        return head;
    }
};


int main() {
    vector<int> nums = {1, 1, 2, 2, 2, 3, 4, 4};

    DoublyNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.removeDuplicates(head);

    cout << "After Removing Duplicates: ";
    printList(head);

    return 0;
}
