class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        dfs(root, ans);
        return ans;
    }

    void dfs(TreeNode* root, vector<int>& ans){
        if(root == nullptr) return;
        
        
        dfs(root -> left, ans);
        dfs(root -> right, ans);
        ans.push_back(root -> val);
    }
};