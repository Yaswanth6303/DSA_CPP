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
    bool hasCycleBrute(Node *head) {
        unordered_set<Node*> nodes_set;
        Node* temp = head;

        while(temp != nullptr) {
            if(nodes_set.find(temp) != nodes_set.end()) {
                return true;
            }
            nodes_set.insert(temp);
            temp = temp->next; 
        }

        return false;
    }

    /**
     * Method 1: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    bool hasCycleOptimal(Node *head) {
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;  // Loop detected
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    vector<int> nums = {1, 2, 3, 4, 5};
    Node* head = createList(nums);

    // Create a cycle: 5 -> 3
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
    cout << "Brute Force: "
         << (sol.hasCycleBrute(head) ? "Cycle detected" : "No cycle")
         << '\n';

    // Method 2: Optimal Approach
    cout << "Optimal: "
         << (sol.hasCycleOptimal(head) ? "Cycle detected" : "No cycle")
         << '\n';

    return 0;
}