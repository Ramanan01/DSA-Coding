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
    void dfs(TreeNode* root, int& targetSum, unordered_map<int, int>& seenCount, 
             int currSum, int& res) {
        if (!root) {
            return;
        }

        currSum += root->val;
        res += seenCount[currSum - targetSum];
        seenCount[currSum]++;

        dfs(root->left, targetSum, seenCount, currSum, res);
        dfs(root->right, targetSum, seenCount, currSum, res);

        seenCount[currSum]--;
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<int, int> seenCount;
        seenCount[0] = 1;
        int res = 0;
        dfs(root, targetSum, seenCount, 0, res);
        return res;
    }
};
