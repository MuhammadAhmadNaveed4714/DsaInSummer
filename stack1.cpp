//#include <iostream>
//using namespace std;
//template <typename T>
//class Stack 
//{
//private:
//    int top;        
//    int capacity;   
//    T* arr;         
//public:
//    Stack(int size)
//    {
//        capacity = size;
//        arr = new T[capacity];
//        top = -1; 
//    }
//    Stack(const Stack& obj)
//    {
//        if (obj.capacity > 0)
//            arr = new T[obj.capacity];
//        else
//            arr = nullptr;
//        capacity = obj.capacity;
//        for (int i = 0; i < capacity; i++)
//        {
//            arr[i] = obj.arr[i];
//        }
//        top = obj.top;
//    }
//    ~Stack()
//    {
//        delete[] arr;
//    }
//    void push(T value) 
//    {
//        if (isFull())
//        {
//            cout << "Stack Overflow! Cannot push " << value << endl;
//            return;
//        }
//        top++;
//        arr[top] = value;
//    }
//    void pop() 
//    {
//        if (isEmpty())
//        {
//            cout << "Stack Underflow! Nothing to pop." << endl;
//            return;
//        }
//        top--;
//    }
//    T peek()  
//    {
//        if (isEmpty())
//        {
//            cout << "Stack is empty! Nothing to peek." << endl;
//            return T();  
//        }
//        return arr[top];
//    }
//    bool isEmpty()
//    {
//        bool status;
//        if (top == -1)
//            status = true;
//        else
//            status = false;
//        return status;
//    }
//    bool isFull()
//    {
//        bool status;
//        if (top == capacity-1)
//            status = true;
//        else
//            status = false;
//        return status;
//    }
//    void display() 
//    {
//        if (isEmpty())
//        {
//            cout << "Stack is empty!" << endl;
//            return;
//        }
//
//        cout << "Stack elements: ";
//        for (int i = 0; i <= top; i++) 
//        {
//            cout << arr[i] << " ";
//        }
//        cout << endl;
//    }
//};
//int main() 
//{
//    Stack<int> s(5);
//    s.push(10);
//    s.push(20);
//    s.push(30);
//    s.display(); 
//    s.pop();
//    s.display();
//    cout << "Top element is: " << s.peek() << "\n";
//    return 0;
//}
