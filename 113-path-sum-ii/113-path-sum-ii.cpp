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
    void preorder(TreeNode* root, int targetSum, int sum, vector<int> &ds, vector<vector<int>> &ans) {
        if(root == NULL) return;
        
        ds.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL) {
            if(root->val + sum == targetSum) {
                ans.push_back(ds);
            }
            ds.pop_back();
            return;
        }
        
        preorder(root->left, targetSum, sum + root->val, ds, ans);
        preorder(root->right, targetSum, sum + root->val, ds, ans);
        
        ds.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> ds;
        preorder(root, targetSum, 0, ds, ans);
        return ans;
    }
};