#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

class ChildNode {
public:
    int data;
    ChildNode* next;
    ChildNode* child;

    ChildNode(int x) {
        data = x;
        next = nullptr;
        child = nullptr;
    }

    ChildNode(int x, ChildNode* next, ChildNode* child) {
        data = x;
        this->next = next;
        this->child = child;
    }
};

// Create vertical list
inline ChildNode* createChildList(vector<int> arr) {
    ChildNode* head = nullptr;
    ChildNode* temp = nullptr;

    for (int x : arr) {
        ChildNode* node = new ChildNode(x);

        if (head == nullptr) {
            head = node;
            temp = node;
        } else {
            temp->child = node;
            temp = node;
        }
    }

    return head;
}

// Print flattened list
inline void printFlattenedList(ChildNode* head) {
    while (head != nullptr) {
        cout << head->data;

        if (head->child != nullptr)
            cout << " -> ";

        head = head->child;
    }

    cout << '\n';
}

#endif