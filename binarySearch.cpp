#include<iostream>
using namespace std;
//Function to calculate binary search
int binarySearch(int arr[], int f, int l, int v)
{
	int m = 0;
	m = (f + l) / 2;
	if (f > l)
	{
		return -1;
	}
	else if (arr[m] > v)
	{
		return binarySearch(arr,f,m-1, v);
	}
	else if (arr[m] < v)
	{
		return binarySearch(arr, m + 1, l, v);
	}
}
int main()
{
	int a[40] = {11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50};
	cout << "\n\t\t\t\t\tBinary Search for 12 : " << binarySearch(a, 0, 39, 11)<<"\n\n";
	return 0;
}