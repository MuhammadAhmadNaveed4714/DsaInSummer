#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int>& s, int current, int mid)
{
    if (s.empty())
        return;

    int x = s.top();
    s.pop();

    if (current == mid)
    {
        // Middle element delete kar diya
        return;
    }

    deleteMiddle(s, current + 1, mid);

    s.push(x);
}

void removeMiddle(stack<int>& s)
{
    int n = s.size();

    // Even size me first middle delete hoga
    int mid = (n / 2) + 1;

    deleteMiddle(s, 1, mid);
}

void printStack(stack<int> s)
{
    cout << "Stack (bottom -> top): ";

    int arr[1000];
    int i = 0;

    while (!s.empty())
    {
        arr[i++] = s.top();
        s.pop();
    }

    for (int j = i - 1; j >= 0; j--)
        cout << arr[j] << " ";

    cout << endl;
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Before deletion:" << endl;
    printStack(s);

    removeMiddle(s);

    cout << "After deletion:" << endl;
    printStack(s);

    return 0;
}