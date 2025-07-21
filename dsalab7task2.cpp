#include <iostream>
#include <string>
using namespace std;
string makeFancyString(string s)
{
    string result;
    int count = 1;
    for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1]) {
            count++;
        }
        else
        {
            count = 1;
        }

        if (count < 3) 
        {
            result += s[i];
        }
    }
    return s.empty() ? "" : s[0] + result;
}

int main()
{
    string s1 = "lugggage";
    string s2 = "aaabaaaa";
    string s3 = "aab";
    cout << makeFancyString(s1) << endl;  
    cout << makeFancyString(s2) << endl;  
    cout << makeFancyString(s3) << endl;  
    return 0;
}
