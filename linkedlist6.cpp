#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insert(Node*& head, int val)
{
    Node* newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Find kth node from end
int kthFromEnd(Node* head, int k)
{
    Node* first = head;
    Node* second = head;

    // Move first pointer k steps ahead
    for (int i = 0; i < k; i++)
    {
        if (first == NULL)
            return -1;

        first = first->next;
    }

    // Move both pointers together
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }

    return second->data;
}

int main()
{
    Node* head = NULL;

    // Linked List: 1 -> 2 -> 3 -> 4
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    int k = 3;

    cout << "Kth node from end: " << kthFromEnd(head, k) << endl;

    return 0;
}