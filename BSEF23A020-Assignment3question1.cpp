#include<iostream>
#include<string>
using namespace std;
// Linked list class
class orderlist
{
private:
	struct ordernode
	{
		int ordernumber;
		string customername;
		string fooditemname;
		int quantityofitem;
		string instructions;
		ordernode* next;
	};
	ordernode* head;
	int counter;
public:
	// Constructor
	orderlist()
	{
		head = nullptr;
		counter = 0;
	}
	// Destructor
	~orderlist()
	{
		ordernode* nodeptr;
		ordernode* nextnode;
		nodeptr = head;
		while (nodeptr != nullptr)
		{
			nextnode = nodeptr->next;
			delete nodeptr;
			nodeptr = nextnode;
		}
	}
	// Linked List Operations
	void appendorder(string cname,string finame,int qoitem,string i)
	{
		counter++;
		ordernode* newnode;
		ordernode* nodeptr;
		newnode = new ordernode;
		newnode->ordernumber = counter;
		newnode->customername = cname;
		newnode->fooditemname = finame;
		newnode->quantityofitem = qoitem;
		newnode->instructions =i;
		newnode->next = nullptr;
		if (head == nullptr)
		{
			head = newnode;
		}
		else
		{
			nodeptr = head;
			while (nodeptr->next != nullptr)
			{
				nodeptr = nodeptr->next;
			}
			nodeptr->next = newnode;
		}
	}
	void modifyorderbyordernumber(int p)
	{
		cin.ignore();
		if (head == nullptr)
		{
			cout << "\n\t\t\t\t\tNo orders to modify.\n";
			return;
	    }
		ordernode* nodeptr = head;
		while (nodeptr != nullptr && nodeptr->ordernumber != p)
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr == nullptr)
		{
			cout << "\n\t\t\t\t\tOrder number " << p << " not found.\n";
			return;
		}
		cout << "\n\t\t\t\t\tModifying order # " << nodeptr->ordernumber << "\n";
		cout << "\n\t\t\t\t\tEnter new food item name : ";
		getline(cin, nodeptr->fooditemname);
		cout << "\n\t\t\t\t\tEnter new quantity : ";
		cin >> nodeptr->quantityofitem;
		cout << "\n\t\t\t\t\tOrder updated successfully.\n";
	}
	void searchbycustomername(string p,int on)
	{
		cin.ignore();
		if (head == nullptr)
		{
			cout << "\n\t\t\t\t\tThere is no customer found.\n";
			return;
		}
		ordernode* nodeptr = head;
		while (nodeptr != nullptr && (nodeptr->customername != p && nodeptr->ordernumber != on))
		{
			nodeptr = nodeptr->next;
		}
		if (nodeptr == nullptr)
		{
			cout << "\n\t\t\t\t\tCustomer name : " << p << " not found.\n";
			return;
		}
		cout << "\n\t\t\t\t\tCustomer name " << p << " found at order # " << nodeptr->ordernumber << " successfully.\n";
	}
	void cancelorder(int d)
	{
		ordernode* nodeptr;
		ordernode* previousnode=nullptr;
		if (head == nullptr)
		{
			return;
		}
		if (head->ordernumber == d)
		{
			nodeptr = head->next;
			delete head;
			head = nodeptr;
		}
		else
		{
			nodeptr = head;
			while (nodeptr != nullptr && nodeptr->ordernumber != d)
			{
				previousnode = nodeptr;
				nodeptr = nodeptr->next;
			}
			if (nodeptr != nullptr)
			{
				previousnode->next = nodeptr->next;
				delete nodeptr;
			}
		}
	}
	void serveorder()
	{
		ordernode* nodeptr;
		ordernode* previousnode = nullptr;
		if (head == nullptr)
		{
			cout << "\n\t\t\t\t\tThere are no orders to be served.\n";
			return;
		}
		cout << "\n\t\t\t\t\tOrder # " << head->ordernumber << " served successfully.\n";
		nodeptr = head->next;
		delete head;
	    head = nodeptr;
	}
	void displayorder() const
	{
		ordernode* nodeptr;
		nodeptr = head;
		while (nodeptr != nullptr)
		{
			cout <<"\n\t\t\t\t\tOrder Number : " << nodeptr->ordernumber;
			cout << "\n\t\t\t\t\tCustomer Name : " << nodeptr->customername;
			cout << "\n\t\t\t\t\tFood item name : " << nodeptr->fooditemname;
			cout << "\n\t\t\t\t\tQuantity of items : " << nodeptr->quantityofitem;
			cout << "\n\t\t\t\t\tSpecial instructions : " << nodeptr->instructions;
			nodeptr = nodeptr->next;
			cout << "\n";
		}
	}
};
int main()
{
	orderlist list;
	int on = 0;
	string cn = "";
	string fin = "";
	int qoi = 0;
	string i = "";
	int choice = 0;
	cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
	cout << "\n\t\t\t\t\t1. Add new order \n";
	cout << "\n\t\t\t\t\t2. Serve earliest order \n";
	cout << "\n\t\t\t\t\t3. Search by customer name \n";
	cout << "\n\t\t\t\t\t4. Modify an order\n";
	cout << "\n\t\t\t\t\t5. Cancel an order\n";
	cout << "\n\t\t\t\t\t6. View all pending orders\n";
	cout << "\n\t\t\t\t\t7. Exit\n";
	cout << "\n\t\t\t\t\tEnter choice : ";
	cin >> choice;
	while (choice != 7)
	{
		if (choice == 1)
		{
			cin.ignore();
			cout << "\n\t\t\t\t\tEnter customer name : ";
			getline(cin, cn);
			cout << "\n\t\t\t\t\tEnter food item name : ";
			getline(cin, fin);
			cout << "\n\t\t\t\t\tEnter quantity of items : ";
			cin >> qoi;
			cin.ignore();
			cout << "\n\t\t\t\t\tEnter special instruction : ";
			getline(cin, i);
			list.appendorder(cn, fin, qoi, i);
			cout << "\n\t\t\t\t\tOrder added successfully.\n";
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
		else if (choice == 2)
		{
			list.serveorder();
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
		else if (choice == 3)
		{
			cin.ignore();
			string h = "";
			cout << "\n\t\t\t\t\tEnter customer name : ";
			getline(cin, h);
			int t = 0;
			cout << "\n\t\t\t\t\tEnter order number : ";
			cin >> t;
			list.searchbycustomername(h,t);
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
		else if (choice == 4)
		{
			int y = 0;
			cout << "\n\t\t\t\t\tEnter order number : ";
			cin >> y;
			list.modifyorderbyordernumber(y);
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
		else if (choice == 5)
		{
			int y = 0;
			cout << "\n\t\t\t\t\tEnter order number : ";
			cin >> y;
			list.cancelorder(y);
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
		else if (choice == 6)
		{
			cout << "\n\t\t\t\t\tTotal orders : \n";
			list.displayorder();
			cout << "\n\t\t\t\t\t-- Restaurant Order System --\n";
			cout << "\n\t\t\t\t\t1. Add new order \n";
			cout << "\n\t\t\t\t\t2. Serve earliest order \n";
			cout << "\n\t\t\t\t\t3. Search by customer name \n";
			cout << "\n\t\t\t\t\t4. Modify an order\n";
			cout << "\n\t\t\t\t\t5. Cancel an order\n";
			cout << "\n\t\t\t\t\t6. View all pending orders\n";
			cout << "\n\t\t\t\t\t7. Exit\n";
			cout << "\n\t\t\t\t\tEnter choice : ";
			cin >> choice;
		}
	}
	cout << "\n\t\t\t\t\tYou have exit the system.\n";
	cout << "\n";
	return 0;
}