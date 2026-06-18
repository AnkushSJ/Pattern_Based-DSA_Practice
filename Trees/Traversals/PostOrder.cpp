class Solution {
private:
    void level(TreeNode* root , vector<int>& ans)
    {
        if(root==NULL)
            return;
        level(root->left,ans);
        level(root->right,ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        level(root,ans);
        return ans;
    }
};

// iterative method
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
         if(root==NULL)
        {
            return {};
        }
        
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);

            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};