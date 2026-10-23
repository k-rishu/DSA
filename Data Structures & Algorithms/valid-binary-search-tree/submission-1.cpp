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
private: 
    bool checkBST(TreeNode* root, int maxValue, int minValue){
        if(!root) return true;

        if(root->val <= minValue || root->val >= maxValue){
            return false;
        }
        return checkBST(root->left, root->val, minValue) && 
            checkBST(root->right, maxValue, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root, INT_MAX, INT_MIN);
    }
};
