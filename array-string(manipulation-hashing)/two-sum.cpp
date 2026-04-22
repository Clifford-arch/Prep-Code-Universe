#include <unordered_map>
#include <vector>
#include <stdexcept>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (hashmap.count(complement)) {//hashmap.find(complement) != hashmap.end()
                return {hashmap[complement], i};
            }

            hashmap[nums[i]] = i;
        }
        return {};
        // throw runtime_error("No two sum solution");
    }
};