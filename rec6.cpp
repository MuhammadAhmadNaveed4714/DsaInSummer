#include <iostream>
using namespace std;
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}
int main()
{
    int n;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> n;
    cout << "The first " << n << " Fibonacci numbers are: ";
    for (int i = 0; i < n; i++) 
    {
        cout << fibonacci(i) << " ";
    }
    return 0;
}