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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mapp;

        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(!q.empty()){
            auto temp = q.front();
            q.pop();

            TreeNode*node = temp.first;

            int vertical = temp.second.first;
            int level = temp.second.second;

            mapp[vertical][level].insert(node->val);

            if(node->left){
                q.push({node->left,{vertical-1,level+1}});
            }

            if(node->right){
                q.push({node->right,{vertical+1,level+1}});
            }
        }


        for(auto a:mapp){
            vector<int>output;
            for(auto b:a.second){
                // output.insert(output.end(),b.second.begin(),b.second.end());
                multiset<int>sett=b.second;
                for(auto it:sett){
                    output.push_back(it);
                }
            }
            ans.push_back(output);
        }
        return ans;
    }
};