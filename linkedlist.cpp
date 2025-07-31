#include<iostream>
using namespace std;
class Node
{
	int data;
	Node* next;
public:
	Node(int val = 0, Node* nxt = nullptr)
	{
		data = val;
		next = nxt;
	}
	void setNext(Node* nod)
	{
		next = nod;
	}
	Node* getNext()
	{
		return next;
	}
	int getVal()
	{
		return data;
	}
};
class List
{
	Node* head;
	Node* tail;
public:
	List()
	{
		head = nullptr;
		tail = nullptr;
	}
	void addToHead(int element)
	{
		head = new Node(element, head);
		if (tail == nullptr)
		{
			tail = head;
		}
	}
	void addToTail(int element)
	{
		if (head == NULL && tail == NULL)
		{
			head = new Node(element);
			tail = new Node(element);
		}
		else
		{
			Node* setNode = new Node(element);
			tail->setNext(setNode);
			tail = tail->getNext();
		}
	}
	void print()
	{
		Node* print = head;
		while (print != nullptr)
		{
			cout << print->getVal() << "\t";
			print = print->getNext();
		}
	}
};
int main()
{
	List Nod;
	Nod.addToHead(15);
	Nod.addToHead(6);
	Nod.addToTail(3);
	Nod.addToTail(10);
	cout << "\n";
	Nod.print();
	cout << "\n";
	return 0;
}