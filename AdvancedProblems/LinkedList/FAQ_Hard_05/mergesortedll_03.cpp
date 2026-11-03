#include <bits/stdc++.h>
#include "../Node.h"
using namespace std;

class Solution {
public:

    /**
     * Method 1: Brute Force
     * TC: O(n1 + n2) + O(n log n) + O(n)
     * SC: O(n) + O(n)
     */
    Node* mergeTwoListsBrute(Node* list1, Node* list2) {
        vector<int> nums;
        Node* temp1 = list1;
        Node* temp2 = list2;

        while (temp1 != nullptr) {
            nums.push_back(temp1->data);
            temp1 = temp1->next;
        }

        while (temp2 != nullptr) {
            nums.push_back(temp2->data);
            temp2 = temp2->next;
        }

        sort(nums.begin(), nums.end());
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;
        for(int i = 0; i < nums.size(); i++){
            temp->next = new Node(nums[i]); 
            temp = temp->next; 
        }
 
        return dummyNode->next;
    }

    /**
     * Method 2: Optimal Approach
     * TC: O(n1 + n2)
     * SC: O(1)
     */
    Node* mergeTwoListsOptimal(Node* list1, Node* list2) {
        Node* dummyNode = new Node(-1);
        Node* temp = dummyNode;

        while (list1 != nullptr && list2 != nullptr) {
            if(list1->data <= list2->data) {
                temp->next = list1;
                list1 = list1->next;
            } else {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }

        if (list1 != nullptr) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        
        return dummyNode->next;
    }
};

int main() {
    vector<int> nums1 = {1, 3, 5};
    vector<int> nums2 = {2, 4, 6};

    // Create two sorted linked lists
    Node* list1 = createList(nums1);
    Node* list2 = createList(nums2);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Solution sol;

    // Test Brute Force
    Node* bruteResult = sol.mergeTwoListsBrute(list1, list2);

    cout << "\nBrute Force Result: ";
    printList(bruteResult);

    // Recreate lists for optimal approach
    list1 = createList(nums1);
    list2 = createList(nums2);

    // Test Optimal Approach
    Node* optimalResult = sol.mergeTwoListsOptimal(list1, list2);

    cout << "Optimal Result: ";
    printList(optimalResult);

    return 0;
}