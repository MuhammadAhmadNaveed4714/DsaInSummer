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

// Display linked list
void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Delete last occurrence of key
void deleteLastOccurrence(Node*& head, int key)
{
    if (head == NULL)
        return;

    Node* temp = head;
    Node* last = NULL;
    Node* prevLast = NULL;
    Node* prev = NULL;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            last = temp;
            prevLast = prev;
        }
        prev = temp;
        temp = temp->next;
    }
    // Key not found
    if (last == NULL)
    {
        cout << "Key not found!" << endl;
        return;
    }
    // If last occurrence is first node
    if (prevLast == NULL)
    {
        head = head->next;
        delete last;
    }
    else
    {
        prevLast->next = last->next;
        delete last;
    }
}

int main()
{
    Node* head = NULL;

    // Creating Linked List
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 1);
    insert(head, 4);

    cout << "Original Linked List:\n";
    display(head);

    int key;
    cout << "\nEnter key to delete last occurrence: ";
    cin >> key;

    deleteLastOccurrence(head, key);

    cout << "\nLinked List after deletion:\n";
    display(head);

    return 0;
}