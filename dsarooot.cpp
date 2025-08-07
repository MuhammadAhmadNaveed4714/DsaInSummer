//#include<iostream>
//using namespace std;
//// Class Binary Tree
//class intbinarytree 
//{
//private:
//	struct treenode
//	{
//		int value;
//		treenode* left;
//		treenode* right;
//	};
//	treenode* root;
//	// Helper function to insert a new node
//	void insert(treenode*& nodeptr, treenode*& newnode)
//	{
//		if (nodeptr == nullptr)
//		{
//			nodeptr = newnode;
//		}
//		else if (newnode->value < nodeptr->value)
//		{
//			insert(nodeptr->left, newnode);
//		}
//		else
//		{
//			insert(nodeptr->right, newnode);
//		}
//	}
//
//	// Helper to destroy entire tree
//	void destroysubtree(treenode* nodeptr)
//	{
//		if (nodeptr != nullptr)
//		{
//			destroysubtree(nodeptr->left);
//			destroysubtree(nodeptr->right);
//			delete nodeptr;
//		}
//	}
//
//	// Helper to delete a node
//	void deletenode(int n, treenode*& t)
//	{
//		if (t == nullptr) 
//		{
//			cout << "\n\t\t\t\t\tValue " << n << " not found in tree.\n";
//			return;
//		}
//		if (n < t->value) 
//		{
//			deletenode(n, t->left);
//		}
//		else if (n > t->value)
//		{
//			deletenode(n, t->right);
//		}
//		else
//		{
//			makedeletion(t);
//		}
//	}
//
//	// Actual node deletion logic
//	void makedeletion(treenode*& nodeptr)
//	{
//		treenode* tempnodeptr = nullptr;
//
//		if (nodeptr == nullptr) 
//		{
//			cout << "\n\t\t\t\t\tCannot delete empty node.\n";
//		}
//		else if (nodeptr->left == nullptr)
//		{  // Only right or no child
//			tempnodeptr = nodeptr;
//			nodeptr = nodeptr->right;
//			delete tempnodeptr;
//		}
//		else if (nodeptr->right == nullptr) 
//		{ // Only left child
//			tempnodeptr = nodeptr;
//			nodeptr = nodeptr->left;
//			delete tempnodeptr;
//		}
//		else 
//		{ // Two children
//			treenode* successorParent = nodeptr;
//			treenode* successor = nodeptr->right;
//
//			// Find in-order successor
//			while (successor->left != nullptr)
//			{
//				successorParent = successor;
//				successor = successor->left;
//			}
//
//			nodeptr->value = successor->value; // Replace with successor value
//
//			// Recursively delete the successor
//			if (successorParent->left == successor)
//				deletenode(successor->value, successorParent->left);
//			else
//				deletenode(successor->value, successorParent->right);
//		}
//	}
//
//	// Display functions
//	void displayinorder(treenode* t) const
//	{
//		if (t != nullptr)
//		{
//			displayinorder(t->left);
//			cout << t->value << "\n";
//			displayinorder(t->right);
//		}
//	}
//	void displaypreorder(treenode* t) const 
//	{
//		if (t != nullptr)
//		{
//			cout << t->value << "\n";
//			displaypreorder(t->left);
//			displaypreorder(t->right);
//		}
//	}
//	void displaypostorder(treenode* t) const 
//	{
//		if (t != nullptr) 
//		{
//			displaypostorder(t->left);
//			displaypostorder(t->right);
//			cout << t->value << "\n";
//		}
//	}
//
//public:
//	// Constructor
//	intbinarytree()
//	{
//		root = nullptr;
//	}
//
//	// Destructor
//	~intbinarytree() 
//	{
//		destroysubtree(root);
//	}
//
//	// Public operations
//	void insertnode(int n) 
//	{
//		treenode* newnode = new treenode{ n, nullptr, nullptr };
//		insert(root, newnode);
//	}
//
//	bool searchnode(int n) 
//	{
//		treenode* nodeptr = root;
//		while (nodeptr != nullptr) 
//		{
//			if (nodeptr->value == n) 
//			{
//				return true;
//			}
//			else if (n < nodeptr->value)
//			{
//				nodeptr = nodeptr->left;
//			}
//			else 
//			{
//				nodeptr = nodeptr->right;
//			}
//		}
//		return false;
//	}
//
//	void remove(int n)
//	{
//		deletenode(n, root);
//	}
//
//	void displayinorder() const
//	{
//		displayinorder(root);
//	}
//	void displaypreorder() const
//	{
//		displaypreorder(root);
//	}
//	void displaypostorder() const
//	{
//		displaypostorder(root);
//	}
//};
//
//// MAIN FUNCTION
//int main() 
//{
//	intbinarytree tree;
//
//	cout << "\n\t\t\t\t\tInserting nodes.\n";
//	tree.insertnode(5);
//	tree.insertnode(15);
//	tree.insertnode(25);
//	tree.insertnode(35);
//
//	cout << "\n\t\t\t\t\tInorder traversal : \n";
//	tree.displayinorder();
//
//	cout << "\n\t\t\t\t\tPreorder traversal : \n";
//	tree.displaypreorder();
//
//	cout << "\n\t\t\t\t\tPostorder traversal : \n";
//	tree.displaypostorder();
//
//	if (tree.searchnode(15))
//	{
//		cout << "\n\t\t\t\t\t15 is found in tree.\n";
//	}
//	else 
//	{
//		cout << "\n\t\t\t\t\t15 is not found in tree.\n";
//	}
//
//	if (tree.searchnode(3)) 
//	{
//		cout << "\n\t\t\t\t\t3 is found in tree.\n";
//	}
//	else
//	{
//		cout << "\n\t\t\t\t\t3 is not found in tree.\n";
//	}
//
//	cout << "\n\t\t\t\t\tDeleting 5.\n";
//	tree.remove(5);
//
//	cout << "\n\t\t\t\t\tDeleting 35.\n";
//	tree.remove(35); // Should now handle gracefully
//
//	cout << "\n\t\t\t\t\tHere are the remaining nodes:\n";
//	tree.displayinorder();
//
//	return 0;
//}
