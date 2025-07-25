//#include<iostream>
//using namespace std;
//// Function of findmaximum
//int fm(int a[], int s)
//{
//	if (s == 1)
//	{
//		return a[0];
//	}
//	int m = fm(a, s - 1);
//	return (a[s - 1] > m) ? a[s - 1] : m;
//}
//int main()
//{
//	int n = 0;
//	cout << "\n\t\t\t\t\tEnter capacity : ";
//	cin >> n;
//	int* a = new int[n];
//		cout << "\n\t\t\t\t\tEntry of elements : \n";
//		for (int i = 0; i < n; i++)
//		{
//			cin >> a[i];
//		}
//		cout << "\n\t\t\t\t\tShow  of elements : ";
//		for (int i = 0; i < n; i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << "\n\n\t\t\t\t\tMaximum : " << fm(a, n) << "\n\n";
//	return 0;
//}