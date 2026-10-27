#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

/**
 * TC: O(max(M, N)) 
 * SC: O(max(M, N))
 */
class Solution {
public:
    Node* addTwoNumbers(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry;

            if (l1 != nullptr) {
                sum += l1->data;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->data;
                l2 = l2->next;
            }

            Node* newNode = new Node(sum % 10);
            carry = sum / 10;
            temp->next = newNode;
            temp = temp->next;
        }

        Node* result = dummy->next;
        delete dummy;

        return result;
    }
};

int main() {
    vector<int> nums1 = {2, 4, 3}; // 342
    vector<int> nums2 = {5, 6, 4}; // 465

    Node* l1 = createList(nums1);
    Node* l2 = createList(nums2);

    Solution solution;
    Node* result = solution.addTwoNumbers(l1, l2);

    cout << "First number: ";
    printList(l1);

    cout << "Second number: ";
    printList(l2);

    cout << "Sum: ";
    printList(result);

    return 0;
}
