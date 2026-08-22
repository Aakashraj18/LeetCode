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
    bool helper(TreeNode* node, long long mini, long long maxi){
        if(!node) return true;
        if(mini < node->val && node->val < maxi){
            return helper(node->left, mini, node->val) && helper(node->right, node->val, maxi);
        }
        else return false;
    }

public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        long long mini = -1000000000000, maxi = 1000000000000;
        return helper(root, mini, maxi);
    }
};