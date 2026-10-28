#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(n + m)
     * SC: O(n)
     */
    Node* getIntersectionNodeBrute(Node *headA, Node *headB) {
        unordered_set<Node*> nodes_set;

        while (headA != nullptr) {
            nodes_set.insert(headA);
            headA = headA->next;
        }

        while (headB != nullptr) {
            if(nodes_set.find(headB) != nodes_set.end()) {
                return headB;
            }
            headB = headB->next;
        }
        
        return nullptr;
    }

    /**
     * Method 2: Better Approach
     * TC: O(n + m)
     * SC: O(1)
     */
    Node* getIntersectionNodeBetter(Node *headA, Node *headB) {
        Node* temp1 = headA;
        Node* temp2 = headB;

        int l1 = 0;
        int l2 = 0;

        while (temp1 != nullptr) {
            l1 += 1;
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            l2 += 1;
            temp2 = temp2 -> next;
        }
        
        if(l1 < l2) return collisionPoint(headA, headB, l2 - l1);
        return collisionPoint(headB, headA, l1 - l2);
    }

private:
    Node* collisionPoint(Node* shorterListHead, Node* longerListHead, int length) {
        Node* temp1 = shorterListHead;
        Node* temp2 = longerListHead;

        for (int i = 0; i < length; i++) {
            temp2 = temp2->next;
        }

        while (temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return temp1;
    };

public:
    /**
     * Method 3: Optimal Approach
     * TC: 
     * SC: 
     */
    Node* getIntersectionNodeOptimal(Node *headA, Node *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        Node* temp1 = headA;
        Node* temp2 = headB;

        while(temp1 != temp2) {
            temp1 = (temp1 == nullptr) ? headB : temp1->next;
            temp2 = (temp2 == nullptr) ? headA : temp2->next;
        }

        return temp1;
    }
};

int main() {
    Solution sol;

    // Create the first list: 1 -> 2 -> 3 -> 8 -> 9
    vector<int> nums1 = {1, 2, 3};
    Node* headA = createList(nums1);

    // Create the second list: 4 -> 5 -> 8 -> 9
    vector<int> nums2 = {4, 5};
    Node* headB = createList(nums2);

    // Create the shared intersection: 8 -> 9
    vector<int> numsCommon = {8, 9};
    Node* common = createList(numsCommon);

    // Connect both lists to the same nodes
    Node* tempA = headA;
    while (tempA->next != nullptr) {
        tempA = tempA->next;
    }
    tempA->next = common;

    Node* tempB = headB;
    while (tempB->next != nullptr) {
        tempB = tempB->next;
    }
    tempB->next = common;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    // Method 1: Brute Force
    Node* intersection1 = sol.getIntersectionNodeBrute(headA, headB);
    cout << "Brute Force Intersection: ";
    if (intersection1) cout << intersection1->data << '\n';
    else cout << "No intersection\n";

    // Method 2: Better Approach
    Node* intersection2 = sol.getIntersectionNodeBetter(headA, headB);
    cout << "Better Approach Intersection: ";
    if (intersection2) cout << intersection2->data << '\n';
    else cout << "No intersection\n";

    // Method 3: Optimal Approach
    Node* intersection3 = sol.getIntersectionNodeOptimal(headA, headB);
    cout << "Optimal Approach Intersection: ";
    if (intersection3) cout << intersection3->data << '\n';
    else cout << "No intersection\n";

    return 0;
}