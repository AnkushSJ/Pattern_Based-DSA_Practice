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

// iterative approach ->
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(!st.empty() || curr!=NULL)
        {
            while(curr != NULL)
            {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();

            ans.push_back(curr->val);

            curr = curr->right;
        }   
        return ans;
    }
};
