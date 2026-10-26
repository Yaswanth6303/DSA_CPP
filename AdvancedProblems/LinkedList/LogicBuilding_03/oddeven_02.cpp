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
        if(head == nullptr && head->next == nullptr) return nullptr;

        vector<int> result;
        Node* temp = head;

        while (temp != nullptr && temp->next != nullptr) {
            result.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp != nullptr) result.push_back(temp->data);

        temp = head->next;
        while (temp != nullptr && temp->next != nullptr) {
            result.push_back(temp->data);
            temp = temp->next->next;
        }
        if(temp != nullptr) result.push_back(temp->data);
        
        int i = 0;
        temp = head;
        
        while (temp != nullptr) {
            temp->data = result[i];
            temp = temp->next;
            i++;
        }

        return head;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    Node* oddEvenListOptimal(Node* &head) {
        if(head == nullptr && head->next == nullptr) return nullptr;

        Node* odd = head;
        Node* even = head->next;
        Node* firstEven = head->next;

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

    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    cout << "Original List: ";
    Node* temp = head1;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Method 1: Brute Force
    sol.oddEvenListBrute(head1);

    cout << "Brute Force: ";
    temp = head1;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Create a separate list for the optimal method
    Node* head2 = new Node(1);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(5);

    // Method 2: Optimal
    sol.oddEvenListOptimal(head2);

    cout << "Optimal: ";
    temp = head2;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}
