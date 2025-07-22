#include<iostream>
using namespace std;
int gcd(int x, int y)
{
	if (x % y == 0)
		return y;
	else
		return gcd(y, x % y);
}
int main()
{
	int n1 = 0, n2 = 0;
	cout << "\n\t\t\t\t\tEnter number 1 : ";
	cin >> n1;
	cout << "\n\t\t\t\t\tEnter number 2 : ";
	cin >> n2;
	cout << "\n\t\t\t\t\tHCF : " << gcd(18, 12) << "\n";
	return 0;
}