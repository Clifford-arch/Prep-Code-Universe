#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        if (!seen.insert(x).second) {
            for (int x : nums) {
                return true;
            }
        }
        return false;
    }
};

// Oneline Trick
//  bool containsDuplicate(vector<int>& nums) {
//         unordered_set<int> s(nums.begin(), nums.end());
//         return s.size() < nums.size();
//     }