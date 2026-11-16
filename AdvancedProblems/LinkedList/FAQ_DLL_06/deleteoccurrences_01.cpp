#include <bits/stdc++.h>
#include "../DoublyNode.h"
using namespace std;

class Solution {
public:
    DoublyNode* deleteAllOccurrences(DoublyNode* head, int target) {
        DoublyNode* temp = head;

        while (temp != nullptr) {
            if (temp->data == target) {
                DoublyNode* nextNode = temp->next;
                DoublyNode* prevNode = temp->prev;

                if (temp == head) {
                    head = nextNode;
                }

                if (nextNode != nullptr) {
                    nextNode->prev = prevNode;
                }

                if (prevNode != nullptr) {
                    prevNode->next = nextNode;
                }

                delete temp;
                temp = nextNode;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 4, 2, 5};
    int target = 2;

    DoublyNode* head = createList(nums);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    head = sol.deleteAllOccurrences(head, target);

    cout << "Updated List:  ";
    printList(head);

    return 0;
}
