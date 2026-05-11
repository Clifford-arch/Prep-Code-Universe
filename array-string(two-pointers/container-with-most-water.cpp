#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxsum = 0;

        while (left < right) {

            int width = right - left;

            int currHeight = min(height[left], height[right]);

            int area = width * currHeight;

            maxsum = max(maxsum, area);

            if (height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }

        return maxsum;
    }
};

int main() {

    int n;

    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);

    cout << "Enter heights:\n";

    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }

    Solution obj;

    int result = obj.maxArea(height);

    cout << "Maximum Water Area = " << result << endl;

    return 0;
}