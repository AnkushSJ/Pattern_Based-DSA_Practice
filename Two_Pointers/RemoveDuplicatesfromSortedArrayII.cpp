class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2)
            return nums.size();
        int index = 2;
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] != nums[index - 2]) {
                nums[index] = nums[i];
                index++;
            }
        }
        return index;
    }
};


// for general to remove K Duplicates
int removeDuplicatesAtMostK(std::vector<int>& nums, int k) {
    if (nums.size() <= k) return nums.size();
    int index = k;
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] != nums[index - k]) {
            nums[index++] = nums[i];
        }
    }
    return index;
}
