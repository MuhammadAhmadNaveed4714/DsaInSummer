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
        next = nullptr;
    }
};

// Function to rotate linked list left by k positions
Node* rotateLeft(Node* head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    // Find length of list
    int length = 1;
    Node* tail = head;

    while (tail->next != nullptr)
    {
        tail = tail->next;
        length++;
    }

    // Handle k greater than length
    k = k % length;

    if (k == 0)
        return head;

    // Find kth node
    Node* current = head;
    for (int i = 1; i < k; i++)
    {
        current = current->next;
    }

    Node* newHead = current->next;

    // Break the list
    current->next = nullptr;

    // Connect old tail to old head
    tail->next = head;

    return newHead;
}

// Insert at end
void insert(Node*& head, int val)
{
    Node* newNode = new Node(val);

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Display list
void display(Node* head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node* head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insert(head, x);
    }

    int k;
    cout << "Enter k: ";
    cin >> k;

    head = rotateLeft(head, k);

    cout << "Linked List after left rotation: ";
    display(head);

    return 0;
}