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

    int getHeight(TreeNode*root){
        if(root == NULL)return 0;

        int left = getHeight(root->left);
        int right = getHeight(root->right);

        return max(left,right)+1;
    }

    bool isBalanced(TreeNode* root) {
        if(root == NULL)return true;
        bool status = false;

        if(abs(getHeight(root->left)-getHeight(root->right)) <= 1)status = true;
        // cout << abs(getHeight(root->left)- getHeight(root->right)) << " ";
        if(root->left == NULL && getHeight(root->right)>1)return false;
        if(root->right == NULL && getHeight(root->left)>1)return false;

        bool ans1 = isBalanced(root->left);
        bool ans2 = isBalanced(root->right);

        return status&&ans1&&ans2;
        // return true;
    }
};