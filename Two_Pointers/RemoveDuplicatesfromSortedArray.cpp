class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int j=i+1;
        int k=1;
        int n=nums.size()-2;
        while(i<=n)
        {
            if(nums[j]!=nums[i])
            {
                nums[k]=nums[j];
                k++;
            }
            i++;
            j++;
        }
        return k;
    }
};