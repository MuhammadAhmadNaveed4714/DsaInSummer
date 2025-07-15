#include<iostream>
#include<string>
using namespace std;
bool isValid(string word)
{
    int leng = word.length();
    if (leng < 3)
    {
        return false;
    }
    bool status1 = false;
    bool status2 = false;
    bool status3 = false;
    for (int i = 0; i < leng; i++)
    {
        char c = word[i];
        if (c >= '0' && c <= '9')
        {
            status1 = true;
        }
        else if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            {
                status2 = true;
            }
            else if (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U')
            {
                status3 = true;
            }
        }
        else
        {
            return false;
        }
    }
    return status1 && status2 && status3;
}
int main()
{
    string inp = "";
    cout << "\nEnter a string : ";
    getline(cin, inp);
    if (isValid(inp))
    {
        cout << "\nYou have entered a right word.\n";
    }
    else
    {
        cout << "\nYou have entered a wrong word.\n";
    }
	return 0;
}