#include <bits/stdc++.h>
#include "../RandomNode.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force (HashMap)
     * TC: O(n) 
     * SC: O(n)
     */
    RandomNode* copyRandomListBrute(RandomNode* head) {
        if (head == nullptr) return nullptr;

        unordered_map<RandomNode*, RandomNode*> nodesMap;

        RandomNode* temp = head;

        // Pass 1: Create cloned nodes
        while (temp != nullptr) {
            RandomNode* newNode = new RandomNode(temp->data);
            nodesMap[temp] = newNode;
            temp = temp->next;
        }

        // Pass 2: Assign next and random pointers
        temp = head;

        while (temp != nullptr) {
            RandomNode* copyNode = nodesMap[temp];

            copyNode->next = nodesMap[temp->next];
            copyNode->random = nodesMap[temp->random];

            temp = temp->next;
        }

        return nodesMap[head];
    }


    /**
     * Helper 1: Insert cloned nodes between original nodes
     */
    void insertCopyNodes(RandomNode* head) {
        RandomNode* temp = head;

        while (temp != nullptr) {
            RandomNode* copyNode = new RandomNode(temp->data);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }
    }


    /**
     * Helper 2: Assign random pointers to cloned nodes
     */
    void connectRandomPointers(RandomNode* head) {
        RandomNode* temp = head;

        while (temp != nullptr) {
            RandomNode* copyNode = temp->next;

            if (temp->random != nullptr) {
                copyNode->random = temp->random->next;
            } else {
                copyNode->random = nullptr;
            }

            temp = copyNode->next;
        }
    }


    /**
     * Helper 3: Separate original and cloned lists
     */
    RandomNode* getDeepCopy(RandomNode* head) {
        RandomNode dummy(-1);
        RandomNode* copyTail = &dummy;

        RandomNode* temp = head;

        while (temp != nullptr) {
            RandomNode* copyNode = temp->next;

            // Restore original list
            temp->next = copyNode->next;

            // Build cloned list
            copyTail->next = copyNode;
            copyTail = copyNode;

            temp = temp->next;
        }

        return dummy.next;
    }


    /**
     * Method 2: Optimal Approach (Three Pass)
     * TC: O(n)
     * SC: O(1) auxiliary space
     */
    RandomNode* copyRandomListOptimal(RandomNode* head) {
        if (head == nullptr) return nullptr;

        // Pass 1: Insert cloned nodes
        insertCopyNodes(head);

        // Pass 2: Assign random pointers
        connectRandomPointers(head);

        // Pass 3: Separate original and cloned lists
        return getDeepCopy(head);
    }
};

int main() {
    vector<int> nums = {7, 13, 11, 10, 1};

    Solution sol;
    RandomNode* head1 = createSampleList(nums);

    cout << "Original List (Brute Force):\n";
    printRandomDetails(head1);

    RandomNode* copy1 = sol.copyRandomListBrute(head1);

    cout << "\nBrute Force Copy:\n";
    printRandomDetails(copy1);

    RandomNode* head2 = createSampleList(nums);

    cout << "\nOriginal List (Optimal):\n";
    printRandomDetails(head2);

    RandomNode* copy2 = sol.copyRandomListOptimal(head2);

    cout << "\nOptimal Copy:\n";
    printRandomDetails(copy2);

    cout << "\nOriginal List After Copy (Restored):\n";
    printRandomDetails(head2);

    return 0;
}
