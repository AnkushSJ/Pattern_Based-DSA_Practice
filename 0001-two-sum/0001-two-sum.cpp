class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> check;

        for(int i=0; i<nums.size(); i++)
        {
            int diff = target - nums[i];
            if(check.find(diff) != check.end())
            {
                return {check[diff],i};
            }
            check[nums[i]] = i ;
        }
        return {};
    }
};