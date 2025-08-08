//#include<iostream>
//using namespace std;
//// Linked list class
//class numberlist
//{
//private:
//	struct listnode
//	{
//		double value;
//		listnode* next;
//	};
//	listnode* head;
//	int counter;
//public:
//	// Constructor
//	numberlist()
//	{
//		head = nullptr;
//		counter = 0;
//	}
//	// Destructor
//	~numberlist()
//	{
//		listnode* nodeptr;
//		listnode* nextnode;
//		nodeptr = head;
//		while (nodeptr != nullptr)
//		{
//			nextnode = nodeptr->next;
//			delete nodeptr;
//			nodeptr = nextnode;
//		}
//	}
//	// Linked List Operations
//	void appendnode(double d)
//	{
//		counter++;
//		listnode* newnode;
//		listnode* nodeptr;
//		newnode = new listnode;
//		newnode->value = d;
//		newnode->next = nullptr;
//		if (head == nullptr)
//		{
//			head = newnode;
//		}
//		else
//		{
//			nodeptr = head;
//			while (nodeptr->next != nullptr)
//			{
//				nodeptr = nodeptr->next;
//			}
//			nodeptr->next = newnode;
//		}
//	}
//	void insertnode(double d)
//	{
//		listnode* newnode;
//		listnode* nodeptr;
//		listnode* previousnode = nullptr;
//		newnode = new listnode;
//		newnode->value = d;
//		if (head == nullptr)
//		{
//			head = newnode;
//			newnode->next = nullptr;
//		}
//		else
//		{
//			nodeptr = head;
//			while (nodeptr != nullptr && nodeptr->value < d)
//			{
//				previousnode = nodeptr;
//				nodeptr = nodeptr->next;
//			}
//			if (previousnode == nullptr)
//			{
//				head = newnode;
//				newnode->next = nodeptr;
//			}
//			else
//			{
//				previousnode->next = newnode;
//				newnode->next = nodeptr;
//			}
//		}
//	}
//	void insertnodeatposition(double d,int p)
//	{
//		if (p < 1)
//		{
//			cout << "\n\t\t\t\t\tInvalid position.\n";
//			return;
//		}
//		listnode* newnode = new listnode;
//		newnode->value = d;
//		newnode->next = nullptr;
//		if (p == 1)
//		{
//			newnode->next = head;
//			head = newnode;
//		}
//		listnode* nodeptr = head;
//		listnode* previousnode = nullptr;
//		for (int i = 0; i < p - 1 && nodeptr != nullptr; i++)
//		{
//				previousnode = nodeptr;
//				nodeptr = nodeptr->next;
//		}
//		if (previousnode == nullptr)
//		{
//			cout << "\n\t\t\t\t\tPosition out of rangr.\n";
//			delete newnode;
//			return;
//		}
//		previousnode->next = newnode;
//		newnode->next = nodeptr;
//		counter++;
//	}
//	void deletenode(double d)
//	{
//		listnode* nodeptr;
//		listnode* previousnode=nullptr;
//		if (head == nullptr)
//		{
//			return;
//		}
//		if (head->value == d)
//		{
//			nodeptr = head->next;
//			delete head;
//			head = nodeptr;
//		}
//		else
//		{
//			nodeptr = head;
//			while (nodeptr != nullptr && nodeptr->value != d)
//			{
//				previousnode = nodeptr;
//				nodeptr = nodeptr->next;
//			}
//			if (nodeptr != nullptr)
//			{
//				previousnode->next = nodeptr->next;
//				delete nodeptr;
//			}
//		}
//	}
//	void displaylist() const
//	{
//		listnode* nodeptr;
//		nodeptr = head;
//		while (nodeptr != nullptr)
//		{
//			cout << nodeptr->value << "\n";
//			nodeptr = nodeptr->next;
//		}
//	}
//};
//int main()
//{
//	double v = 0;
//	int p = 0;
//	numberlist list;
//	list.appendnode(2.5);
//	list.appendnode(6.5);
//	list.appendnode(8.5);
//	list.appendnode(12.5);
//	list.appendnode(16.5);
//	cout << "\n\t\t\t\t\tInitial values : \n";
//	list.displaylist();
//	cout << "\n\t\t\t\t\tEnter position : ";
//	cin >> p;
//	cout << "\n\t\t\t\t\tValue you want to insert : \n";
//	cin >> v;
//	list.insertnodeatposition(v,p);
//	cout << "\n\t\t\t\t\tDisplay of nodes : \n";
//	list.displaylist();
//	return 0;
//}