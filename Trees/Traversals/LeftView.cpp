class Solution {
private:
    void solve(TreeNode* root , vector<int> &ans , int level)
    {
        if(root==NULL)
            return;
        
        if(level == ans.size())
            ans.push_back(root->val);

        solve(root->left,ans,level+1);
        solve(root->right,ans,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};