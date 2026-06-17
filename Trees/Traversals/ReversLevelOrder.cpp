class Solution {
private: 
    vector<vector<int>> level(TreeNode* root)
    {
        if(root == NULL)
        {
            return {};
        }
        stack<TreeNode*> st;
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> arr;
        q.push(root);
        q.push(NULL);
        st.push(NULL);

        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            st.push(temp);
            if(temp == NULL)
            {
                if(!q.empty())
                    q.push(NULL);
            }
            else
            {
                if(temp->right) q.push(temp->right);
                if(temp->left) q.push(temp->left);
            }
        }
        st.pop();
        while(!st.empty())
        {
            if(st.top() == NULL)
            {
                st.pop();
                ans.push_back(arr);
                arr.clear();
            }  
            else
            {
                TreeNode* temp = st.top();
                st.pop();
                arr.push_back(temp->val);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return level(root);
    }
};

// other approach ->
  // use the levelOrder Traversal at last just reverse the ans and return;