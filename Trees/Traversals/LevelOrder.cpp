class Solution {
private:
    vector<vector<int>> level(TreeNode* root)
    {
        if(root == NULL){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<vector<int>> ans;
        vector<int> arr ;
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp == NULL)
            {
                ans.push_back(arr);
                arr.clear();
                if(!q.empty())
                    q.push(NULL);
            }
            else
            { 
                arr.push_back(temp->val);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        return level(root);
    }
};

// other approach ->

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
            return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int n = q.size();
            vector<int> arr;

            for(int i=0 ; i<n; i++)
            {
                TreeNode* temp = q.front();
                q.pop();
                arr.push_back(temp->val);

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            ans.push_back(arr);
        }
        return ans;
    }
};