#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(2n)
     * SC: O(n)
     */
    Node* oddEvenListBrute(Node* &head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        vector<int> result;
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            result.push_back(temp->data);
            temp = temp->next->next;
        }

        if (temp != nullptr)
            result.push_back(temp->data);

        temp = head->next;

        while (temp != nullptr && temp->next != nullptr) {
            result.push_back(temp->data);
            temp = temp->next->next;
        }

        if (temp != nullptr)
            result.push_back(temp->data);

        int i = 0;
        temp = head;

        while (temp != nullptr) {
            temp->data = result[i++];
            temp = temp->next;
        }

        return head;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    Node* oddEvenListOptimal(Node* &head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node* odd = head;
        Node* even = head->next;
        Node* firstEven = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = firstEven;

        return head;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3, 4, 5};

    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    sol.oddEvenListBrute(head1);

    cout << "Brute Force: ";
    printList(head1);

    Node* head2 = createList(nums);

    sol.oddEvenListOptimal(head2);

    cout << "Optimal: ";
    printList(head2);

    return 0;
}