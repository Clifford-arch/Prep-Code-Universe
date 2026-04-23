#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;

        for (const auto& word : strs) {
            string key = word;
            sort(key.begin(), key.end());
            anagrams[key].push_back(word);
        }

        vector<vector<string>> result;

        // for (const auto& [key, group] : anagrams) {
        //     result.push_back(group);
        // }
          for (const auto& it : anagrams) {
            result.push_back(it.second);
        }

        return result;
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution sol;
    vector<vector<string>> result = sol.groupAnagrams(strs);

    for (const auto& group : result) {
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}