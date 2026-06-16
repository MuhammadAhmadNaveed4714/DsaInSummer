#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to find height (in terms of edges)
int height(Node* root) {
    if (root == NULL)
        return -1;

    return 1 + max(height(root->left), height(root->right));
}

int main() {
    /*
            1
           / \
          2   3
         / \
        4   5

        Height = 2 edges
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Height of Binary Tree: " << height(root) << endl;

    return 0;
}