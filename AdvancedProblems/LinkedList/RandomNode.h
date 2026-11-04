#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>
using namespace std;

class RandomNode {
public:
    int data;
    RandomNode* next;
    RandomNode* random;

    RandomNode(int x) {
        data = x;
        next = nullptr;
        random = nullptr;
    }

    RandomNode(int x, RandomNode* next, RandomNode* r) {
        data = x;
        this->next = next;
        this->random = r;
    }
};


// Create linked list
inline RandomNode* createList(vector<int>& arr) {
    RandomNode* head = nullptr;
    RandomNode* temp = nullptr;

    for (int x : arr) {
        RandomNode* newNode = new RandomNode(x);

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


// Create sample list with random pointers
inline RandomNode* createSampleList(vector<int>& nums) {
    RandomNode* head = createList(nums);

    vector<RandomNode*> nodes;
    RandomNode* temp = head;

    while (temp != nullptr) {
        nodes.push_back(temp);
        temp = temp->next;
    }

    // Assign random pointers using indices
    if (nodes.size() >= 5) {
        nodes[0]->random = nodes[2];
        nodes[1]->random = nodes[0];
        nodes[2]->random = nodes[4];
        nodes[3]->random = nodes[2];
        nodes[4]->random = nodes[1];
    }

    return head;
}


// Print next and random pointers
inline void printRandomDetails(RandomNode* head) {
    while (head != nullptr) {
        cout << "Node: " << head->data << ", Random: ";

        if (head->random != nullptr) {
            cout << head->random->data;
        } else {
            cout << "NULL";
        }

        cout << '\n';
        head = head->next;
    }
}

#endif