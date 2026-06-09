#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check whether a character is an operator
bool isOperator(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' ||
        ch == '/' || ch == '^') {
        return true;
    }
    return false;
}

// Function to convert Postfix to Prefix
string postfixToPrefix(string postfix) {

    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {

        char ch = postfix[i];

        // If operand, push into stack
        if (!isOperator(ch)) {
            string operand = "";
            operand += ch;
            st.push(operand);
        }

        // If operator
        else {

            string operand2 = st.top();
            st.pop();

            string operand1 = st.top();
            st.pop();

            string temp = "";

            temp += ch;          // operator
            temp += operand1;    // first operand
            temp += operand2;    // second operand

            st.push(temp);
        }
    }

    return st.top();
}

int main() {

    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    string prefix = postfixToPrefix(postfix);

    cout << "Prefix Expression: " << prefix << endl;

    return 0;
}