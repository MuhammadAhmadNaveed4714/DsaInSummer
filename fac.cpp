#include<iostream>
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
	int n = 0;
	cout << "\nEnter number to generate fibonacci series :  ";
	cin >> n;
	cout << "\n\n\t\t\t\t\tFibonacci series : " << fibonacci(n) << "\n";
	return 0;
}