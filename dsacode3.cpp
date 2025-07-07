#include<iostream>
using namespace std;
// Struct node
struct node
{
	int coef;
	int expo;
	node* next;
};
// Create function
node* createNode(int coef, int expo)
{
	node* newNode = new node;
	newNode->coef = coef;
	newNode->expo = expo;
	newNode->next = nullptr;
	return newNode;
}
// Insert function
void insert(node*& head, int coef, int expo)
{
	node* newNode = createNode(coef, expo);
	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		node* temp = head;
		while (temp->next != nullptr)
		{
			temp = temp->next;
		}
		temp->next = newNode;
	}
}
// Display function
void display(node* head)
{
	node* temp = head;
	while (temp != nullptr)
	{
		cout << temp->coef << "x^" << temp->expo;
		if (temp->next != nullptr)
		{
			cout << " + ";
		}
		temp = temp->next;
	}
	cout << endl;
}
// Addpolynomials Function
node* add(node* p1, node* p2)
{
	node* result = nullptr;
	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->expo > p2->expo)
		{
			insert(result, p1->coef, p1->expo);
			p1 = p1->next;
		}
		else if (p2->expo > p1->expo)
		{
			insert(result, p2->coef, p2->expo);
			p2 = p2->next;
		}
		else
		{
			int sum = p1->coef + p2->coef;
			insert(result, sum, p1->expo);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != nullptr)
	{
		insert(result, p1->coef, p1->expo);
		p1 = p1->next;
	}
	while (p2 != nullptr)
	{
		insert(result, p2->coef, p2->expo);
		p2 = p2->next;
	}
	return result;
}
// Subtract function
node* subtract(node* p1, node* p2)
{
	node* result = nullptr;
	while (p1 != nullptr && p2 != nullptr)
	{
		if (p1->expo > p2->expo)
		{
			insert(result, p1->coef, p1->expo);
			p1 = p1->next;
		}
		else if (p2->expo > p1->expo)
		{
			insert(result, -p2->coef, p2->expo);
			p2 = p2->next;
		}
		else
		{
			int diff = p1->coef - p2->coef;
			insert(result, diff, p1->expo);
			p1 = p1->next;
			p2 = p2->next;
		}
	}
	while (p1 != nullptr)
	{
		insert(result, p1->coef, p1->expo);
		p1 = p1->next;
	}
	while (p2 != nullptr)
	{
		insert(result, -p2->coef, p2->expo);
		p2 = p2->next;
	}
	return result;
}
// Multiply function
node* multiply(node* p1, node* p2)
{
	node* result = nullptr;
	for (node* t1 = p1; t1 != nullptr; t1 = t1->next)
	{
		for (node* t2 = p2; t2 != nullptr; t2 = t2->next)
		{
			int coef = t1->coef * t2->coef;
			int expo = t1->expo + t2->expo; 
			node* temp = result;
			bool found = false;
			while (temp != nullptr)
			{
				if (temp->expo == expo)
				{
					temp->coef += coef;
					found = true;
					break;
				}
				temp = temp->next;
			}
			if (!found)
			{
				insert(result, coef, expo);
			}
		}
	}
	return result;
}
// Delete function
void remove(node* h)
{
	node* t = nullptr;
	while (h != nullptr)
	{
		t=h;
		h = h->next;
		delete t;
	}
}
int main()
{
	node* poly1 = nullptr;
	node* poly2 = nullptr;
	insert(poly1, 3, 2);
	insert(poly1, 2,1);
	insert(poly1, 1, 0);
	insert(poly2, 4, 1);
	insert(poly2, 5, 0);
	cout << "\n\t\t\t\t\tPolynomial 1 : ";
	display(poly1);
	cout << "\n\t\t\t\t\tPolynomial 2 : ";
	display(poly2);
	node* sum = add(poly1, poly2);
	cout << "\n\t\t\t\t\tSum : ";
	display(sum);
	node* diff = subtract(poly1, poly2);
	cout << "\n\t\t\t\t\tDifference : ";
	display(diff);
	node* prod = multiply(poly1, poly2);
	cout << "\n\t\t\t\t\tProduct : ";
	display(prod);
	remove(poly1);
	poly1 = nullptr;
	remove(poly2);
	poly2 = nullptr;
	return 0;
}