//Inorder Traversal
class Solution {
private:
    void level(TreeNode* root , vector<int>& ans)
    {
         if(root == NULL)
            return;

        level(root->left,ans);
        ans.push_back(root->val);
        level(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        level(root,ans);
        return ans;   
    }
};
