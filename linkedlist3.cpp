#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = nullptr;
        next = nullptr;
    }
};

// Function to reverse Doubly Linked List
Node* reverseDLL(Node* head) {
    // Empty list or single node
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    Node* current = head;
    Node* temp = nullptr;
    while (current != nullptr) {
        // Swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        // Move to next node
        current = current->prev;
    }
    // Update head
    head = temp->prev;
    return head;
}

// Function to print Doubly Linked List
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data;

        if (temp->next != nullptr) {
            cout << " <-> ";
        }

        temp = temp->next;
    }

    cout << endl;
}

int main() {

    // Creating Doubly Linked List:
    // 1 <-> 2 <-> 3 <-> 4

    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;

    second->prev = head;
    second->next = third;

    third->prev = second;
    third->next = fourth;

    fourth->prev = third;

    cout << "Original Doubly Linked List:" << endl;
    printList(head);

    // Reverse the list
    head = reverseDLL(head);

    cout << "Reversed Doubly Linked List:" << endl;
    printList(head);

    return 0;
}