#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
// vector<int> topKFrequent(vector<int>& nums, int k) {
//     unordered_map<int,int> freq;
//     for (int x : nums) {
//     freq[x]++;
//     }


//     priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

//     for (auto &p : freq) {
//         pq.push({p.second, p.first});
//         if (pq.size() > k) {
//             pq.pop();
//         }
//     }

//     vector<int> ans;
//     ans.reserve(k);
//     while (!pq.empty()) {
//         ans.push_back(pq.top().second);
//         pq.pop();
//     }

//     reverse(ans.begin(), ans.end()); // optional for sorted output
//     return ans;
// }


// };


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         unordered_map<int, int> freq;

        // Step 1: Count frequency
        for (int num : nums) {
            freq[num]++;
        }

        // Step 2: Create buckets
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto it : freq) {
            int number = it.first;
            int count = it.second;

            bucket[count].push_back(number);
        }

        // Step 3: Collect top k frequent elements
        vector<int> ans;

        for (int i = bucket.size() - 1; i >= 0; i--) {
            for (int num : bucket[i]) {
                ans.push_back(num);

                if (ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
   
   
};

int main() {
Solution sol;

vector<int> nums = {1,1,1,2,2,3,4,5,5,5,6,6,6};
int k = 3;

vector<int> result = sol.topKFrequent(nums, k);

cout << "Top " << k << " frequent elements: ";
for (int x : result) {
    cout << x << " ";
}
cout << endl;

return 0;


}
