#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
     int maxProfit(vector<int>& prices) {


        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices) {

            minPrice = min(minPrice, price);

            int profit = price - minPrice;

            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;

    vector<int> nums = {3, 4, 5, 2, 3, 6};
   

    int result = sol.maxProfit(nums);

    cout << "Max Prof: " << result << endl;

    return 0;
}

// class Solution {
// public:
//      int maxProfit(vector<int>& prices) {
//         int buy=prices[0];
//         int maxprof=0;
//         int n=prices.size();

//         for (int i=1;i<n;i++){
//             if(prices[i]<buy){
//                 buy=prices[i];
//             }
//             else{
//                 int currentprof=prices[i]-buy;
//                 maxprof=max(currentprof,maxprof);
//             }
//         }

//         return maxprof;
//     }
// };

