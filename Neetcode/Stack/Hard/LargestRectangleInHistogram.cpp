// https://neetcode.io/problems/largest-rectangle-in-histogram/question
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    struct hi
    {
        int index, h;
    };
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        stack<hi> active;
        int maxArea = 0, n = heights.size();
        for (int i = 0; i < n; i++)
        {
            int leftMost = i;
            while (!active.empty() && heights[i] < active.top().h)
            {
                hi curr = active.top();
                active.pop();
                // cout << "Pop " << curr.h << endl;
                maxArea = max(maxArea, (i - curr.index) * curr.h);
                leftMost = curr.index;
                // cout << "maxArea " << maxArea << endl;
            }

            // cout << " ind"<< leftMost << "push " << heights[i] << endl;
            active.push({leftMost, heights[i]});
        }


        return maxArea;
    }
};
