// https://neetcode.io/problems/min-cost-climbing-stairs/question?list=neetcode250
#include <vector>
#include <iostream>
#include <stack>
#include <set>
#include <queue>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> m(n+2,0);
        for(int i = n-1; i >= 0; i--) {
            m[i] = min(cost[i] + m[i+1], cost[i] + m[i+2]);
        }
        return min(m[0], m[1]);
    }
};
