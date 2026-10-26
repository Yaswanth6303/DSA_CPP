#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(2n)
     * SC: O(1)
     */
    Node* sortListBrute(Node* &head) {
        int count0 = 0, count1 = 0, count2 = 0;

        Node* temp = head;

        while (temp != nullptr) {
            if (temp->data == 0)
                count0++;
            else if (temp->data == 1)
                count1++;
            else
                count2++;

            temp = temp->next;
        }

        temp = head;

        while (temp != nullptr) {
            if (count0 > 0) {
                temp->data = 0;
                count0--;
            } else if (count1 > 0) {
                temp->data = 1;
                count1--;
            } else {
                temp->data = 2;
                count2--;
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
    Node* sortListOptimal(Node* &head) {
        if (head == nullptr || head->next == nullptr) return head;

        Node zeroDummy(0);
        Node oneDummy(0);
        Node twoDummy(0);

        Node* zero = &zeroDummy;
        Node* one = &oneDummy;
        Node* two = &twoDummy;

        Node* temp = head;

        while (temp != nullptr) {
            Node* nextNode = temp->next;
            temp->next = nullptr;

            if (temp->data == 0) {
                zero->next = temp;
                zero = temp;
            } else if (temp->data == 1) {
                one->next = temp;
                one = temp;
            } else {
                two->next = temp;
                two = temp;
            }

            temp = nextNode;
        }

        zero->next = (oneDummy.next != nullptr) ? oneDummy.next : twoDummy.next;
        one->next = twoDummy.next;
        two->next = nullptr;

        head = zeroDummy.next;

        return head;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 0, 1, 2, 0};

    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    sol.sortListBrute(head1);

    cout << "Brute Force: ";
    printList(head1);

    Node* head2 = createList(nums);

    head2 = sol.sortListOptimal(head2);

    cout << "Optimal: ";
    printList(head2);

    return 0;
}
