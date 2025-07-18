//
//                                                     // Implementation of queue using stack
//
//#include<iostream>
//using namespace std;
//template <class t>
//class queue
//{
//private:
//	int cap;
//	t* arr;
//	int top;
//public:
//	queue(int s)
//	{
//		cap = s;
//		arr = new t[cap];
//		top = -1;
//	}
//	queue(const queue& other)
//	{
//		cap = other.cap;
//		if (other.cap > 0)
//		{
//			arr = new t[cap];
//		}
//		else
//		{
//			arr = nullptr;
//		}
//		for (int i = 0; i < cap; i++)
//		{
//			arr[i] = other.arr[i];
//		}
//		top = other.top;
//	}
//	~queue()
//	{
//		delete[]arr;
//		arr = nullptr;
//	}
//	bool isfull()
//	{
//		bool status;
//		if (top == cap - 1)
//		{
//			status = true;
//		}
//		else
//		{
//			status = false;
//		}
//		return status;
//	}
//	bool isempty()
//	{
//		bool status;
//		if (top == -1)
//		{
//			status = true;
//		}
//		else
//		{
//			status = false;
//		}
//		return status;
//	}
//	void enqueue(int s)
//	{
//		if (isfull())
//		{
//			cout << "\nQueue is full.There is nothing to enqueue.\n";
//			return;
//		}
//		else
//		{
//			top++;
//			arr[top] = s;
//		}
//	}
//	void dequeue()
//	{
//		if (isempty())
//		{
//			cout << "\nQueue is empty.There is nothing to dequeue.\n";
//			return;
//		}
//		else
//		{
//			top--;
//		}
//	}
//	t front()
//	{
//		if (isempty())
//		{
//			cout << "\nQueue is empty.   Top is -1.\n";
//			return t();
//		}
//		else
//		{
//			return arr[top];
//		}
//	}
//	void rear()
//	{
//		if (!isempty())
//		{
//           cout<<"\n\t\t\t\t\tFirst element of queue : "<< arr[0];
//			for (int i = 0; i < top; i++)
//			{
//				arr[i] = arr[i + 1];
//			}
//			top--;
//		}
//		else
//		{
//			cout << "\nQueue is empty.Nothing to show.\n";
//		}
//	}
//	void display()
//	{
//		cout << "\n\t\t\t\t\tQueue elements : ";
//		for (int i = 0; i <= top; i++)
//		{
//			cout << arr[i] << " ";
//		}
//		cout << "\n";
//	}
//};
//int main()
//{
//	queue<int>s(5);
//	s.enqueue(5);
//	s.enqueue(4);
//	s.enqueue(3);
//	s.enqueue(2);
//	s.enqueue(1);
//	s.display();
//    s.rear();
//	s.display();
//	cout<<"\n\t\t\t\t\tLast element of Queue : "<<s.front();
//	s.dequeue();
//	s.display();
//	return 0;
//}