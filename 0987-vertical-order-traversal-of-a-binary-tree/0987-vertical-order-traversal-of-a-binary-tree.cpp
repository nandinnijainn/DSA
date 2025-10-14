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
        queue<pair<TreeNode*,pair<int,int>>> q; 
        map<int,map<int,multiset<int>>>mpp;

        q.push({root,{0,0}});

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            TreeNode* n = node.first;
            auto x = node.second.first;
            auto y = node.second.second;
            mpp[x][y].insert(n->val);

            if(n->left) q.push({n->left,{x-1,y+1}});
            if(n->right) q.push({n->right,{x+1,y+1}});
        }

        vector<vector<int>> ans;

        for(auto node : mpp){
            vector<int> col;
            for(auto x : node.second) col.insert(col.end(),x.second.begin(),x.second.end());
            ans.push_back(col);
        }
    return ans;
    }
};