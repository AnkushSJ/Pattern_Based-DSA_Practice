class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int ans = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            int curr = nums[i];
            if(curr < 0)
            {
                swap(maxi,mini);
            }
            maxi = max(curr,maxi*curr);
            mini = min(curr,mini*curr);

            ans = max(ans,maxi);
        }
        return ans;
    }
};