#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;

    string s;

    cout << "Enter a string of brackets: ";
    cin >> s;

    if (sol.isValid(s))
        cout << "Valid\n";
    else
        cout << "Invalid\n";

    return 0;
}