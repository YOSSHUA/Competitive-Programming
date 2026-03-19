// https://leetcode.com/problems/trapping-rain-water/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int totalSum = 0;
        stack<int> h;
        vector<int> leftMax(n);
        vector<int> rightMax(n);
        leftMax[0] = height[0];
        rightMax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
            rightMax[n - 1 - i] = max(rightMax[n - i], height[n - 1 - i]);
        }

        for (int i = 1; i < n; i++)
        {
            totalSum += max(0, min(leftMax[i], rightMax[i]) - height[i]);
        }

        return totalSum;
    }
};
