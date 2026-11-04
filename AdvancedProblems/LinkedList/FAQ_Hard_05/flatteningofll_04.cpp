#include <bits/stdc++.h>
#include "../ChildNode.h"
using namespace std;

class Solution {
public:

    /**
     * Brute Force
     * TC: O(n log n)
     * SC: O(n)
     */
    ChildNode* flattenLinkedListBrute(ChildNode* &head) {
        if (head == nullptr) return nullptr;

        vector<int> values;

        ChildNode* temp = head;

        while (temp != nullptr) {
            ChildNode* childTemp = temp;

            while (childTemp != nullptr) {
                values.push_back(childTemp->data);
                childTemp = childTemp->child;
            }

            temp = temp->next;
        }

        sort(values.begin(), values.end());

        ChildNode* dummy = new ChildNode(-1);
        ChildNode* curr = dummy;

        for (int val : values) {
            curr->child = new ChildNode(val);
            curr = curr->child;
        }

        ChildNode* newHead = dummy->child;
        delete dummy;

        return newHead;
    }


    /**
     * Merge two sorted vertical lists
     */
    ChildNode* merge(ChildNode* a, ChildNode* b) {
        ChildNode dummy(-1);
        ChildNode* temp = &dummy;

        while (a != nullptr && b != nullptr) {
            ChildNode* selected;

            if (a->data <= b->data) {
                selected = a;
                a = a->child;
            } else {
                selected = b;
                b = b->child;
            }

            temp->child = selected;
            temp = selected;
            temp->next = nullptr;
        }

        ChildNode* remaining = (a != nullptr) ? a : b;

        temp->child = remaining;

        while (remaining != nullptr) {
            remaining->next = nullptr;
            remaining = remaining->child;
        }

        return dummy.child;
    }


    /**
     * Better Approach
     * TC: O(n * k)
     * SC: O(1)
     */
    ChildNode* flattenLinkedListBetter(ChildNode* &head) {
        if (head == nullptr) return nullptr;

        ChildNode* curr = head;

        while (curr->next != nullptr) {

            // Save the next horizontal list
            ChildNode* nextList = curr->next;
            ChildNode* remainingLists = nextList->next;

            // Detach both horizontal connections
            curr->next = nullptr;
            nextList->next = nullptr;

            // Merge the two sorted lists
            curr = merge(curr, nextList);

            // Preserve remaining horizontal lists
            curr->next = remainingLists;
        }

        return curr;
    }


    /**
     * Better Approach: Recursive merging
     * TC: O(n * k)
     * SC: O(k) recursion stack
     */
    ChildNode* flattenLinkedListBetter(ChildNode* &head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ChildNode* mergedHead = flattenLinkedListBetter(head->next);

        head->next = nullptr;

        return merge(head, mergedHead);
    }

    /**
     * Optimal Approach: Min Heap
     * TC: O(n log k)
     * SC: O(k)
     */
    ChildNode* flattenLinkedListOptimal(ChildNode* &head) {
        if (head == nullptr) return nullptr;

        auto cmp = [](ChildNode* a, ChildNode* b) {
            return a->data > b->data;
        };

        priority_queue<ChildNode*, vector<ChildNode*>, decltype(cmp)> pq(cmp);

        ChildNode* temp = head;

        while (temp != nullptr) {
            pq.push(temp);
            temp = temp->next;
        }

        ChildNode dummy(-1);
        ChildNode* tail = &dummy;

        while (!pq.empty()) {
            ChildNode* node = pq.top();
            pq.pop();

            if (node->child != nullptr) {
                pq.push(node->child);
            }

            tail->child = node;
            tail = node;

            node->next = nullptr;
        }

        tail->child = nullptr;

        return dummy.child;
    }
};

int main() {

    vector<vector<int>> lists = {
        {5, 7, 8, 30},
        {10, 20},
        {19, 22, 50},
        {28, 35, 40, 45}
    };

    Solution sol;

    ChildNode* head1 = nullptr;
    ChildNode* temp1 = nullptr;

    for (auto& nums : lists) {
        ChildNode* newList = createChildList(nums);

        if (head1 == nullptr) {
            head1 = newList;
            temp1 = head1;
        } else {
            temp1->next = newList;
            temp1 = temp1->next;
        }
    }

    cout << "Brute Force: ";
    head1 = sol.flattenLinkedListBrute(head1);
    printFlattenedList(head1);

    ChildNode* head2 = nullptr;
    ChildNode* temp2 = nullptr;

    for (auto& nums : lists) {
        ChildNode* newList = createChildList(nums);

        if (head2 == nullptr) {
            head2 = newList;
            temp2 = head2;
        } else {
            temp2->next = newList;
            temp2 = temp2->next;
        }
    }

    cout << "Better: ";
    head2 = sol.flattenLinkedListBetter(head2);
    printFlattenedList(head2);

    ChildNode* head3 = nullptr;
    ChildNode* temp3 = nullptr;

    for (auto& nums : lists) {
        ChildNode* newList = createChildList(nums);

        if (head3 == nullptr) {
            head3 = newList;
            temp3 = head3;
        } else {
            temp3->next = newList;
            temp3 = temp3->next;
        }
    }

    cout << "Optimal: ";
    head3 = sol.flattenLinkedListOptimal(head3);
    printFlattenedList(head3);

    return 0;
}