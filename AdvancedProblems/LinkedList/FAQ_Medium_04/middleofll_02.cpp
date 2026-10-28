#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brue Force
     * TC: O(3n/2)
     * SC: O(1)
     */
    Node* middleOfLinkedListBrute(Node* head) {
        Node* temp = head;

        int count = 0;
        while (temp != nullptr) {
            count += 1;
            temp = temp->next;
        }

        int midPosition = (count / 2) + 1;
        Node* middleNode = head;
        for(int i = 1; i < midPosition; i++) {
            middleNode = middleNode -> next;
        }
        
        return middleNode;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n/2)
     * SC: O(1)
     */
    Node* middleOfLinkedListOptimal(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next !=nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
};


int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5, 6};

    // Method 1: Brute Force
    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    Node* mid1 = sol.middleOfLinkedListBrute(head1);

    cout << "Brute Force Middle: ";
    if (mid1 != nullptr) {
        cout << mid1->data << endl;
    }

    // Method 2: Optimal
    Node* head2 = createList(nums);

    Node* mid2 = sol.middleOfLinkedListOptimal(head2);

    cout << "Optimal Middle: ";
    if (mid2 != nullptr) {
        cout << mid2->data << endl;
    }

    return 0;
}
