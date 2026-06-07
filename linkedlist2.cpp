#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Function to reverse the linked list
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* nextNode = nullptr;

    while (curr != nullptr) {
        nextNode = curr->next; // Store next node
        curr->next = prev;     // Reverse link
        prev = curr;           // Move prev forward
        curr = nextNode;       // Move curr forward
    }

    return prev; // New head
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr)
            cout << " -> ";

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    // Creating linked list:
    // 1 -> 2 -> 3 -> 4 -> 5

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    printList(head);

    return 0;
}