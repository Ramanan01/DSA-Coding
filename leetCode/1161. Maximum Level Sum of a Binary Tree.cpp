class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxLevelSum = INT_MIN, maxLevel = 0;
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;

        while (!q.empty()) {
            int n = q.size();
            int levelSum = 0;

            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }

                levelSum += node->val;
            }

            if (maxLevelSum < levelSum) {
                maxLevelSum = levelSum;
                maxLevel = level;
            }
            
            level++;
        }

        return maxLevel;
    }
};
