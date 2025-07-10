#include<iostream>
#include<string>
using namespace std;
template<typename t>
class stack
{
private:
	int cap;
	t* arr;
	int top;
public:
	stack(int s)
	{
		cap = s;
		arr = new t[cap];
		top = -1;
	}
	stack(const stack& other)
	{
		cap = other.cap;
		if (other.cap > 0)
		{
			arr = new t[cap];
		}
		else
		{
			arr = nullptr;
		}
		for (int i = 0; i < cap; i++)
		{
			arr[i] = other.arr[i];
		}
		top = other.top;
	}
	~stack()
	{
		delete[]arr;
		arr = nullptr;
	}
	bool isfull()
	{
		bool status;
		if (top == cap - 1)
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
		if (top == -1)
		{
			status = true;
		}
		else
		{
			status = false;
		}
		return status;
	}
	void push(int s)
	{
		if (isfull())
		{
			cout << "\nStack is full.There is nothing to push.\n";
			return;
		}
		else
		{
			top++;
			arr[top] = s;
		}
	}
	void pop()
	{
		if (isempty())
		{
			cout << "\nStack is empty.There is nothing to pop.\n";
			return;
		}
		else
		{
			top--;
		}
	}
	t peek()
	{
		if (isempty())
		{
			cout << "\nStack is empty.   Top is -1.\n";
			return t();
		}
		else
		{
			return arr[top];
		}
	}
	void display()
	{
		cout << "\n\t\t\t\t\tStack elements : ";
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
 int getsize()
{
	return top + 1;
	}
t getatspecificposition(int i)
{
	return arr[i];
}
};
bool isValid(string s)
{
	int len = s.length();
	stack<char> st(len);
	for (int i = 0; i < len; i++)
	{
		char cha = s[i];
		if (cha == '(' || cha == '{' || cha == '[')
		{
			st.push(cha);
		}
		else if (cha == ')' || cha == '}' || cha == ']')
		{
			if (st.isempty())
			{
				return false;
			}
			char topofcha = st.peek();
			if ((cha == ')') && (topofcha == '(') || (cha == '}') && (topofcha == '{') || (cha == ']') && (topofcha == '['))
			{
				st.pop();
			}
			else
			{
				return false;
			}
		}
	}
	return st.isempty();
}
int main()
{
	string st = "";
	cout << "\nEnter string : ";
	cin >> st;
	cout << "\nThe string is valid : ";
	if (isValid(st))
	{
		cout << "\nYes\n";
	}
	else
	{
		cout << "\nNo\n";
	}
	return 0;
}