//#include<iostream>
//#include<string>
//using namespace std;
// Linked list class
//class assignmentlist
//{
//private:
//	struct assignmentnode
//	{
//		string studentname;
//		string rollnumber;
//		string assignmenttopic;
//		string submissiondate;
//		string status;
//		assignmentnode* next;
//	};
//	assignmentnode* head;
//public:
//	 Constructor
//	assignmentlist()
//	{
//		head = nullptr;
//	}
//	 Destructor
//	~assignmentlist()
//	{
//		assignmentnode* nodeptr;
//		assignmentnode* nextnode;
//		nodeptr = head;
//		while (nodeptr != nullptr)
//		{
//			nextnode = nodeptr->next;
//			delete nodeptr;
//			nodeptr = nextnode;
//		}
//	}
//	bool checkroll(string c)
//	{
//		bool status = false;
//		assignmentnode* ptr = head;
//		while (ptr != nullptr)
//		{
//			if (ptr->rollnumber == c)
//			{
//				status = true;
//				break;
//			}
//			ptr = ptr->next;
//		}
//		return status;
//	}
//	 Linked List Operations
//	void addstudent(string cname,string rnumber,string atopic,string sdate,string stat)
//	{
//		if (checkroll(rnumber))
//		{
//			cout << "\n\t\t\t\t\tEnter roll number again : ";
//			getline(cin, rnumber);
//			while (checkroll(rnumber))
//			{
//				cout << "\n\t\t\t\t\tEnter roll number again : ";
//				getline(cin, rnumber);
//			}
//			assignmentnode* newnode;
//			assignmentnode* nodeptr;
//			newnode = new assignmentnode;
//			newnode->studentname = cname;
//			newnode->rollnumber = rnumber;
//			newnode->assignmenttopic = atopic;
//			newnode->submissiondate = sdate;
//			newnode->status = stat;
//			newnode->next = nullptr;
//			if (head == nullptr)
//			{
//				head = newnode;
//			}
//			else
//			{
//				nodeptr = head;
//				while (nodeptr->next != nullptr)
//				{
//					nodeptr = nodeptr->next;
//				}
//				nodeptr->next = newnode;
//			}
//		}
//		else
//		{
//			assignmentnode* newnode;
//			assignmentnode* nodeptr;
//			newnode = new assignmentnode;
//			newnode->studentname = cname;
//			newnode->rollnumber = rnumber;
//			newnode->assignmenttopic = atopic;
//			newnode->submissiondate = sdate;
//			newnode->status = stat;
//			newnode->next = nullptr;
//			if (head == nullptr)
//			{
//				head = newnode;
//			}
//			else
//			{
//				nodeptr = head;
//				while (nodeptr->next != nullptr)
//				{
//					nodeptr = nodeptr->next;
//				}
//				nodeptr->next = newnode;
//			}
//		}
//	}
//	void updatestatus(string rnumber)
//	{
//		cin.ignore();
//		if (head == nullptr)
//		{
//			cout << "\n\t\t\t\t\tThere are no students.\n";
//			return;
//	    }
//		assignmentnode* nodeptr = head;
//		while (nodeptr != nullptr && nodeptr->rollnumber != rnumber)
//		{
//			nodeptr = nodeptr->next;
//		}
//		if (nodeptr == nullptr)
//		{
//			cout << "\n\t\t\t\t\tStudent having roll number  " << rnumber << " not found.\n";
//			return;
//		}
//		cout << "\n\t\t\t\t\tModifying status of student having rollnumber " << nodeptr->rollnumber << "\n";
//		cout << "\n\t\t\t\t\tEnter staus of assignment : ";
//		getline(cin, nodeptr->status);
//		cout << "\n\t\t\t\t\tStatus updated successfully.\n";
//	}
//	void searchbyrollnumber(string p)
//	{
//		cin.ignore();
//		if (head == nullptr)
//		{
//			cout << "\n\t\t\t\t\tThere is no student found.\n";
//			return;
//		}
//		assignmentnode* nodeptr = head;
//		while (nodeptr != nullptr && nodeptr->rollnumber != p)
//		{
//			nodeptr = nodeptr->next;
//		}
//		if (nodeptr == nullptr)
//		{
//			cout << "\n\t\t\t\t\tStudent having roll number " << p << " not found.\n";
//			return;
//		}
//		cout << "\n\t\t\t\t\tStudent having roll-number " << p << " is found successfully with name " << nodeptr->studentname << "\n";
//	}
//	void deletestudent(string d)
//	{
//		assignmentnode* nodeptr;
//	assignmentnode* previousnode=nullptr;
//		if (head == nullptr)
//		{
//			return;
//		}
//		if (head->rollnumber == d)
//		{
//			nodeptr = head->next;
//			delete head;
//			head = nodeptr;
//		}
//		else
//		{
//			nodeptr = head;
//			while (nodeptr != nullptr && nodeptr->rollnumber != d)
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
//	void displayallstudents() const
//	{
//		assignmentnode* nodeptr;
//		nodeptr = head;
//		if (head == nullptr)
//		{
//			cout << "\nThere are no students present.\n";
//			return;
//		}
//		while (nodeptr != nullptr)
//		{
//			cout <<"\n\t\t\t\t\tStudent name : " << nodeptr->studentname;
//			cout << "\n\t\t\t\t\tStudent rollnumber : " << nodeptr->rollnumber;
//			cout << "\n\t\t\t\t\tAssignment topic : " << nodeptr->assignmenttopic;
//			cout << "\n\t\t\t\t\tSubmission date : " << nodeptr->submissiondate;
//			cout << "\n\t\t\t\t\tAssignment status : " << nodeptr->status;
//			nodeptr = nodeptr->next;
//			cout << "\n";
//		}
//	}
//};
//int main()
//{
//	assignmentlist list;
//	string sname = "";
//	string srnumber = "";
//	string atopic = "";
//	string sdate = "";
//	string stat = "";
//	int choice = 0;
//	cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//	cout << "\n\t\t\t\t\t1. Add new student \n";
//	cout << "\n\t\t\t\t\t2. Delete a student record \n";
//	cout << "\n\t\t\t\t\t3. Modify the status\n";
//	cout << "\n\t\t\t\t\t4. Search for a student\n";
//	cout << "\n\t\t\t\t\t5. View all pending orders\n";
//	cout << "\n\t\t\t\t\t6. Exit\n";
//	cout << "\n\t\t\t\t\tEnter choice between 1 and 6: ";
//	cin >> choice;
//	while (choice < 0 || choice>6)
//	{
//		cout << "\n\t\t\t\t\tEnter choice between 1 and 6 : ";
//		cin >> choice;
//	}
//	while (choice != 6)
//	{
//		if (choice == 1)
//		{
//			cin.ignore();
//			cout << "\n\t\t\t\t\tEnter student name : ";
//			getline(cin, sname);
//			cout << "\n\t\t\t\t\tEnter roll number : ";
//			getline(cin, srnumber);
//			cout << "\n\t\t\t\t\tEnter assignment topic : ";
//			getline(cin, atopic);
//			cout << "\n\t\t\t\t\tEnter submission date : ";
//			getline(cin, sdate);
//			cout << "\n\t\t\t\t\tEnter status of submission : ";
//			getline(cin, stat);
//			list.addstudent(sname, srnumber, atopic, sdate,stat);
//			cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//			cout << "\n\t\t\t\t\t1. Add new student \n";
//			cout << "\n\t\t\t\t\t2. Delete a student record \n";
//			cout << "\n\t\t\t\t\t3. Modify the status\n";
//			cout << "\n\t\t\t\t\t4. Search for a student\n";
//			cout << "\n\t\t\t\t\t5. View all pending orders\n";
//			cout << "\n\t\t\t\t\t6. Exit\n";
//			cout << "\n\t\t\t\t\tEnter choice : ";
//			cin >> choice;
//		}
//		else if (choice == 2)
//		{
//			cin.ignore();
//			string y ="";
//			cout << "\n\t\t\t\t\tEnter roll number of a student who has dropped the course : ";
//			getline(cin,y);
//			list.deletestudent(y);
//			cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//			cout << "\n\t\t\t\t\t1. Add new student \n";
//			cout << "\n\t\t\t\t\t2. Delete a student record \n";
//			cout << "\n\t\t\t\t\t3. Modify the status\n";
//			cout << "\n\t\t\t\t\t4. Search for a student\n";
//			cout << "\n\t\t\t\t\t5. View all pending orders\n";
//			cout << "\n\t\t\t\t\t6. Exit\n";
//			cout << "\n\t\t\t\t\tEnter choice : ";
//			cin >> choice;
//		}
//		else if (choice == 3)
//		{
//			cin.ignore();
//			string y = "";
//			cout << "\n\t\t\t\t\tEnter rollnumber of a student whose status has to be upgraded : ";
//			getline(cin, y);
//			list.updatestatus(y);
//			cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//			cout << "\n\t\t\t\t\t1. Add new student \n";
//			cout << "\n\t\t\t\t\t2. Delete a student record \n";
//			cout << "\n\t\t\t\t\t3. Modify the status\n";
//			cout << "\n\t\t\t\t\t4. Search for a student\n";
//			cout << "\n\t\t\t\t\t5. View all pending orders\n";
//			cout << "\n\t\t\t\t\t6. Exit\n";
//			cout << "\n\t\t\t\t\tEnter choice : ";
//			cin >> choice;
//		}
//		else if (choice == 4)
//		{
//			cin.ignore();
//			string h = "";
//			cout << "\n\t\t\t\t\tEnter student roll number : ";
//			getline(cin, h);
//			list.searchbyrollnumber(h);
//			cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//			cout << "\n\t\t\t\t\t1. Add new student \n";
//			cout << "\n\t\t\t\t\t2. Delete a student record \n";
//			cout << "\n\t\t\t\t\t3. Modify the status\n";
//			cout << "\n\t\t\t\t\t4. Search for a student\n";
//			cout << "\n\t\t\t\t\t5. View all pending orders\n";
//			cout << "\n\t\t\t\t\t6. Exit\n";
//			cout << "\n\t\t\t\t\tEnter choice : ";
//			cin >> choice;
//		}
//		else if (choice == 5)
//		{
//			list.displayallstudents();
//			cout << "\n\t\t\t\t\t-- Assignment Submission System --\n";
//			cout << "\n\t\t\t\t\t1. Add new student \n";
//			cout << "\n\t\t\t\t\t2. Delete a student record \n";
//			cout << "\n\t\t\t\t\t3. Modify the status\n";
//			cout << "\n\t\t\t\t\t4. Search for a student\n";
//			cout << "\n\t\t\t\t\t5. View all students\n";
//			cout << "\n\t\t\t\t\t6. Exit\n";
//			cout << "\n\t\t\t\t\tEnter choice : ";
//			cin >> choice;
//		}
//	}
//	cout << "\n\t\t\t\t\tYou have exit the system.\n";
//	cout << "\n";
//	return 0;
//}