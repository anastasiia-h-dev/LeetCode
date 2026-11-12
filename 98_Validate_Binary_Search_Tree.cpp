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


    bool Helper(TreeNode* root, long long left, long long right)
    {
        if(root == nullptr) return true;

        if(root->val <= left || root->val >= right) return false;

        return Helper(root->left, left, root->val) && Helper(root->right, root->val, right);
    }

    bool isValidBST(TreeNode* root) {
        return Helper(root, -9999999999999, 9999999999999);
    }
};