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
    int findLengthOfLoopBrute(Node* head) {
        Node* temp = head;
        unordered_map<Node*, int> map;

        int count = 0;
        while(temp != nullptr) {
            if(map.find(temp) != map.end()) {
                int loopLength = count - map[temp];
                return loopLength;
            }

            map[temp] = count;
            count += 1;
            temp = temp->next;
        }
        
        return 0;
    }

    int findLength(Node* slow, Node* fast) {
        int count = 1;
        fast = fast->next;

        while (slow != fast) {
            count++;
            fast = fast->next;
        }

        return count;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n)
     * SC: O(1)
     */
    int findLengthOfLoopOptimal(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return findLength(slow, fast);
            }
        }

        return 0;
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
    cout << "Brute Force Loop Length: "
         << sol.findLengthOfLoopBrute(head) << '\n';

    // Method 2: Optimal Approach
    cout << "Optimal Loop Length: "
         << sol.findLengthOfLoopOptimal(head) << '\n';

    return 0;
}