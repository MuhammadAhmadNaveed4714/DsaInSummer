#include <iostream>
using namespace std;

class Node
{
  public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};


Node *pairwiseSwap(Node *head)
{
    Node *curr = head;

    
    while (curr != nullptr && curr->next != nullptr)
    {

    
        swap(curr->data, curr->next->data);

        
        curr = curr->next->next;
    }
    return head;
}
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{

    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    pairwiseSwap(head);

    printList(head);

    return 0;
}