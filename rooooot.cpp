#include<iostream>
using namespace std;
class binarytree
{
private:
	struct treenode
	{
		int value;
		treenode* left;
		treenode* right;
	};
	treenode* root;
	void destroysubtree(treenode* root)
	{
		if (root != nullptr)
		{
			destroysubtree(root->left);
			destroysubtree(root->right);
			delete root;
		}
	}
	void insert(treenode*& root, treenode*& newnode)
	{
		if (root == nullptr)
		{
			root = newnode;
		}
		else if (newnode->value < root->value)
		{
			insert(root->left, newnode);
		}
		else if (newnode->value > root->value)
		{
			insert(root->right, newnode);
		}
	}
	void displaypreorder(treenode* t) const
	{
		if (t != nullptr)
		{
			cout << t->value << " ";
			displaypreorder(t->left);
			displaypreorder(t->right);
		}
	}
	void displayinorder(treenode* t) const
	{
		if (t != nullptr)
		{
			displayinorder(t->left);
			cout << t->value << " ";
			displayinorder(t->right);
		}
	}
	void displaypostorder(treenode* t) const
	{
		if (t != nullptr)
		{
			displaypostorder(t->left);
			displaypostorder(t->right);
			cout << t->value << " ";
		}
	}
	void deletenode(int n, treenode*& t)
	{
		if (t == nullptr)
		{
			cout << "\n\t\t\t\t\tValue is not found.\n";
			return;
		}
		if (n > t->value)
		{
			deletenode(n, t->right);
		}
		else if (n < t->value)
		{
			deletenode(n, t->left);
		}
		else
		{
			makedeletion(t);
		}
	}
	void makedeletion(treenode*& t)
	{
		treenode* temp = nullptr;
		if (t == nullptr)
		{
			cout << "\n\t\t\t\t\tCannot delete an empty road.\n";
		}
		else if (t->right == nullptr)
		{
			temp = t;
			t = t->left;
			delete temp;
		}
		else if (t->left == nullptr)
		{
			temp = t;
			t = t->right;
			delete temp;
		}
		else
		{
			treenode* parent = t;
			treenode* suc = t->right;
			while (t->left != nullptr)
			{
				parent = suc;
				suc = suc->left;
			}
			t->value = suc->value;
			if (parent->left == suc)
			{
				deletenode(suc->value, parent->left);
			}
			else
			{
				deletenode(suc->value, parent->right);
			}
		}
	}
public:
	binarytree()
	{
		root = nullptr;
	}
	~binarytree()
	{
		destroysubtree(root);
	}
	void insertnode(int n)
	{
		treenode* newnode = new treenode{n, nullptr, nullptr};
		insert(root, newnode);
	}
	void displayinpreorder()const
	{
		displaypreorder(root);
	}
	void displayininorder() const
	{
		displayinorder(root);
	}
	void displayinpostorder() const
	{
		displaypostorder(root);
	}
	bool searchnode(int n)
	{
		treenode* nodeptr = root;
		while (nodeptr != nullptr)
		{
			if (nodeptr->value == n)
			{
				return true;
			}
			else if (nodeptr->value > n)
			{
				nodeptr = nodeptr->left;
			}
			else if (nodeptr->value < n)
			{
				nodeptr = nodeptr->right;
			}
		}
		return false;
	}
	void remove(int n)
	{
		deletenode(n, root);
	}
};
int main()
{
	binarytree tree;
	cout << "\n\t\t\t\t\tInserting nodes in a tree.\n";
	tree.insertnode(50);
	tree.insertnode(10);
	tree.insertnode(40);
	tree.insertnode(30);
	tree.insertnode(0);
	cout << "\n\n\t\t\t\t\tPreorder Display   : ";
	tree.displayinpreorder();
	cout << "\n\n\t\t\t\t\tInorder Display    : ";
	tree.displayininorder();
	cout << "\n\n\t\t\t\t\tPostorder Display  : ";
	tree.displayinpostorder();
	cout << "\n\n\t\t\t\t\tSearch function    : ";
		if (tree.searchnode(40))
		{
			cout << " 40 is found in tree.\n";
		}
		else 
		{
			cout << " 40 is not found in tree.\n";
		}
		cout << "\n\t\t\t\t\tDeleting 50.\n";
		tree.remove(50);
		cout << "\n\t\t\t\t\tDeleting 30.\n";
		tree.remove(30); 
		cout << "\n\n\t\t\t\t\tInorder Display    : ";
		tree.displayininorder();
		cout << "\n";
	return 0;
}