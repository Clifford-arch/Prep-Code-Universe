#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }

        sort(nums.begin(), nums.end());

        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;

        for(int i = 1; i < n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                } else {
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }

        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {5,1,2,6,7,8,0,3,9};

    int result = sol.longestConsecutive(nums);

    cout << "Longest Consecutive Sequence Length: " << result << endl;

    return 0;
}