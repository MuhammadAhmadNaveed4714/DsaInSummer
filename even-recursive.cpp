//#include<iostream>
//using namespace std;
//// Function odd
//int even(int* a, int s, int i)
//{
//	if (i >= s)
//	{
//		return 0;
//	}
//	if (i < s)
//	{
//		i = i + 2;
//		return a[i - 2] + even(a, s, i);
//	}
//}
//int main()
//{
//	int size = 0;
//			cout << "\n\t\t\t\t\tEnter size of array : ";
//			cin >> size;
//			int* q = new int[size];
//			for (int i = 0; i < size; i++)
//			{
//				cout << "\n\t\t\t\t\tEnter element [" << i  << "] = ";
//				cin >> q[i];
//			}
//			cout << "\n\t\t\t\t\tEven : " << even(q, size,0) << "\n";
//			delete[]q;
//			q = nullptr;
//	return 0;
//}