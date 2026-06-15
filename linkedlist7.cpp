#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Delete last occurrence of key
void deleteLastOccurrence(Node*& head, int key) {
    if (head == NULL)
        return;

    Node* temp = head;
    Node* lastOcc = NULL;
    Node* prevLastOcc = NULL;
    Node* prev = NULL;

    while (temp != NULL) {
        if (temp->data == key) {
            lastOcc = temp;
            prevLastOcc = prev;
        }
        prev = temp;
        temp = temp->next;
    }

    // Key not found
    if (lastOcc == NULL)
        return;

    // If last occurrence is head
    if (prevLastOcc == NULL) {
        Node* del = head;
        head = head->next;
        delete del;
    }
    else {
        prevLastOcc->next = lastOcc->next;
        delete lastOcc;
    }
}

// Print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data;
        if (head->next != NULL)
            cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Example: 1 -> 2 -> 3 -> 1 -> 4
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 1);
    insert(head, 4);

    int key = 1;

    cout << "Original List: ";
    printList(head);

    deleteLastOccurrence(head, key);

    cout << "After deleting last occurrence of "
         << key << ": ";
    printList(head);

    return 0;
}