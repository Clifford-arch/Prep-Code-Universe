#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastSeen(256, -1);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.length(); right++) {
            char ch = s[right];

            // If character is already in the current window
            if (lastSeen[ch] >= left) {
                left = lastSeen[ch] + 1;
            }

            // Update last seen position
            lastSeen[ch] = right;

            // Update maximum length
            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};

int main() {
    Solution sol;

    string s;
    cout << "Enter a string: ";
    cin >> s;

    cout << "Length of longest substring without repeating characters: "
         << sol.lengthOfLongestSubstring(s) << endl;

    return 0;
}