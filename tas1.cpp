#include<iostream>
#include<vector>
using namespace std;
int num(vector<int>& p, int limit)
{
	int c = 0;
	int b = 0;
	int sum = 0;
	for (int i = 0; i < p.size(); i++)
	{
		if (p[i] == limit)
		{
			b++;
		}
		else if (p[i] < limit)
		{
			sum += p[i];
			c++;
			if (c == 2)
			{
				if (sum <= limit)
				{
					b++;
				}
				else if (sum > limit)
				{
					b = b + 2;
				}
				c = 0;
				sum = 0;
			}
		}
	}
	if (sum != 0)
	{
		b++;
	}
	return b;
}
int main()
{
	    int ssize = 0;
		cout << "\nEnter size : ";
		cin >> ssize;
		int limit = 0;
		cout << "\nEnter limit : ";
		cin >> limit;
		vector<int> v (ssize,0);
		for (int i = 0; i < ssize; i++)
		{
			cout << "\n\t\t\t\t\tEnter element [" << i << "] = ";
			cin >> v[i];
		}
		for (int i = 0; i < v.size(); i++)
		{
			for (int j = 0; j < v.size() - i - 1; j++)
			{
				if (v[j] > v[j + 1])
				{
					int temp = v[i];
					v[i] = v[i + 1];
					v[i + 1] = temp;
				}
			}
		}
		cout << "\nOutput : " << num(v, limit) << "\n";
	return 0;
}