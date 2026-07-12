class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int,int>> sorted(n);
        for(int i=0 ; i<n ; i++)
        {
            sorted[i] = {nums[i],i};
        }
        sort(sorted.begin(),sorted.end());
        int right = n - 1;
        int left = 0;
        while(left<right)
        {
            if(sorted[left].first+sorted[right].first==target)
            {
                return {sorted[left].second,sorted[right].second};
            }
            else if (sorted[left].first+sorted[right].first>target)
            {
                right--;
            }
            else{
                left++;
            }
        }
        return {};
    }
};


// this can be solved using maps also -->

class Solution{
    public:
        vector<int> twoSum(vector<int> &nums , int target)
        {
            unordered_maps<int,int> check;
            
            for(int i=0; i<nums.size(); i++)
            {
                int diff = target - nums[i];
                if(check.find(diff) != check.end())
                {
                    return {check[diff],i};
                }
                check[nums[i]] = i;
            }
            return {};
        }
};
