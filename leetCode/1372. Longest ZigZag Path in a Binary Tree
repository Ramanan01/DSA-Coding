class Solution {
public:
    int longestZigZagPath(TreeNode* root, int &maxNodesZigZagPath, int side) {
        if (root == NULL) {
            return 0;
        }
        
        int left = longestZigZagPath(root->left, maxNodesZigZagPath, -1);
        int right = longestZigZagPath(root->right, maxNodesZigZagPath, 1);
        
        maxNodesZigZagPath = max(maxNodesZigZagPath, max(left + 1, right + 1));
        
        return (side == -1) ? 1 + right : 1 + left;
    }

    int longestZigZag(TreeNode* root) {
        int maxNodesZigZagPath = 0;
        longestZigZagPath(root, maxNodesZigZagPath, 0);
        return maxNodesZigZagPath - 1;
    }
};
