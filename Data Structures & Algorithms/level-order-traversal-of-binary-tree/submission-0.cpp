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
    vector<vector<int>> result;
    void help(TreeNode* root, int level){
        if(root == nullptr) return;
        if (result.size() == level) {
            result.push_back({});
        }

        result[level].push_back(root->val);
        help(root->left, level+1);
        help(root->right, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        result.clear();
        help(root, 0);
        return result;

    }
};
