#include<iostream>
using namespace std;
class stack
{
private:
	int* array;
	int size;
	int top;
public:
	stack(int n)
	{
		if (n > 0)
		{
			array = new int[n];
		}
		else
		{
			array = nullptr;
		}
		size = n;
		top = -1;
	}
	stack(const stack& obj)
	{
		array = new int[obj.size];
		size = obj.size;
		top = obj.top;
		for (int i = 0; i < obj.size; i++)
		{
			array[i] = obj.array[i];
		}
	}
	~stack()
	{
		delete[]array;
		array = nullptr;
	}
	void push(int n)
	{
		if (isfull())
		{
			cout << "\n\t\t\t\t\tStack is full.\n";
		}
		else
		{
			top++;
			array[top] = n;
		}
	}
	void pop(int& n)
	{
		if (isempty())
		{
			cout << "\n\t\t\t\t\tStack is empty.\n";
		}
		else
		{
			n = array[top];
			top--;
		}
	}
	bool isfull()
	{
		bool status;
		if (top == size - 1)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
	bool isempty()
	{
		bool status;
		if (top == - 1)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
};
int main()
{
	stack s(5);
	cout << "\n\t\t\t\t\tPushing 5 elements into stack.\n";
	for (int i = 1; i < 6; i++)
	{
		s.push(i * 7);
	}
	int v = 0;
	cout << "\n\t\t\t\t\tPopping 5 elements from stack.\n";
	cout << "\n\t\t\t\t\tAll popped elements : ";
	while (!s.isempty())
	{
		s.pop(v);
		cout << v << " ";
	}
	cout << "\n";
	return 0;
}