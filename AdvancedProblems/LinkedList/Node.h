#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }

    Node(int x, Node* next) {
        data = x;
        this->next = next;
    }
};

inline Node* createList(vector<int>& arr) {
    Node* head = nullptr;
    Node* temp = nullptr;

    for (int x : arr) {
        Node* newNode = new Node(x);

        if (head == nullptr) {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    return head;
}

inline void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data;

        if (head->next != nullptr) {
            cout << " -> ";
        }

        head = head->next;
    }

    cout << '\n';
}

#endif
