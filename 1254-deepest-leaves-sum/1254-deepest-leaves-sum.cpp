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

    int height(TreeNode*root){
        if(root == NULL)return 0;

        int left = height(root->left);
        int right = height(root->right);

        return max(left,right)+1;
    }

    int solve(TreeNode*root,int h){
        if(root == NULL)return 0;
        if(h == 1)return root->val;

        int ans1 = 0;
        int ans2 = 0;
        ans1 += solve(root->left,h-1);
        ans2 += solve(root->right,h-1);

        return ans2+ans1;
    }

    int deepestLeavesSum(TreeNode* root) {
        int h = height(root);
        
        return solve(root,h);
    }
};