#include <iostream>
#include <stack>

using namespace std;

struct Node{
    Node()
        : left (nullptr)
        , right(nullptr)
    {}

    Node* left;
    Node* right;
};

int depth(Node* node){

    if (!node)
        return 0;

    int lDepth = 1 + depth(node->left );
    int rDepth = 1 + depth(node->right);

    return lDepth > rDepth ? lDepth : rDepth;
}

int main()
{
    Node root;

    root.left             = new Node;
    root.right            = new Node;

    root.left->left       = new Node;
    root.left->left->left = new Node;

    cout << depth(&root) << endl;

    return 0;
}
