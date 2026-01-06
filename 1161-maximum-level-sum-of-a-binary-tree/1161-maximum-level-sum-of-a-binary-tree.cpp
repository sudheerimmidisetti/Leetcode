/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    long long maxSum = INT_MIN;
    int level = 0;
    void levelSum(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        int currentLevel = 0;
        while (!q.empty()) {
            int n = q.size();
            long long sum = 0;
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
            currentLevel++;
            if(sum > maxSum) {
                maxSum = sum;
                level = currentLevel;
            }
        }
    }
    int maxLevelSum(TreeNode* root) {
        levelSum(root);
        return level;
    }
};