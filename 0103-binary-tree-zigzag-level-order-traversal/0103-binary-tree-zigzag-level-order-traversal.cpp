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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL){
            return result;
        }

        queue<TreeNode*> n;
        n.push(root);
        bool flag=true;
        
        while(!n.empty()){
            int s=n.size();
            vector<int> row(s);
            for(int i=0;i<s;i++){
                TreeNode* node=n.front();
                n.pop();

                int index=(flag)?i:(s-1-i);

                row[index]=node->val;
                if(node->left){
                    n.push(node->left);
                }
                if(node->right){
                    n.push(node->right);
                }

             
            }
               flag=!flag;
                result.push_back(row);
            
        }
        return result;
    }
};