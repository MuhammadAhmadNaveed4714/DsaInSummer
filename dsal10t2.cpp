//#include<iostream>
//#include<vector>
//#include<set>
//#include<unordered_set>
//using namespace std;
//// Function
//int uniqueproductsumquotient(vector<int>& nums)
//{
//	int sum = 0;
//	int pro = 1;
//	set<int>s;
//	for (int i = 0; i < nums.size(); i++)
//	{
//		s.insert(nums[i]);
//	}
//	for (auto p:s)
//	{
//		sum =sum+ p;
//	}
//	for (auto p : s)
//	{
//		pro =pro* p;
//	}
//	int k = 0;
//	if (sum == 0)
//	{
//		cout << "\n\t\t\t\t\tDivision by zero is not possible.\n";
//		return -1;
//	}
// k = (pro / sum);
//	return k;
//}
//int main()
//{
//	int size = 0;
//	cout << "\nEnter size : ";
//	cin >> size;
//	vector<int> vec(size,0);
//	for (int i = 0; i < size; i++)
//	{
//		cout << "\nEnter element [" << i << "] = ";
//		cin >> vec[i];
//	}
//	cout << "\n\t\t\t\t\tFinal value : " << uniqueproductsumquotient(vec) << "\n";
//	return 0;
//}