#ifndef DOUBLY_NODE_H
#define DOUBLY_NODE_H

#include <bits/stdc++.h>
using namespace std;

class DoublyNode {
public:
    int data;
    DoublyNode* prev;
    DoublyNode* next;

    DoublyNode(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }

    DoublyNode(int x, DoublyNode* prev, DoublyNode* next) {
        data = x;
        this->prev = prev;
        this->next = next;
    }
};

inline DoublyNode* createList(vector<int>& arr) {
    DoublyNode* head = nullptr;
    DoublyNode* temp = nullptr;

    for (int x : arr) {
        DoublyNode* newNode = new DoublyNode(x);

        if (head == nullptr) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

inline void printList(DoublyNode* head) {
    while (head != nullptr) {
        cout << head->data;

        if (head->next != nullptr) {
            cout << " <-> ";
        }

        head = head->next;
    }

    cout << '\n';
}

#endif
