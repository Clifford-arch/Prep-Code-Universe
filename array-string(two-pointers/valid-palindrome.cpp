#include <iostream>
#include <string>
#include <cctype>   // for isalnum() and tolower()

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while (left < right) {

            
            while (left < right && !isalnum(s[left])) {
                left++;
            }

            
            while (left < right && !isalnum(s[right])) {
                right--;
            }

           
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};

int main() {

    Solution obj;

    string s;

    cout << "Enter string: ";
    getline(cin, s);

    bool result = obj.isPalindrome(s);

    if (result) {
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}