#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class ReverseLinkedList {
    public:

    /**
     * Method 1: Brute Force
     * TC: O(2n)
     * SC: O(n)
     */
    Node* reverseListBrute(Node* head) {
        stack<int> st;

        Node* temp = head;
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;
       
        while (!st.empty()) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

    /**
     * Method 2: Optimal Approach (Iterative)
     * TC: O(n)
     * SC: O(n)
     */
    Node* reverseListOptimalIterative(Node* head) {
        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr) {
            Node* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }   

        return prev;
    }

    /**
     * Method 3: Optimal Approach (Recursive)
     * TC: O(n)
     * SC: O(n)
     */
    Node* reverseListOptimalRecursive(Node* head) {
        if(head == nullptr || head->next == nullptr) return head;

        Node* newHead = reverseListOptimalRecursive(head->next);
        Node* front = head->next;
        head->next = nullptr;
        front->next = head;

        return newHead;
    }
};


int main() {
    ReverseLinkedList sol;

    vector<int> nums = {1, 2, 3, 4, 5};

    // Method 1: Brute Force
    Node* head1 = createList(nums);

    cout << "Original List: ";
    printList(head1);

    head1 = sol.reverseListBrute(head1);

    cout << "Brute Force: ";
    printList(head1);

    // Method 2: Optimal Iterative
    Node* head2 = createList(nums);

    head2 = sol.reverseListOptimalIterative(head2);

    cout << "Optimal Iterative: ";
    printList(head2);

    // Method 3: Optimal Recursive
    Node* head3 = createList(nums);

    head3 = sol.reverseListOptimalRecursive(head3);

    cout << "Optimal Recursive: ";
    printList(head3);

    return 0;
}