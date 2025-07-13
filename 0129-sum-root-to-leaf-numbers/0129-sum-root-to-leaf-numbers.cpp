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

    int ans = 0;
    int solve(TreeNode*root,string&temp){
        if(root == NULL)return 0;
        if(root->left == NULL && root->right == NULL){
            temp.push_back(root->val+'0');
            int sum = stoi(temp);
            ans+=sum;
            temp.pop_back();
            return ans;
        }
    

        temp.push_back(root->val+'0');
        solve(root->left,temp);
        solve(root->right,temp);
        temp.pop_back();

        return ans;
    }

    int sumNumbers(TreeNode* root) {
        string temp = "";
        return solve(root,temp);
    }
};