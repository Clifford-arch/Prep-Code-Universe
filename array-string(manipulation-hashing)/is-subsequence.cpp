#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int pointer1 = 0, pointer2 = 0;

        while (pointer1 < s.length() && pointer2 < t.length()) {
            if (s[pointer1] == t[pointer2]) {
                pointer1++;
            }
            pointer2++;
        }

        return pointer1 == s.length();
    }
};

int main() {
    Solution obj;

    string s, t;
    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter string t: ";
    cin >> t;

    bool result = obj.isSubsequence(s, t);

    cout << (result ? "True" : "False") << endl;
}