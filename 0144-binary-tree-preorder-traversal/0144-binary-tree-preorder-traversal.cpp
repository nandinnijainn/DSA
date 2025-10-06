class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        
        ans.push_back(root -> val);
        dfs(root -> left, ans);
        dfs(root -> right, ans);
    }
};