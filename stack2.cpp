#include <iostream>
using namespace std;

string reverseString(string &s) {
    stack<char> st;
  
    // Push the charcters into stack
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }

    // Pop the characters of stack into the original string
    for (int i = 0; i < s.size(); i++) {
        s[i] = st.top();
        st.pop();
    }
  
  	return s;
}

int main() {
    string s = "abdcfe";
    cout << reverseString(s);
    return 0;
}