// iterative approach
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty())
        {
            while(curr!=NULL)
            {
                ans.push_back(curr->val);
                st.push(curr->right);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();
        }
        return ans;
    }
};

// recuresive
class Solution {
private:
    void level(TreeNode* root , vector<int>& ans)
    {
        if(root==NULL)
            return;
        
        ans.push_back(root->val);
        level(root->left,ans);
        level(root->right,ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        level(root,ans);
        return ans;
    }
};

// iterative 
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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

            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        return ans;
    }
};
