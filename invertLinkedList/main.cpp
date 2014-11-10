#include <iostream>

using namespace std;

struct Node {
    Node() : next(nullptr), i(0) {}
    Node* next;
    int   i;
};

Node* invert(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr){
        next       = curr->next;
        curr->next = prev;
        prev       = curr;
        curr       = next;
    }

    return prev;
}

int main()
{
    Node root;
    cout << root.i;
    Node** node = &root.next;
    for (int i = 1; i < 10; ++i){
        *node    = new Node;
        (*node)->i = i;
        cout << " " << (*node)->i;
        node    = &(*node)->next;
    }
    cout << endl;

    Node* newHead = invert(&root);

    Node* next = newHead;
    while (next){
        cout << next->i << " ";
        next = next->next;
    }
    cout << endl;

    return 0;
}

