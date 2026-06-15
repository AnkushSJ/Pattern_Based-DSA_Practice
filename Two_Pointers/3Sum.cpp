// brute force -->
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> st;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                for(int k=j+1; k<nums.size(); k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int> temp = {nums[i],nums[j],nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};


// Optimal Approach -->

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       vector<vector<int>> ans;

       for(int i=0; i<nums.size(); i++)
       {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = nums.size()-1;
            while(j < k)
            {
                int sum = nums[i]+nums[j]+nums[k];

                if(sum==0) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
       }
        return ans;
    }
};

