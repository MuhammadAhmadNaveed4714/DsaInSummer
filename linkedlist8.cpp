#include <iostream>
using namespace std;

// Node structure
class Node
{
public:
    int data;
    Node* next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Insert node at end of Circular Linked List
void insert(Node* &head, int value)
{
    Node* newNode = new Node(value);

    // If list is empty
    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    // Go to last node
    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

// Traverse Circular Linked List
void printList(Node* head)
{
    if(head == NULL)
    {
        cout << "List is empty";
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while(temp != head);

    cout << endl;
}

int main()
{
    Node* head = NULL;

    insert(head, 1);
    insert(head, 7);
    insert(head, 8);
    insert(head, 10);

    cout << "Circular Linked List: ";
    printList(head);

    return 0;
}