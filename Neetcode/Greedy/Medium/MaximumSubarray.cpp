// https://leetcode.com/problems/maximum-subarray/
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res, s;
        res = s = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            s = max(s, 0);
            s += nums[i];
            res = max(res, s);
        }
        return res;
    }
};
