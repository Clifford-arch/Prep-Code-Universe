#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         vector<int>prod;
//         for(int i=0;i<nums.size();i++){
//             int count=1;
//             for(int j=0;j<nums.size();j++){
//                 if(i!=j){
//                     count*=nums[j];
//                 }
//             }
//             prod.push_back(count);
//         }

//         return prod;
//     }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prod(n,1);

        int leftProduct = 1;
        for(int i=0;i<n;i++){
            prod[i]=leftProduct;
            leftProduct *= nums[i];
        }
        int rightProduct = 1;
        for(int i=n-1;i>=0;i--){
           prod[i] *= rightProduct;
         rightProduct *= nums[i];
        }
        return prod;

    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4};

    vector<int> result = sol.productExceptSelf(nums);

    for (int x : result) {
        cout << x << " ";
    }
  
    return 0;
}