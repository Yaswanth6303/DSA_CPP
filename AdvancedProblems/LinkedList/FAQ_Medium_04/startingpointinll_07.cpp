#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(n)
     * SC: O(n)
     */
    Node* findStartingPointBrute(Node *head) {
        Node* temp = head;
        unordered_map<Node*, int> map;

        while(temp != nullptr) {
            if(map.count(temp) != 0) return temp;
            map[temp] = 1;
            temp = temp->next;
        }

        return nullptr;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    Node* findStartingPointOptimal(Node* head) {
        Node* slow = head;
        Node* fast = head;

        // Step 1: Detect cycle
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // Step 2: Reset slow to head
                slow = head;

                // Step 3: Find cycle starting point
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return nullptr;
    }
};

int main() {
    Solution sol;

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = createList(nums);

    // Create cycle: 5 -> 3
    Node* temp = head;
    Node* cycleNode = nullptr;

    while (temp->next != nullptr) {
        if (temp->data == 3) {
            cycleNode = temp;
        }
        temp = temp->next;
    }

    temp->next = cycleNode;

    // Method 1: Brute Force
    Node* result1 = sol.findStartingPointBrute(head);

    cout << "Brute Force: ";
    if (result1 != nullptr) {
        cout << result1->data << '\n';
    } else {
        cout << "No cycle found\n";
    }

    // Method 2: Optimal Approach
    Node* result2 = sol.findStartingPointOptimal(head);

    cout << "Optimal: ";
    if (result2 != nullptr) {
        cout << result2->data << '\n';
    } else {
        cout << "No cycle found\n";
    }

    return 0;
}