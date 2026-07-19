/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int cnt = 0;
    int solve(TreeNode* root) {
        if (!root)
            return INT_MIN;

        int lMax = solve(root->left);
        int rMax = solve(root->right);

        int currMax = max({root->val, lMax, rMax});
        if (currMax == root->val)
            cnt++;

        return currMax;
    }
    
    int countDominantNodes(TreeNode* root) {
        solve(root);
        return cnt;
    }
};