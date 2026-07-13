class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size() - 2;

        if (nums.size() == 1)
            return nums[0];
        int n = nums.size();
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 1] != nums[n - 2])
            return nums[n - 1];

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] == nums[mid - 1]) {
                if ((mid - 1) % 2 == 0) {
                    s = mid + 1;
                } else {
                    e = mid - 2;
                }
            } else if (nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    s = mid + 2;
                } else {
                    e = mid - 1;
                }
            } else {
                return nums[mid];
            }
        }
        return -1;
    }
};