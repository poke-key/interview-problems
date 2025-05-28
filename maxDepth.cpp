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
    int maxDepth(TreeNode* root) {
        
        TreeNode* currNode = root;

        if(!currNode) return 0;

        int left_depth = maxDepth(currNode->left);
        int right_depth = maxDepth(currNode->right);

        if(left_depth > right_depth) return left_depth + 1;

        return right_depth + 1;
        
    }
};