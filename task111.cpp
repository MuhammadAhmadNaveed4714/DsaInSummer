#include<iostream>
#include<string>
using namespace std;
int maxNumberOfBalloons(string text)
{
	int cb = 0, ca = 0, cl = 0, co = 0, cn = 0;
	cout << "\nA full balloon has 1a,1b,2o,2l and 1n.\n ";
	int len = text.length();
	for (int i = 0; i < len; i++)
	{
		if (text[i] == 'b')
		{
			cb++;
		}
		else if (text[i] == 'a')
		{
			ca++;
		}
		else if (text[i] == 'l')
		{
			cl++;
		}
		else if (text[i] == 'o')
		{
			co++;
		}
		if (text[i] == 'n')
		{
			cn++;
		}
	}
	int count = 0;
	while (cb >= 1 && cn >= 1 && ca >= 1 && cl >= 2 && co >= 2)
	{
		count++;
		cb -= 1;
		ca -= 1;
		co -= 2;
		cn -= 1;
		cl -= 2;
	}
	return count;
}
int main()
{
	string text = "w";
	cout << "\nEnter string : ";
	cin >> text;
	int n = maxNumberOfBalloons(text);
	cout << "\nTotal balloons : " << n << "\n";
	return 0;
}