#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseWords(string str)
{
    stack<char> st;
    string result;

    for (int i = 0; i < str.length(); i++)
    {
        // Jab tak space nahi milta, characters stack mein push karo
        if (str[i] != ' ')
        {
            st.push(str[i]);
        }
        else
        {
            // Word reverse karke result mein add karo
            while (!st.empty())
            {
                result += st.top();
                st.pop();
            }

            result += ' ';
        }
    }

    // Last word ke liye
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string str;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Output: " << reverseWords(str) << endl;

    return 0;
}