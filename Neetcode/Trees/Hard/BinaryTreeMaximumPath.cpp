// https://leetcode.com/problems/binary-tree-maximum-path-sum/

#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int globalMax = root->val;
        int maxTreeWith = calculateMax(root, &globalMax);
        cout << "globalMax: " << globalMax << " maxTreeWith: " << maxTreeWith;
        return max(globalMax, maxTreeWith);
    }

    int calculateMax(TreeNode *root, int *globalMax)
    {
        // end of path
        if (root == nullptr)
            return -1001;
        // leaf
        if (root->left == nullptr && root->right == nullptr)
        {
            return root->val;
        }

        int left = calculateMax(root->left, globalMax);
        int right = calculateMax(root->right, globalMax);
        int me = root->val;
        *globalMax = max(*globalMax, me + left + right);
        *globalMax = max(*globalMax, max(left, right));

        return max(me + left,
                   max(me + right, me));
    }
};
